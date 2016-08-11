#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <secondwindow.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_login_clicked();

    void on_lineEdit_password_returnPressed();

    void on_lineEdit_username_returnPressed();

private:
    Ui::MainWindow *ui;
    SecondWindow *secondWindow;
    bool isLoginValid();
    void login();
};

#endif // MAINWINDOW_H
