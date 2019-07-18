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

private:

    //TitelMenu
    void createMenu();
    //The name of the found result
    std::string m_title;
    Ui::ResultWindow *ui;
};

} //tcloud

#endif // RESULTWINDOW_H
