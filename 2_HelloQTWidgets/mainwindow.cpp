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

// Executes action when button is pressed down
void MainWindow::on_pushButton_Quit_pressed()
{
    ui->labelMessage->setText("Hold on please !");
}
