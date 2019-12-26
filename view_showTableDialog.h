#ifndef SHOWMATERIALDIALOG_H
#define SHOWMATERIALDIALOG_H

#include <QDialog>
#include <QtWidgets>
#include <QtSql>

namespace Ui {
class ShowTableDialog;
}

class ShowTableDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ShowTableDialog(QWidget *parent = 0,uint16_t table_selected = 0);
    ~ShowTableDialog();

private:
    Ui::ShowTableDialog *ui;

    uint16_t m_table_selected = 0;

    QSqlRelationalTableModel *model;
    void initUI(Ui::ShowTableDialog *ui);

    QVector<QString> m_fieldName;
    void getTableStructure(QString tableName);
    void customColumnName();
    void customDataWidget(QDataWidgetMapper *mapper);
    void showError(const QSqlError &err);
};

#endif // SHOWMATERIALDIALOG_H
