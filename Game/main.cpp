#include "mainwindow.h"

#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

void setupDatabase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    qDebug() << "Database path:" << db.databaseName();
    db.setDatabaseName("highscores.db");

    if (!db.open()) {
        qCritical() << "Failed to open database:" << db.lastError().text();
        return;
    } else {
        qDebug() << "Database connected successfully.";
    }

    QSqlQuery query;
    if (!query.exec("CREATE TABLE IF NOT EXISTS highscores (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, score INTEGER)")) {
        qCritical() << "Failed to create table:" << query.lastError().text();
    } else {
        qDebug() << "Table created or already exists.";
    }
}
void listAvailableDrivers() {
    qDebug() << "Available database drivers:";
    QStringList drivers = QSqlDatabase::drivers();
    for (const QString &driver : drivers) {
        qDebug() << driver;
    }
}
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    listAvailableDrivers(); // Check available drivers
    setupDatabase();
    return a.exec();
}
