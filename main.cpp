#include <QApplication>
#include <QDialog>
#include <QtWidgets>

#include "model_accessDatabase.h"
#include "view_startPage.h"

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(material);

    //设置QString默认采用的编码。而究竟采用哪一个，
    //一般来说就是源代码是GBK，就用GBK，源代码是UTF-8就用UTF-8。
    //但有一个例外，如果你保存成了带BOM的UTF-8而且用的微软的cl编译器，此时仍是GBK

//    //对于外部字符串编码解码全部采用本地编码
//    QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));


    // initialize the database
    QSqlError err = model_Database::initDatabase();
    if (err.type() != QSqlError::NoError) {
        QMessageBox::critical(NULL,"Unable to initialize Database",
                    "Error initializing database: " + err.text());
    }

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
