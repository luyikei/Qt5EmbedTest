#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QProcess>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

protected:
    void closeEvent(QCloseEvent *) Q_DECL_OVERRIDE;

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;

    QProcess *process;
};

#endif // WIDGET_H
