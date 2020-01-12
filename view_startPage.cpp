#include "view_startPage.h"
#include "ui_view_startPage.h"

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
    dlgShowTable = new ShowTableDialog(this, M_MATERIAL_CATEGORY_TABLE);
    AuthorityControl(MATERIAL_CATEGORY_COLUMN);
}


/**
 * 打开 "物资种类"--"显示物资种类" 对话框
 *
 */
void MainWindow::on_action_showMaterialDialog_triggered()
{
    dlgShowTable = new ShowTableDialog(this, M_MATERIAL_TABLE);
    AuthorityControl(MATERIAL_COLUMN);
}


/**
 * 打开 "库房信息"--"显示所有库房" 对话框
 *
 */
void MainWindow::on_action_showStorgeRoomDialog_triggered()
{
    dlgShowTable = new ShowTableDialog(this, M_STORAGE_ROOM_TABLE);
    AuthorityControl(STORAGE_ROOM_COLUMN);
}


/**
 * 打开 "库存信息"--"显示所有库存" 对话框
 *
 * @brief MainWindow::on_action_ShowMaterialDialog_triggered
 */
void MainWindow::on_action_showStorgeDialog_triggered()
{
    dlgShowTable = new ShowTableDialog(this, M_STORAGE_TABLE);
    AuthorityControl(STORAGE_COLUMN);
}


/**
 * 打开 "库存信息"--"显示所有库存" 对话框
 *
 */
void MainWindow::on_action_showRoleDialog_triggered()
{
    dlgShowTable = new ShowTableDialog(this, M_ROLE_TABLE);
    AuthorityControl(ROLE_COLUMN);
}


/**
 * 打开 "信息统计"--"显示物资详情" 对话框
 *
 */
void MainWindow::on_action_showMaterialDetailDialog_triggered()
{
    dlgShowTable = new ShowTableDialog(this, M_ROLE_TABLE);
    AuthorityControl(ROLE_COLUMN);
}


/**
 * 打开 "关于"--"关于我们" 对话框
 *
 */
void MainWindow::on_action_aboutDialog_triggered()
{
    dlgAbout = new AboutDialog(this);
}


/**
 * 权限控制
 */
void MainWindow::AuthorityControl(QString neededTable)
{
    switch (UserAuthentication::isAuthorityAllow(neededTable, "Retrieve", 1))
    {
    case G_TRUE:
        //QMessageBox::information(this, QObject::tr("Info"), QObject::tr("Run successfully"), QMessageBox::Yes);
        dlgShowTable->exec();
        break;
    case G_FALSE:
        QMessageBox::information(this, QObject::tr("Info"), QObject::tr("You don't have authority"), QMessageBox::Yes);
        break;
    case G_NOTICE:
        QMessageBox::warning(this, QObject::tr("Info"), QObject::tr("Can't find this RoleID"), QMessageBox::Yes);
        break;
    case G_WARNING:
        QMessageBox::warning(this, tr("Warning"), tr("The data in database isn't 'Y' or 'N',"), QMessageBox::Yes);
        break;
    case G_EXCEPTION:
        QMessageBox::critical(this, tr("Info"), tr("Unknown exception"), QMessageBox::Yes);
        break;
    default:
        QMessageBox::about(this, tr("Unknown"), tr("Unknown return! Please contact administrator : 'BUG-Hunter'"));
        break;
    }
}



