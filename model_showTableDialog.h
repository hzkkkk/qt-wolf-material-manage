#ifndef SHOWMATERIALDIALOG_H
#define SHOWMATERIALDIALOG_H

#include <QDialog>
#include <QtWidgets>
#include <QtSql>
#include "middleware_userAuthentication.h"

namespace Ui {
class ShowTableDialog;
}

class ShowTableDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ShowTableDialog(QWidget *parent = 0,QString table_selected = 0);
    ~ShowTableDialog();


private:
    Ui::ShowTableDialog *ui;

    QString m_table_selected = "no table";

    QSqlRelationalTableModel *model;
    void initUI(Ui::ShowTableDialog *ui);

    QVector<QString> m_fieldName;
    void getTableStructure(QString tableName);
    void customColumnName();
    void customDataWidget(QDataWidgetMapper *mapper);
    void showError(const QSqlError &err);

    void stylizeWidget();


    //middleware
    inline boolean authentication(UserAuthentication neededAuthority, UserAuthentication currentAuthority)
    {
        return (neededAuthority == currentAuthority ) ? TRUE : FALSE;
    }
};

#endif // SHOWMATERIALDIALOG_H
