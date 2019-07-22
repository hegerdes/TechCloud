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
    /**
     * @brief Construct a new NoteFactory object
     *
     */
    NoteFactory(){}

    /**
     * @brief Destroy the NoteFactory object
     *
     */
    virtual ~NoteFactory() = default;

    bool addNote(Note note){
        m_con_notes.insert(std::pair<int,Note>(note.get_id(),note));
        return true;
    }

private:

    std::map<int,Note> m_con_notes;
};

} // namespace tcloud

#endif // !NOTE_Factory_HPP