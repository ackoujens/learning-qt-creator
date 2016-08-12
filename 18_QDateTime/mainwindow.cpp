#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Setup timer to trigger each second
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(myFunction()));
    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::myFunction()
{
    // Get current time each second
    QTime time = QTime::currentTime();
    QString time_text = time.toString("hh : mm : ss");

    // If seconds are dividable by 2
    // remove the seperator
    if((time.second() % 2) == 0) {
        time_text[3] = ' ';
        time_text[8] = ' ';
    }

    // Display text on label
    ui->label_time->setText(time_text);
}
