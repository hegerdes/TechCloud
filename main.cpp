/**
 * @file main.cpp
 * @author Henrik Gerdes (hegerdes@uni-osnabrueck.de)
 * @brief
 * @version 0.1
 * @date 2019-05-30
 *
 * @copyright Copyright (c) 2019
 *
 */

#include <QApplication>
#include <nlohmann/json.hpp>
#include "include/ui/MainWindow.h"
#include "Note.hpp"
#include "Note_preference.hpp"
#include "NoteFactory.hpp"
#include "BuildNote.hpp"

using json = nlohmann::json;
using namespace tcloud;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow window;



    //window.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    //window.show();

    //return a.exec();
}
