#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "QDebug"

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
    // All examples of message boxes
    QMessageBox::warning(this, "Warning", "This is a warning message.");
    QMessageBox::question(this, "Question", "Are you really sure ?");
    QMessageBox::information(this, "Info", "Some additional information.");
    QMessageBox::critical(this, "Critical", "You did something wrong on a critical level !");
    QMessageBox::aboutQt(this, "About QT");
    QMessageBox::about(this, "About", "Application about information here.");

    // Ask a legit question to the user
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Are you sure ?", "Do you want to quit this application ?",
                                                              QMessageBox::Yes | QMessageBox::No);
    // Stream supplied information to QDebug
    if (reply == QMessageBox::Yes ) {
        qDebug() << "QDebug: The user chose to quit the application !";
        QApplication::quit();
    } else {
        qDebug() << "QDebug: The user wants to continue the application.";
    }
}
