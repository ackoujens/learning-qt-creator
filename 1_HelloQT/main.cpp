#include <QApplication>
#include <QLabel>

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    QLabel *label = new QLabel("Hello QT!");
    label->setWindowTitle("First QT Application");
    label->resize(200, 30);
    label->show();
    return app.exec();
}
