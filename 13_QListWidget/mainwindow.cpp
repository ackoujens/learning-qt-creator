#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Add items to listWidget
    QListWidgetItem *item1 = new QListWidgetItem(QIcon(":/img/award-badge-2.png"), "Gold Medal");
    ui->listWidget->addItem(item1);

    QListWidgetItem *item2 = new QListWidgetItem(QIcon(":/img/award-badge.png"), "Silver Medal");
    ui->listWidget->addItem(item2);

    QListWidgetItem *item3 = new QListWidgetItem(QIcon(":/img/award-badge-2.png"), "Bronze Medal");
    ui->listWidget->addItem(item3);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    // Show selected item
    QMessageBox::information(this, "You selected ...", ui->listWidget->currentItem()->text());
    ui->listWidget->currentItem()->setBackground(Qt::red);
    ui->listWidget->currentItem()->setForeground(Qt::blue);
}
