/**
 * @file ResultWindow.cpp
 * @author Henrik Gerdes (hegerdes@uni-osnabrueck.de)
 * @brief
 * @version 0.1
 * @date 2019-05-30
 *
 * @copyright Copyright (c) 2019
 *
 */


#include "ResultWindow.h"
#include "ui_ResultWindow.h"

namespace tcloud
{
ResultWindow::ResultWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ResultWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Results: ");

}

ResultWindow::~ResultWindow()
{
    delete ui;
}

} //tcloud
