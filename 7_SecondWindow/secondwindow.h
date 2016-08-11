#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>

namespace Ui {
class SecondWindow;
}

class SecondWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = 0);
    ~SecondWindow();

private slots:
    // Second window is on it's way out
    void on_SecondWindow_finished();

private:
    // Main window
    QWidget *m_parent;

    // Second window
    Ui::SecondWindow *ui;
};

#endif // SECONDWINDOW_H
