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

    createMenu();
    ui->dis_textEdit->setHtml("<p>test test test test test test</p><p>|||||||||</p>");
    ui->dis_textEdit->setFixedHeight(100);

}

void ResultWindow::createMenu()
{
    QAction *exitAction = new QAction(tr("Exit"), this);
    QAction *aboutAct = new QAction(tr("About"), this);
    QAction *aboutQtAct = new QAction(tr("About Qt"), this);

    connect(exitAction, &QAction::triggered, qApp, &QApplication::quit);
    connect(aboutQtAct, &QAction::triggered, qApp, &QApplication::aboutQt);

    QMenuBar* menuBar = new QMenuBar();
    QMenu* fileMenu = menuBar->addMenu(tr("File"));
    fileMenu->addAction(exitAction);

    QMenu* helpMenu = menuBar->addMenu(tr("About"));
    helpMenu->addAction(aboutAct);
    helpMenu->addAction(aboutQtAct);

    this->layout()->setMenuBar(menuBar);
}

ResultWindow::~ResultWindow()
{
    delete ui;
}

} //tcloud
