#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Check the checkbox on default
    // ui->checkBox->setChecked(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
   // Check the state of the checkbox
   if( ui->checkBox->isChecked()) {
       QMessageBox::information(this, "Breakfast", "A plate of bacon is on it's way.");
   } else {
       QMessageBox::information(this, "Breakfast", "No bacon for you !");
   }
}

void MainWindow::on_checkBox_stateChanged(int arg1)
{
    // Display message when checkbox is clicked
    if(arg1) {
        QMessageBox::information(this, "Breakfast", "Interaction with checkbox.");
    }
}
