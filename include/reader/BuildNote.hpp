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

    Note::Ptr createNote()
    {
        auto note = std::make_shared<Note>();
        std::cout << "Enter entry name:" << std::endl;
        std::string tmp;
        std::cin >> tmp;
        note->set_title(tmp);
        return note;
    }

private:
    BuildNote(){}
};

} // namespace tcloud


#endif