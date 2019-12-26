#include "view_showTableDialog.h"
#include "Configuration.h"
#include "controller_showTableDelegate.h"
#include "ui_MaterialDialog.h"

#include "model_Table.h"
#include <QtSql>

ShowTableDialog::ShowTableDialog(QWidget *parent, uint16_t table_selected) :
    QDialog(parent),
    ui(new Ui::ShowTableDialog)
{
    ui->setupUi(this);
    m_table_selected = table_selected;
    initUI(ui);
}


ShowTableDialog::~ShowTableDialog()
{
    delete ui;
}


void ShowTableDialog::initUI(Ui::ShowTableDialog *ui)
{
    // The upper part of the UI
    // Create the data model
    model = new QSqlRelationalTableModel(ui->DataTable);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    if(m_table_selected == 6)
        // rename ColumnName for different Structure
        customColumnName();
    else
    {
       QString databaseSelected = model_Material::s_databaseName.at(m_table_selected);
       getTableStructure(databaseSelected);
       // Set the localized header captions  for model
       model->setTable(databaseSelected);
    }

    // Populate the model
    if (!model->select()) {
        showError(model->lastError());
        return;
    }
    // Set the model
    ui->DataTable->setModel(model);
    ui->DataTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ////////////////委托声明
    ui->DataTable->setItemDelegate(new MaterialDelegate(ui->DataTable));
    ////////////////委托声明
    // Hide the ID column
    //ui->MaterialTable->setColumnHidden(model->fieldIndex("id"), true);
    // Set SingleSelect
    ui->DataTable->setSelectionMode(QAbstractItemView::SingleSelection);

    // The lower part of the UI
    QDataWidgetMapper *mapper = new QDataWidgetMapper(this);
    mapper->setModel(model);

    ////////////////委托声明
    mapper->setItemDelegate(new MaterialDelegate(this));
    ////////////////委托声明

    connect(ui->DataTable->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
            mapper, SLOT(setCurrentModelIndex(QModelIndex)));

    ui->DataTable->setCurrentIndex(model->index(0, 0));
}


void ShowTableDialog::getTableStructure(QString tableName)
{
    QSqlQuery query;
    QString strTableNmae = tableName;
    QString str = "PRAGMA table_info(" + strTableNmae + ")";

    qDebug() << QString(QString::fromLocal8Bit("Running getTableStructure"));

    query.prepare(str);
    if (query.exec())
    {
        while (query.next())
        {//QLatin1String
            qDebug() << QString(QLatin1String(("Field Count : %1    "
                                               " Field Name : %2    "
                                               " Field Type : %3")))
                        .arg(query.value(0).toString())
                        .arg(query.value(1).toString())
                        .arg(query.value(2).toString());
            //save the Field Names for self-adaptation
            this->m_fieldName.push_back(query.value(1).toString());
        }
    }
    else
    {
        qDebug() << query.lastError();
        return;
    }
    return;
}


void ShowTableDialog::customColumnName()
{
    // Remember the indexes of the columns
//    authorIdx = model->fieldIndex("author");
//    genreIdx = model->fieldIndex("genre");

//    // Set the relations to the other database tables
//    model->setRelation(authorIdx, QSqlRelation("authors", "id", "name"));
//    model->setRelation(genreIdx, QSqlRelation("genres", "id", "name"));


    // Set the localized header captions  for model
    model->setHeaderData(model->fieldIndex("MaterialID"), Qt::Horizontal, tr("物资id"));
    model->setHeaderData(model->fieldIndex("MaterialName"), Qt::Horizontal, tr("物资名称"));
    model->setHeaderData(model->fieldIndex("CategoryID"), Qt::Horizontal, tr("物资种类id"));
    model->setHeaderData(model->fieldIndex("MaterialNote"), Qt::Horizontal, tr("物资备注"));
    model->setHeaderData(model->fieldIndex("MaterialState"), Qt::Horizontal, tr("物资状态"));


}


void ShowTableDialog::customDataWidget(QDataWidgetMapper *mapper)
{
    for(uint16_t i = 0;i < this->m_fieldName.size();i++)
    {
        QLineEdit* lineEdit = findChild<QLineEdit*>("No"+ QString::number(i + 1) + "Edit");
        QLabel* label = findChild<QLabel*>("No"+ QString::number(i + 1) + "Label");
        if(lineEdit != NULL)
        {
            mapper->addMapping(lineEdit, model->fieldIndex(m_fieldName.at(i)));
            label->setText(m_fieldName.at(i));
        }
    }
}


void ShowTableDialog::showError(const QSqlError &err)
{
    QMessageBox::critical(this, "Unable to initialize Database",
                          "Error initializing database: " + err.text());
}

