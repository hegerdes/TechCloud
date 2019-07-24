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
const double version = 0.1;

#include <QApplication>
#include <boost/program_options.hpp>
#include <nlohmann/json.hpp>
#include "Note_preference.hpp"
#include "NoteFactory.hpp"
#include "BuildNote.hpp"
#include "MainWindow.h"
#include "Note.hpp"

using json = nlohmann::json;
using namespace tcloud;
namespace po = boost::program_options;

int main(int argc, char *argv[])
{
    BuildNote& bn = BuildNote::getInstance();
    NoteFactory& nf = NoteFactory::getInstance();

    po::options_description desc("Allowed options");

    desc.add_options()
    ("help,h", "produce help message")
    ("add,a", "add a new note")
    ("search,s", "search for a note")
    ("edit,e", po::value<int>()->default_value(0) , "edit note")
    ("version,v", "list the programm version")
    ("list,l", "list number and title of all notes")
    ("grafic,g", "start grafical interface");

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    if (vm.count("help")) {
        std::cout << desc << "\n";
        return 1;
    }

    if (vm.count("version")) {
        std::cout << "Your are using TechCloud version: " << version << std::endl;
    }

    if (vm.count("add")) {
        nf.addNote(bn.createNoteBash());
    }

    if (vm.count("list")) {
        //TODO
    }

    if (vm.count("edit")) {
        //TODO
        //int id = vm["edit"].as<int>();
    }

    if (vm.count("search")) {
        //TODO
    }

    if (vm.count("grafic")) {
        QApplication a(argc, argv);
        MainWindow window;
        //window.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
        window.show();
        return a.exec();
    }


    nf.print();
}
