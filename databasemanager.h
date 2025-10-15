#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class DatabaseManager
{
public:
    static DatabaseManager &instance();
private:
    DatabaseManager();
private:
    QSqlDatabase m_db;
};

#endif // DATABASEMANAGER_H
