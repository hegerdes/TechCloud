#include "ResultWindow.h"
#include "ui_ResultWindow.h"

ResultWindow::ResultWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ResultWindow)
{
    ui->setupUi(this);
    ui->toolBox->close();
    ui->frame->close();

}

ResultWindow::~ResultWindow()
{
    delete ui;
}

void ResultWindow::on_pushButton_clicked()
{
    ui->toolBox->show();
    ui->frame->show();
}
