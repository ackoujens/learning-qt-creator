#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "secondwindow.h"

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

void MainWindow::on_pushButton_clicked()
{
    /*
     * Object is destroyed afterwards
     * Main window is not accessable anymore
     * untill you close the second window
     */
    // SecondWindow secondWindow;
    // secondWindow.setModal(true);
    // secondWindow.exec();

    /*
     * Object stays on the heap
     * main window is still accessable
     */
    // secondWindow = new SecondWindow(this);
    // secondWindow->show();

    // Hide the main window
    hide();

    // Create and show the new window
    secondWindow = new SecondWindow(this);
    secondWindow->show();
}
