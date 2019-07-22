/**
 * @file NoteFactory.hpp
 * @author Henrik Gerdes (hegerdes@uni-osnabrueck.de)
 * @brief
 * @version 0.1
 * @date 2019-07-22
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef NOTE_Factory_HPP
#define NOTE_Factory_HPP

#pragma once

#include <map>
#include "Note.hpp"

namespace tcloud
{

class NoteFactory
{
public:

    static NoteFactory& getInstance()
    {
        static NoteFactory instance;
        return instance;
    }

    NoteFactory(NoteFactory const&)         = delete;
    void operator=(NoteFactory const&)      = delete;


    bool addNote(Note::Ptr note){
        m_con_notes.insert(std::pair<int,Note::Ptr>(note->get_id(),note));
        return true;
    }

    void print()
    {
        for(auto item : m_con_notes)
        {
            std::cout << item.second->get_title() << std::endl;
        }
    }

private:
    NoteFactory()
    {
        //m_con_notes = std::map<int,Note::Ptr>();
    }

private:

    static NoteFactory& instance;
    std::map<int,Note::Ptr> m_con_notes;
};

} // namespace tcloud

#endif // !NOTE_Factory_HPP