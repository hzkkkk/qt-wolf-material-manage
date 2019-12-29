#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "config_configuration.h"
#include "model_showTableDialog.h"

#include "view_aboutDialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:


    void on_action_showCategoryDialog_triggered();

    void on_action_showMaterialDialog_triggered();

    void on_action_showStorgeRoomDialog_triggered();

    void on_action_showStorgeDialog_triggered();

    void on_action_showRoleDialog_triggered();

    void on_action_showMaterialDetailDialog_triggered();



    void on_action_aboutDialog_triggered();

private:
    Ui::MainWindow *ui;
    AboutDialog* dlgAbout;
    ShowTableDialog* dlgShowTable;

};

#endif // MAINWINDOW_H
