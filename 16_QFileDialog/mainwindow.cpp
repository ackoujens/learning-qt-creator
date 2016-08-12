#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDir>

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
    // Select a file and display it's file name
    //QString file_name = QFileDialog::getOpenFileName(this, "Open File", "");
    QString file_name = QFileDialog::getOpenFileName(this, "Open File", QDir::homePath());
    QMessageBox::information(this, "Open File", "File name: " + file_name);
}
