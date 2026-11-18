#include "databasemanager.h"

DatabaseManager &DatabaseManager::instance()
{
    static DatabaseManager dbm;
    return dbm;
}

DatabaseManager::DatabaseManager()
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setHostName("UniversityScheduler");
    m_db.setDatabaseName("schedules.sdb");
    if (!m_db.open()) {
        qCritical() << "Can't open DB";
    }
    QSqlQuery query;
    QString createTableQuery =
        "";
    if (!query.exec(createTableQuery)) {
        qCritical() << "Failed to create table:" << query.lastError().text();
    }
}

