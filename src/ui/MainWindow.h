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

#endif // MAINWINDOW_H
