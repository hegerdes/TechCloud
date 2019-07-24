/**
 * @file Note.cpp
 * @author Henrik Gerdes (hegerdes@uni-osnabrueck.de)
 * @brief
 * @version 0.1
 * @date 2019-05-30
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "reader/Note.hpp"

namespace tcloud
{

Note::Note(){}

int64_t& Note::get_id() { return m_id; }
void Note::set_id(const int64_t& value) { this->m_id = value; }

std::string& Note::get_title() { return m_title; }
void Note::set_title(const std::string& value) { this->m_title = value; }

std::string& Note::get_sum() { return m_sumery; }
void Note::set_sum(const std::string& value) { this->m_sumery = value; }

std::string& Note::get_dis() { return m_discription; }
void Note::set_dis(const std::string& value) { this->m_discription = value; }

std::string& Note::get_example() { return m_example; }
void Note::set_example(const std::string& value) { this->m_example = value; }

std::vector<std::string>& Note::get_tags() { return m_tags; }
void Note::set_tags(const std::vector<std::string>& value) { this->m_tags = value; }

std::string& Note::get_group() { return m_group; }
void Note::set_group(const std::string& value) { this->m_group = value; }

bool& Note::get_favorite() { return m_favorite; }
void Note::set_favorite(const bool& value) { this->m_favorite = value; }

std::vector<Ref>& Note::get_refs() { return m_refs; }
void Note::set_refs(const std::vector<Ref>& value) { this->m_refs = value; }


//Ref
Ref::Ref(){}

std::string& Ref::get_replace_word() { return replace_word; }
void Ref::set_replace_word(const std::string &value) { this->replace_word = value; }

int64_t& Ref::get_ref_num() { return ref_num; }
void Ref::set_ref_num(const int64_t &value) { this->ref_num = value; }

} //tcloud