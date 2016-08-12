#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QFontDialog>
#include <QColorDialog>
#include <QColor>
#include <QPrinter>
#include <QPrintDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Remove sidewalls
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Empty file path & clear text
void MainWindow::on_actionNew_triggered()
{
    file_path = "";
    ui->textEdit->setText("");
}

// Open file and fill textEdit with contents
void MainWindow::on_actionOpen_triggered()
{
    QString file_name = QFileDialog::getOpenFileName(this, "Open File", "");
    QFile file(file_name);

    file_path = file_name;

    if(!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "File Open", "File not open");
        return;
    }

    QTextStream input(&file);
    QString text = input.readAll();

    ui->textEdit->setText(text);
    file.close();
}

// Save textEdit contents to currently opened file
void MainWindow::on_actionSave_triggered()
{
    QFile file(file_path);

    if(!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "File Save", "No file is open at the moment, use 'save as' to create a new file.");
        return;
    }

    QTextStream output(&file);
    QString text = ui->textEdit->toPlainText();
    output << text;

    file.flush();
    file.close();
}

// Save textEdit contents to a new file
void MainWindow::on_actionSave_as_triggered()
{
    QString file_path = QFileDialog::getSaveFileName(this, "Save File", "");
    QFile file(file_path);

    if(!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "File Save", "File not saved");
        return;
    }

    QTextStream output(&file);
    QString text = ui->textEdit->toPlainText();
    output << text;

    file.flush();
    file.close();
}

// Call system cut action
void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

// Call system copy action
void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

// Call system paste action
void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

// Call system redo action
void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

// Call system undo action
void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

// Popup an about dialog
void MainWindow::on_actionAbout_Notepad_triggered()
{
    QString about_text;
    about_text =  "Author : Ackou Jens\n";
    about_text += "Date     : 12/12/12\n";
    about_text += "(C) Notepad (R)\n";
    QMessageBox::about(this, "About Notepad", about_text);
}

// Select a font
void MainWindow::on_actionFont_triggered()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, this);
    if(ok) {
        ui->textEdit->setFont(font);
    } else {
        return;
    }
}

// Select font color
void MainWindow::on_actionColor_triggered()
{
    QColor color = QColorDialog::getColor(Qt::black, this, "Choose a color");
    if (color.isValid()){
        ui->textEdit->setTextColor(color);
    }
}

// Select font highlight color
void MainWindow::on_actionBackground_Color_triggered()
{
    QColor backgroundColor = QColorDialog::getColor(Qt::black, this, "Choose a color");
    if (backgroundColor.isValid()){
        ui->textEdit->setTextBackgroundColor(backgroundColor);
    }
}

// Select window background color
void MainWindow::on_actionWindow_Background_triggered()
{
    QColor backgroundColor = QColorDialog::getColor(Qt::black, this, "Choose a color");
    if (backgroundColor.isValid()){
        ui->textEdit->setPalette(QPalette(backgroundColor));
    }
}

// Push textEdit contents to a printer
void MainWindow::on_actionPrint_triggered()
{
    QPrinter printer;
    printer.setPrinterName("Printer");
    QPrintDialog dialog(&printer, this);
    if(dialog.exec() == QDialog::Rejected) {
        return;
    } else {
        ui->textEdit->print(&printer);
    }
}

void MainWindow::on_actionQuit_triggered()
{
    QApplication::quit();
}
