#ifndef MODEL_M_MATERIALDB_H
#define MODEL_M_MATERIALDB_H

#include <QtSql>

class model_Material
{
public:
    model_Material();

    //将查询结果保存到表格显示出来
    void criteriaQuery();

    static QStringList s_databaseName;
};

#endif // MODEL_M_MATERIALDB_H
