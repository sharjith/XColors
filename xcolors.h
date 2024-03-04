#ifndef XCOLORS_H
#define XCOLORS_H

#include <QWidget>

namespace Ui {
class XColors;
}

class XColors : public QWidget
{
    Q_OBJECT

public:
    explicit XColors(QWidget *parent = 0);
    ~XColors();

private slots:
    void on_listWidget_currentRowChanged(int currentRow);

    void on_pushButton_clicked();

private:
    Ui::XColors *ui;
};

#endif // XCOLORS_H
