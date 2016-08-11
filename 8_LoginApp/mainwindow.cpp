#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "QPixmap"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Put a Qt resource in a QPixmap object
    QPixmap pix (":/img/profile-image.jpg");

    // Place the QPixmap on a label
    ui->profileImage->setPixmap(pix.scaled(ui->profileImage->width(), ui->profileImage->height(), Qt::KeepAspectRatio));

    // Adding status bar widgets
    ui->statusBar->addPermanentWidget(ui->label_serverload, 1);
    ui->statusBar->addPermanentWidget(ui->progressBar_serverload, 1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_login_clicked()
{
    login();
}

// Login sequence
void MainWindow::login(){
    if(isLoginValid()) {
        hide();
        QMessageBox::information(this, "Login", "You've been logged in.");
        secondWindow = new SecondWindow(this);
        secondWindow->show();
    } else {
        // Open a modal box for your message
        // QMessageBox::warning(this, "Login", "Wrong username or password !");

        // Timed statusbar message
        // ui->statusBar->showMessage("Wrong username or password !", 2000);

        // Use same serverload label for other mesages
        ui->label_serverload->setText("Wrong username or password !");
    }
}

// Check if login information was correct
bool MainWindow::isLoginValid() {
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if(username == "test" && password == "test") {
        return true;
    } else {
        return false;
    }
}

// Most users are also used to hitting enter instead of pressing a login button
void MainWindow::on_lineEdit_password_returnPressed()
{
    login();
}

void MainWindow::on_lineEdit_username_returnPressed()
{
    login();
}
