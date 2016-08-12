#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QFileDialog>

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

void MainWindow::on_pushButton_Read_clicked()
{
    // Windows Filters
    // QString filter = "All Files (*,*) ;; Text Files (*.txt) ;; XML Files (*.xml)";
    // QString file_name = QFileDialog::getOpenFileName(this, "Open File", "", filter);

    // Select a file from a file dialog
    QString file_name = QFileDialog::getOpenFileName(this, "Open File", "");

    // Put the selected file into a QFile object instead of manual input
    // QFile file("myfile.txt");
    QFile file(file_name);

    // Open the file as a text read-only file
    if(!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "File not opened.");
    } else {
        // Put our file in a text stream object so we can read it
        // and set our plain text to the result
        QTextStream input(&file);
        QString text = input.readAll();
        ui->plainTextEdit->setPlainText(text);
        file.close();
    }
}

void MainWindow::on_pushButton_Write_clicked()
{
    // Choose a file name in a save filename dialog
    QString file_name = QFileDialog::getSaveFileName(this, "Save File", "");

    // Put the result in a QFile object
    //QFile file("myfile.txt");
    QFile file(file_name);

    // Open file as write-only text file
    if(!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "File not opened.");
    } else {
        // Put file in a textstream object so we can
        // edit it in out text edit
        QTextStream output(&file);
        QString text = ui->plainTextEdit->toPlainText();
        output << text;

        // Flush our created alterations to out file
        file.flush();
        file.close();
    }
}
