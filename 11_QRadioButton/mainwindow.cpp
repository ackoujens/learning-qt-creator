#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

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
    if(ui->radioButton->isChecked()) {
        QMessageBox::information(this, "Name", "You chose Mark");
    }
    if(ui->radioButton_2->isChecked()) {
        QMessageBox::information(this, "Name", "You chose John");
    }

    if(ui->radioButton_3->isChecked()) {
        QMessageBox::information(this, "Name", "Meow");
    }
    if(ui->radioButton_4->isChecked()) {
        QMessageBox::information(this, "Name", "Woof");
    }
}
