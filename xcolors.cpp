#include "xcolors.h"
#include "ui_xcolors.h"

#include "rgb.h"

#include <QString>
#include <QColor>
#include <QBrush>
#include <QMessageBox>

XColors::XColors(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::XColors)
{
    ui->setupUi(this);

    int i;
    for(i = 0; i < 146; i++)
    {
        ui->listWidget->addItem(QString(xcolors[i]));
    }

    ui->listWidget->setCurrentRow(0);
}

XColors::~XColors()
{
    delete ui;
}

void XColors::on_listWidget_currentRowChanged(int currentRow)
{
    QColor c(ui->listWidget->item(currentRow)->text());

    QVariant variant= c;
    QString colcode = variant.toString();
    ui->colorlabel->setStyleSheet("QLabel { background-color :"+colcode+"; }");

    //ui->colorlabel->setPalette(QPalette(c));

    QString rgb;
    rgb.sprintf("  R %d  G %d  B %d", c.red(), c.green(), c.blue());
    //QString msg;
    //msg.sprintf("Item No %d", index);
    //QMessageBox::warning(this, tr("My Application"), msg, QMessageBox::Ok);
    setWindowTitle("XColors...  " + ui->listWidget->item(currentRow)->text() + rgb);
    ui->lcdNumber1->display(c.red());
    ui->lcdNumber2->display(c.green());
    ui->lcdNumber3->display(c.blue());
}

void XColors::on_pushButton_clicked()
{
    qApp->quit();
}
