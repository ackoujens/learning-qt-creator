#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Add item, also with icon
    ui->comboBox->addItem("Release");
    ui->comboBox->addItem(QIcon(":/icon/coffee-cup-with-steam.png"), "Debug");

    // Filling combobox using for loop
    for(int i=0; i < 10; i++) {
        ui->comboBox->addItem("Item" + QString::number(i));
    }

    // Insert item at index
    ui->comboBox->insertItem(10, "inserted item");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    // Print selected item text
    QMessageBox::information(this, "Selected Item", ui->comboBox->currentText());
}
