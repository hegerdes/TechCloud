/**
 * @file NoteFactory.cpp
 * @author Henrik Gerdes (hegerdes@uni-osnabrueck.de)
 * @brief
 * @version 0.1
 * @date 2019-07-24
 *
 * @copyright Copyright (c) 2019
 *
 */
#include "NoteFactory.hpp"

namespace tcloud
{

NoteFactory::NoteFactory(): id_counter(0)
{
    //m_con_notes = std::map<int,Note::Ptr>();
}

bool NoteFactory::addNote(Note::Ptr note){
    m_con_notes.insert(std::pair<int,Note::Ptr>(note->get_id(),note));
    return true;
}

void NoteFactory::print()
{
    for(auto item : m_con_notes)
    {
        json j = item.second;
        std::cout << j<< std::endl;
        //std::cout << item.second->get_title() << std::endl;
    }
}

NoteFactory& NoteFactory::getInstance()
{
    static NoteFactory instance;
    return instance;
}

int64_t NoteFactory::get_id_counter(){return id_counter;}
int64_t NoteFactory::inc_id_counter(){return ++id_counter;}

NoteFactory::NoteMap NoteFactory::getMap(){return m_con_notes;}

} //tcloud