#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "form.h"

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

void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    ui->tabWidget->removeTab(index);
}

void MainWindow::on_pushButton_add_clicked()
{
    // Add empty tab
    // ui->tabWidget->addTab(new QWidget(), "New Tab");

    // Add empty numbered tab
    // ui->tabWidget->addTab(new QWidget(), QString("Tab %0").arg(ui->tabWidget->count()+1));

    // Add new numbered tab based on form.ui
    ui->tabWidget->addTab(new Form(), QString("Tab %0").arg(ui->tabWidget->count()+1));
    ui->tabWidget->setCurrentIndex(ui->tabWidget->count()-1);
}
