#ifndef MODEL_INITDATABASE_H
#define MODEL_INITDATABASE_H

#include <QtSql>
#include <QtWidgets>

class model_Database
{
public:
    model_Database();
    static QSqlError initDatabase();
    static QSqlDatabase s_db;
};

#endif // MODEL_INITDATABASE_H
