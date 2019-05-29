/**
 * @file MainWindow.h
 * @author Henrik Gerdes (hegerdes@uni-osnabrueck.de)
 * @brief
 * @version 0.1
 * @date 2019-05-30
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCompleter>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QFileDialog>
#include "ResultWindow.h"

namespace Ui {
class MainWindow;
}

namespace tcloud{

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_useAdvanced_check_stateChanged(int arg1);

    void on_searchButton_clicked();

private:
    Ui::MainWindow *ui;
    ResultWindow *resultWindow;
};

}//tcloud
#endif // MAINWINDOW_H