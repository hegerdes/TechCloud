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

#include "src/ui/MainWindow.h"
#include <QApplication>
#include "src/reader/Note.hpp"
#include "ext/json/json.hpp"

using json = nlohmann::json;
using namespace tcloud;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow window;

    tcloud::Note aa = tcloud::Note(2);



    //window.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    window.show();

    return a.exec();
}
