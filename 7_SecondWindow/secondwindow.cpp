#include "secondwindow.h"
#include "ui_secondwindow.h"

SecondWindow::SecondWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecondWindow)
{
    // Storing the parent pointer. I refer to it later when
    // the parent window needs to be shown again
    m_parent = parent;
    ui->setupUi(this);
}

SecondWindow::~SecondWindow()
{
    // Cleanup is very important when using pointers
    delete m_parent;
    delete ui;
}

void SecondWindow::on_SecondWindow_finished()
{
    // Show the parent window again when this one is closed
    m_parent->show();
}
