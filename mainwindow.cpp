#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


/**
 * 打开 "物资分类"--"显示物资分类" 对话框
 *
 */
void MainWindow::on_action_showCategoryDialog_triggered()
{
    dlgShowTable = new ShowTableDialog(this,1);
    dlgShowTable->exec();
}


/**
 * 打开 "物资种类"--"显示物资种类" 对话框
 *
 */
void MainWindow::on_action_showMaterialDialog_triggered()
{
    dlgShowTable = new ShowTableDialog(this,2);
    dlgShowTable->exec();
}


/**
 * 打开 "库房信息"--"显示所有库房" 对话框
 *
 */
void MainWindow::on_action_showStorgeRoomDialog_triggered()
{
    dlgShowTable = new ShowTableDialog(this,3);
    dlgShowTable->exec();
}


/**
 * 打开 "库存信息"--"显示所有库存" 对话框
 *
 * @brief MainWindow::on_action_ShowMaterialDialog_triggered
 */
void MainWindow::on_action_showStorgeDialog_triggered()
{
    dlgShowTable = new ShowTableDialog(this,4);
    dlgShowTable->exec();
}


/**
 * 打开 "库存信息"--"显示所有库存" 对话框
 *
 */
void MainWindow::on_action_showRoleDialog_triggered()
{
    dlgShowTable = new ShowTableDialog(this,5);
    dlgShowTable->exec();
}

/**
 * 打开 "信息统计"--"显示物资详情" 对话框
 *
 */
void MainWindow::on_action_showMaterialDetailDialog_triggered()
{
    dlgShowTable = new ShowTableDialog(this,6);
    dlgShowTable->exec();
}




/**
 * 打开 "关于"--"关于我们" 对话框
 *
 */
void MainWindow::on_action_aboutDialog_triggered()
{
    dlgAbout = new AboutDialog(this);
    dlgAbout->exec();
}

