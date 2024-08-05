#ifndef DATABASECONNECT_H
#define DATABASECONNECT_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>

class DatabaseConnect
{
public:
    DatabaseConnect();
    static DatabaseConnect& instance();
    QSqlDatabase& database();

private:
    QSqlDatabase db;
};

#endif // DATABASECONNECT_H
