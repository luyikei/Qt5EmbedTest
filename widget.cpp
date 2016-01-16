#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    WId winid = winId();

    process = new QProcess(this);
    QStringList arguments;
    arguments << "-into";
    arguments << QString::number(winid);
    process->start("xterm", arguments);

}

Widget::~Widget()
{
    delete process;
    delete ui;
}

void Widget::closeEvent(QCloseEvent *){
    process->terminate();
    process->waitForFinished();
}
