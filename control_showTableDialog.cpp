#include <QtSql>

#include "control_showTableDialog.h"
#include "config_configuration.h"
#include "control_materialDelegate.h"
#include "ui_control_showTableDialog.h"

ShowTableDialog::ShowTableDialog(QWidget *parent, QString table_selected) :
    QDialog(parent),
    ui(new Ui::ShowTableDialog)
{
    ui->setupUi(this);
    m_table_selected = table_selected;
    initUI();
    stylizeWidget();
}


ShowTableDialog::~ShowTableDialog()
{
    delete ui;
}


//初始化数据模型
void ShowTableDialog::initUI()
{
    // The upper part of the UI
    // Create the data model
    model = new QSqlRelationalTableModel(ui->DataTable);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    if(m_table_selected == "no table")
    {
        // rename ColumnName for different Structure
        qDebug() << QString(QString::fromLocal8Bit("Error, no init table"));
        customColumnName();
    }
    else
    {
        QString databaseSelected = m_table_selected;
        getTableStructure(databaseSelected);
        // Set the localized header captions  for model
        model->setTable(databaseSelected);
    }

    // Populate the model
    if (!model->select()) {
        showError(model->lastError(),
                  QString("Unable to initialize Database."
                          "Error initializing database:"));
        return;
    }
    // Set the model
    ui->DataTable->setModel(model);

    //TODO: add AuthorityControl System
    //isAuthorityAllow(currentRole);

    if(0)           //isAuthorityAllow(currentRole)
    {
        ui->DataTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    }
    else
    {
        ui->DataTable->setEditTriggers(QAbstractItemView::DoubleClicked);
    }

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


    customDataWidget(mapper);

    ////////////////委托声明
    mapper->setItemDelegate(new MaterialDelegate(this));
    ////////////////委托声明

    connect(ui->DataTable->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
            mapper, SLOT(setCurrentModelIndex(QModelIndex)));

    ui->DataTable->setCurrentIndex(model->index(0, 0));
}

//获取数据库结构
void ShowTableDialog::getTableStructure(QString tableName)
{
    QSqlQuery query;
    QString strTableName = tableName;
    QString sql;

    if(DATABASEDRIVER == "QSQLITE")
        sql = "PRAGMA table_info(" + strTableName + ")";
    else if(DATABASEDRIVER == "QMYSQL")
        sql = "select ORDINAL_POSITION, COLUMN_NAME, DATA_TYPE from information_schema.COLUMNS where table_name =  '" + strTableName + "'";

    qDebug() << sql;
    qDebug() << QString(QString::fromLocal8Bit("Running getTableStructure"));

    query.prepare(sql);

    if (query.exec())
    {
        while (query.next())
        {// QLatin1String
            qDebug() << QString(QLatin1String(("Field Count : %1    "
                                               " Field Name : %2    "
                                               " Field Type : %3")))
                        .arg(query.value(0).toString())
                        .arg(query.value(1).toString())
                        .arg(query.value(2).toString());
            // Save the Field Names for self-adaptation
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

//格式化按钮控件
void ShowTableDialog::stylizeWidget()
{
    qDebug() << "searching QPushButton";
    QList<QPushButton*> Btns = findChildren<QPushButton *>();
    foreach (QPushButton * btn, Btns)
    {
        qDebug() << "setting QPushButton";
        btn->setStyleSheet("QPushButton { border-radius: 4px; border:none; border-style: outset; }"
                           "QPushButton:enabled { background: #5BACEB; color: white;}"
                           "QPushButton:!enabled { background: #5BACEB; color: rgb(200, 200, 200);}"
                           "QPushButton:hover { background: #7DBDF0;}"
                           "QPushButton:pressed { background: #5C8BB0; border-style: inset;}");
    }
}

//为自定义查询定制列名
void ShowTableDialog::customColumnName()
{
    // Remember the indexes of the columns
    //    authorIdx = model->fieldIndex("author");
    //    genreIdx = model->fieldIndex("genre");

    //    // Set the relations to the other dat`abase tables
    //    model->setRelation(authorIdx, QSqlRelation("authors", "id", "name"));
    //    model->setRelation(genreIdx, QSqlRelation("genres", "id", "name"));


    // Set the localized header captions  for model
    model->setHeaderData(model->fieldIndex("MaterialID"), Qt::Horizontal, tr("物资id"));
    model->setHeaderData(model->fieldIndex("MaterialName"), Qt::Horizontal, tr("物资名称"));
    model->setHeaderData(model->fieldIndex("CategoryID"), Qt::Horizontal, tr("物资种类id"));
    model->setHeaderData(model->fieldIndex("MaterialNote"), Qt::Horizontal, tr("物资备注"));
    model->setHeaderData(model->fieldIndex("MaterialState"), Qt::Horizontal, tr("物资状态"));
}

//根据数据库属性个数, 自适应命名编辑框
void ShowTableDialog::customDataWidget(QDataWidgetMapper *mapper)
{
    QGridLayout* gridLayout = ui->gridLayout; //根据子控件的名称查找子控件

    for(uint16_t i = 0;i < this->m_fieldName.size();i++)
    {
        QLineEdit* lineEdit = new QLineEdit("this");
        gridLayout->addWidget(lineEdit);//把Button放入Layout中
    }


//    for(uint16_t i = 0;i < this->m_fieldName.size();i++)
//    {
//        QLineEdit* lineEdit = findChild<QLineEdit*>("No"+ QString::number(i + 1) + "Edit");
//        QLabel* label = findChild<QLabel*>("No"+ QString::number(i + 1) + "Label");
//        if(lineEdit != NULL)
//        {
//            mapper->addMapping(lineEdit, model->fieldIndex(m_fieldName.at(i)));
//            label->setText(m_fieldName.at(i));
//        }
//    }
}

// 出现error 显示 critical 信息
void ShowTableDialog::showError(const QSqlError &err, const QString errText)
{
    QMessageBox::critical(this, "Error", errText + err.text());
}


void ShowTableDialog::on_CommitButton_clicked()
{
    model->database().transaction(); //开始事务操作
    if (model->submitAll()) {
        model->database().commit(); //提交
        QMessageBox::information(this, tr("tableModel"), "提交成功");
    } else {
        model->database().rollback(); //回滚
        QMessageBox::warning(this, tr("tableModel"),
                             tr("数据回滚.数据库错误: %1")
                             .arg(model->lastError().text()));
    }
}
