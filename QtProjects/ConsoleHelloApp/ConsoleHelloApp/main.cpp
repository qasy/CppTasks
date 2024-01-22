#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget *widget = new QWidget();

    widget->setWindowTitle("Hello from Qt!");
    widget->setMinimumHeight(300);
    widget->setMinimumWidth(400);

    QPushButton *btn1 = new QPushButton("Button1");
    QPushButton *btn2 = new QPushButton("Button2");
    QPushButton *btn3 = new QPushButton("Button3");
    QPushButton *btn4 = new QPushButton("Button4");

    QVBoxLayout *layout = new QVBoxLayout(widget);

    layout->addWidget(btn1);
    layout->addWidget(btn2);
    layout->addWidget(btn3);
    layout->addWidget(btn4);

    widget->show();

    return app.exec();
}
