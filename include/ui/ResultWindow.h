/**
 * @file ResultWindow.h
 * @author Henrik Gerdes (hegerdes@uni-osnabrueck.de)
 * @brief
 * @version 0.1
 * @date 2019-05-30
 *
 * @copyright Copyright (c) 2019
 *
 */


#ifndef RESULTWINDOW_H
#define RESULTWINDOW_H

#include <iostream>
#include <QWidget>
#include <QAction>
#include <QMenu>
#include <QMenuBar>

namespace Ui {
class ResultWindow;
}

namespace tcloud
{
class ResultWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ResultWindow(QWidget *parent = nullptr);
    ~ResultWindow();

private slots:

    void on_save_edit_pushButton_clicked();

private:

    //TitelMenu
    void createMenu();
    //The name of the found result
    std::string m_title;
    //The ui
    Ui::ResultWindow *ui;
    //Edit mode
    bool m_edit;
    //Is favorite
    bool m_fav;
};

} //tcloud

#endif // RESULTWINDOW_H
