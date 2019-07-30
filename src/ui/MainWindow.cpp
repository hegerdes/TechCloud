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


#include "MainWindow.h"
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
    ui->main_frame_search->size().setWidth(this->size().width());
    ui->main_frame_search->size().setHeight(this->size().height());

    //default hide advanced search
    ui->centralWidget->showMaximized();

    QPixmap pixmap_set("res/icon/setting.png");
    QIcon ButtonIcon1(pixmap_set);
    ui->settings_pushButton->setIcon(ButtonIcon1);

    QPixmap pixmap_search("res/icon/a_search.png");
    QIcon ButtonIcon2(pixmap_search);
    ui->advanced_pushButton->setIcon(ButtonIcon2);


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

void tcloud::MainWindow::on_advanced_pushButton_clicked()
{

}

void MainWindow::on_searchButton_clicked()
{
    resultWindow->show();
}
} //tcloud


