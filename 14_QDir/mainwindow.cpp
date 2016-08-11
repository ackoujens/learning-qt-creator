#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Initialize QDir with desired path or no path & check directory
    // QDir dir("C:/random_dir");
    QDir dir;
    if(dir.exists()) {
        QMessageBox::information(this, "Directory check", "This directory exists");
    } else {
        QMessageBox::information(this, "Directory check", "This directory does not exist!");
    }

    // List all drives
    foreach(QFileInfo var , dir.drives() ) {
        ui->comboBox->addItem(var.absoluteFilePath());
    }

    // List all files & directories
    QDir dir_2;
    foreach(QFileInfo var , dir_2.entryInfoList() ) {
        if(var.isDir())
            ui->listWidget->addItem("Dir: " + var.absoluteFilePath());
        if(var.isFile())
            ui->listWidget->addItem("File: " + var.absoluteFilePath());

    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    // Check if directory exists / create directory
    QDir dir_2("directory");
    if(dir_2.exists()) {
        QMessageBox::information(this, "Directory check", "This directory exists");
    } else {
        QMessageBox::information(this, "Directory check", "Directory does not exist, creating directory ...");
        dir_2.mkpath("directory");
    }
}
