/**
 * @file Note_preference.hpp
 * @author Henrik Gerdes (hegerdes@uni-osnabrueck.de)
 * @brief
 * @version 0.1
 * @date 2019-06-03
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef NOTE_PREFFERENCE
#define NOTE_PREFFERENCE

#pragma once

#include <boost/optional.hpp>
#include <stdexcept>
#include <regex>

namespace tcloud
{

class NotePreferences
{
public:
    struct Favorite
    {
    private:
        int64_t note_id;
        std::string note_name;
    public:

    inline int64_t & get_note_id() { return note_id; }
    inline void set_note_id(const int64_t& value) { this->note_id = value; }

    inline std::string & get_note_name() { return note_name; }
    inline void set_note_name(const std::string& value) { this->note_name = value; }
    };

    NotePreferences();
    virtual ~NotePreferences() = default;

    inline std::vector<Favorite> & get_Favorites() { return m_Favorites; }
    inline void set_Favorites(const std::vector<Favorite>& value) { this->m_Favorites = value; }

    inline std::vector<std::string> & get_tags() { return m_tags; }
    inline void set_tags(const std::vector<std::string>& value) { this->m_tags = value; }

    inline std::vector<std::string> & get_groups() { return m_groups; }
    inline void set_groups(const std::vector<std::string>& value) { this->m_groups = value; }

    inline std::vector<std::string> & get_language() { return m_language; }
    inline void set_language(const std::vector<std::string>& value) { this->m_language = value; }


private:
    std::vector<Favorite> m_Favorites;
    std::vector<std::string> m_tags;
    std::vector<std::string> m_groups;
    std::vector<std::string> m_language;

};
} //tcloud

#endif
