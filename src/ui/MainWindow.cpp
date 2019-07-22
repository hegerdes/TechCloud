/**
 * @file MainWindow.cpp
 * @author Henrik Gerdes (hegerdes@uni-osnabrueck.de)
 * @brief
 * @version 0.1
 * @date 2019-05-30
 *
 * @copyright Copyright (c) 2019
 *
 */


#include "include/ui/MainWindow.h"
#include "ui_MainWindow.h"

namespace tcloud
{
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("TechCloud");

    //Init other windows
    resultWindow = new ResultWindow();

    //Set mainFrame size with mainWwindow size
    ui->main_frame->size().setWidth(this->size().width());
    ui->main_frame->size().setHeight(this->size().height());

    //default hide advanced search
    ui->centralWidget->showMaximized();


    //Completer
    QStringList wordList;
    wordList << "alpha" << "omega" << "omicron" << "zeta";
    ui->lineEdit->setCompleter(new QCompleter(wordList, this));

    //QPixmap image = QPixmap("1.jpg");
    //QGraphicsPixmapItem* item = new QGraphicsPixmapItem();
    //item->setPixmap(image);
    //scene->addItem(item);
    //ui->Ui_MainWindow::graphicsView->setScene(scene);

    //on_searchButton_clicked();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete resultWindow;
}



//void MainWindow::on_useAdvanced_check_stateChanged(int arg1)
//{
//    if(arg1 == Qt::Unchecked)
//    {
//        ui->advanced_frame->hide();
//    }else ui->advanced_frame->show();

//}


void MainWindow::on_searchButton_clicked()
{
    resultWindow->show();
}
} //tcloud
