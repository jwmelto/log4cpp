/*
 * BasicLayout.cpp
 *
 * Copyright 2000, LifeLine Networks BV (www.lifeline.nl). All rights reserved.
 * Copyright 2000, Bastiaan Bakker. All rights reserved.
 *
 * See the COPYING file for the terms of usage and distribution.
 */

#include <log4cpp/BasicLayout.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/FactoryParams.hh>

#include <memory>
#include <sstream>

namespace log4cpp {

    BasicLayout::BasicLayout() {
    }
    
    BasicLayout::~BasicLayout() {
    }

    std::string BasicLayout::format(const LoggingEvent& event) {
        std::ostringstream message;

        const std::string& priorityName = Priority::getPriorityName(event.priority);
        message << event.timeStamp.getSeconds() << " " << priorityName << " " 
                << event.categoryName << " " << event.ndc << ": " 
                << event.message << std::endl;

        return message.str();
    }

    std::unique_ptr<Layout> create_basic_layout(const FactoryParams& params)
    {
       return std::unique_ptr<Layout>(new BasicLayout);
    }
}
