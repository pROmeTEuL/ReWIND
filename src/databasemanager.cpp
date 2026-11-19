#include "databasemanager.h"

DatabaseManager &DatabaseManager::instance()
{
    static DatabaseManager dbm;
    return dbm;
}

bool DatabaseManager::good()
{
    return m_good;
}

bool DatabaseManager::bad()
{
    return !m_good;
}

DatabaseManager::DatabaseManager()
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setHostName("UniversityScheduler");
    m_db.setDatabaseName("schedules.sdb");
    if (!m_db.open()) {
        qCritical() << "Can't open DB";
        m_good = false;
        return;
    }
    QSqlQuery query;
    QString createTableQuery =
R"rawliteral(CREATE TABLE IF NOT EXISTS schedules (
    id   INTEGER PRIMARY KEY,
    name TEXT NOT NULL
);

CREATE TABLE IF NOT EXISTS classes (
    id          INTEGER PRIMARY KEY,
    schedule_id INTEGER NOT NULL,
    day_of_week INTEGER NOT NULL CHECK (day_of_week BETWEEN 1 AND 7),
    name        TEXT NOT NULL,
    location    TEXT,
    start_time  TEXT NOT NULL,
    end_time    TEXT NOT NULL,

    FOREIGN KEY (schedule_id) REFERENCES schedules(id) ON DELETE CASCADE,
    CHECK (start_time < end_time)
);

CREATE INDEX IF NOT EXISTS idx_classes_schedule_day
    ON classes(schedule_id, day_of_week, start_time);
)rawliteral";
    if (!query.exec(createTableQuery)) {
        qCritical() << "Failed to create table:" << query.lastError().text();
        m_good = false;
        return;
    }
    m_good = true;
}

