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
#include <nlohmann/json.hpp>
#include <stdexcept>
#include <regex>
#include <vector>
#include <memory>

namespace tcloud
{
using nlohmann::json;

class Ref
{
public:

    Ref();

    ~Ref() = default;

    std::string& get_replace_word();
    void set_replace_word(const std::string &value);

    int64_t& get_ref_num();
    void set_ref_num(const int64_t &value);

private:
    //Word to be replaced with a link
    std::string replace_word;

    //ID to the reffert Note
    int64_t ref_num;
};

class Note
{
public:
    using Ptr = std::shared_ptr<Note>;

    Note();

    ~Note() = default;

    int64_t& get_id();
    void set_id(const int64_t& value);

    std::string& get_title();
    void set_title(const std::string& value);

    std::string& get_sum();
    void set_sum(const std::string& value);

    std::string& get_dis();
    void set_dis(const std::string& value);

    std::string& get_example();
    void set_example(const std::string& value);

    std::vector<std::string>& get_tags();
    void set_tags(const std::vector<std::string>& value);

    std::string& get_group();
    void set_group(const std::string& value);

    bool& get_favorite();
    void set_favorite(const bool& value);

    std::vector<Ref>& get_refs();
    void set_refs(const std::vector<Ref>& value);


//private:
    int64_t m_id;
    std::string m_title;
    std::string m_sumery;
    std::string m_discription;
    std::string m_example;
    std::vector<std::string> m_tags;
    std::string m_group;
    bool m_favorite;
    std::vector<Ref> m_refs;
};

void inline to_json(json& j, const Note::Ptr& n)
{
    j = json{{"ID", n->get_id()}, {"Title", n->get_title()}, {"Summary", n->get_sum()}, {"Description", n->get_dis()},{"Example", n->get_example()}};
}

void inline from_json(const json& j, Note& n)
{
}

} // namespace tcloud

#endif // !NOTE_HPP