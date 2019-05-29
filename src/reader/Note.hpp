/**
 * @file Note.hpp
 * @author Henrik Gerdes (hegerdes@uni-osnabrueck.de)
 * @brief
 * @version 0.1
 * @date 2019-05-29
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef NOTE_HPP
#define NOTE_HPP

#pragma once

#include <iostream>
#include <boost/optional.hpp>
#include <stdexcept>
#include <regex>

namespace tcloud
{

class Ref
{
public:
    /**
	 * @brief Construct a new Ref object
	 *
	 */
    Ref() = default;

    /**
	 * @brief Destroy the Ref object
	 *
	 */
    virtual ~Ref() = default;

    inline std::string &get_replace_word() { return replace_word; }

    inline void set_replace_word(const std::string &value) { this->replace_word = value; }

    inline int64_t &get_ref_num() { return ref_num; }

    inline void set_ref_num(const int64_t &value) { this->ref_num = value; }

private:
    //Word to be replaced with a link
    std::string replace_word;

    //ID to the reffert Note
    int64_t ref_num;
};

class Note
{
public:
    /**
     * @brief Construct a new Note object
     *
     */
    Note() = default;

    Note(int a);

    /**
     * @brief Destroy the Note object
     *
     */
    virtual ~Note() = default;

    inline int64_t & get_id() { return m_id; }
    void set_id(const int64_t& value) { this->m_id = value; }

    inline std::string & get_title() { return m_title; }
    void set_title(const std::string& value) { this->m_title = value; }

    inline std::string & get_sum() { return m_sumery; }
    void set_sum(const std::string& value) { this->m_sumery = value; }

    inline std::string & get_dis() { return m_discription; }
    void set_dis(const std::string& value) { this->m_discription = value; }

    inline std::string & get_example() { return m_example; }
    void set_example(const std::string& value) { this->m_example = value; }

    inline std::vector<int64_t> & get_tags() { return m_tags; }
    void set_tags(const std::vector<int64_t>& value) { this->m_tags = value; }

    inline std::vector<int64_t> & get_language() { return m_language; }
    void set_language(const std::vector<int64_t>& value) { this->m_language = value; }

    inline std::string & get_group() { return m_group; }
    void set_group(const std::string& value) { this->m_group = value; }

    inline bool & get_favorite() { return m_favorite; }
    void set_favorite(const bool& value) { this->m_favorite = value; }

    inline std::vector<Ref> & get_refs() { return m_refs; }
    void set_refs(const std::vector<Ref>& value) { this->m_refs = value; }


private:
    int64_t m_id;
    std::string m_title;
    std::string m_sumery;
    std::string m_discription;
    std::string m_example;
    std::vector<int64_t> m_tags;
    std::vector<int64_t> m_language;
    std::string m_group;
    bool m_favorite;
    std::vector<Ref> m_refs;
};

} // namespace tcloud

#endif // !NOTE_HPP