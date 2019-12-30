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


private slots:
    void on_CommitButton_clicked();

private:
    Ui::ShowTableDialog *ui;

    QString m_table_selected = "no table";
    QSqlRelationalTableModel *model;

    UserAuthentication needAuthentication;
    void initUI();

    QVector<QString> m_fieldName;
    void getTableStructure(QString tableName);

    void stylizeWidget();

    void customColumnName();

    void customDataWidget(QDataWidgetMapper *mapper);

    void showError(const QSqlError &err, const QString errText);
};


#endif // SHOWMATERIALDIALOG_H
