#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class DatabaseManager
{
public:
    static DatabaseManager &instance();
    bool good();
    bool bad();
/// TODO: add methods to execute queries and manage the database connection

private:
    DatabaseManager();

private:
    QSqlDatabase m_db;
    bool m_good;
};

#endif // DATABASEMANAGER_H
