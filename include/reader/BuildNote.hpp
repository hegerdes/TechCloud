/**
 * @file BuildNote.hpp
 * @author Henrik Gerdes (hegerdes@uni-osnabrueck.de)
 * @brief
 * @version 0.1
 * @date 2019-07-22
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef BUILDNOTE_HPP
#define BUILDNOTE_HPP

#pragma once

#include <memory>
#include <iostream>
#include "Note.hpp"
#include "NoteFactory.hpp"

namespace tcloud
{
class BuildNote
{
public:
    static BuildNote& getInstance()
    {
        static BuildNote instance;
        return instance;
    }

    BuildNote(BuildNote const&)         = delete;
    void operator=(BuildNote const&)    = delete;

    Note::Ptr createNoteBash()
    {
        std::string tmp;
        NoteFactory& nf = NoteFactory::getInstance();
        auto note = std::make_shared<Note>();
        note->set_id(nf.inc_id_counter());
        std::cout << "Enter entry name:" << std::endl;
        std::cin >> tmp;
        note->set_title(tmp);
        std::cout << "Enter discription:" << std::endl;
        std::cin >> tmp;
        note->set_dis(tmp);
        return note;
    }

    Note::Ptr createNoteGUI()
    {
        NoteFactory& nf = NoteFactory::getInstance();
        auto note = std::make_shared<Note>();
        note->set_id(nf.inc_id_counter());
        return note;
    }

private:
    BuildNote(){}

    static BuildNote& instance;

};

} // namespace tcloud


#endif