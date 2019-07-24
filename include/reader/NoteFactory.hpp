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
    using NoteMap = std::map<int,Note::Ptr>;

    static NoteFactory& getInstance();

    bool addNote(Note::Ptr note);

    NoteMap getMap();

    void print();

    int64_t get_id_counter();
    int64_t inc_id_counter();

    NoteFactory(NoteFactory const&)         = delete;
    void operator=(NoteFactory const&)      = delete;


private:
    NoteFactory();

    static NoteFactory& instance;
    NoteMap m_con_notes;

    int32_t id_counter;
};

} // namespace tcloud

#endif // !NOTE_Factory_HPP