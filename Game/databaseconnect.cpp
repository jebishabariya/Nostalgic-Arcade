#include "databaseconnect.h"

DatabaseConnect::DatabaseConnect() {}
DatabaseConnect& DatabaseConnect::instance() {
    static DatabaseConnect instance;
    return instance;
}

QSqlDatabase& DatabaseConnect::database() {
    if (!db.isOpen()) {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("snakehighscores.db");

        if (!db.open()) {
            qCritical() << "Failed to connect to database:" << db.lastError().text();
            } else {
            qDebug() << "Database opened successfully.";
        }
    }
    return db;
}
