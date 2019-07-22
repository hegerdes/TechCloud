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



private:
    BuildNote(){}
};

} // namespace tcloud


#endif