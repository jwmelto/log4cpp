/*
 * BasicConfigurator.cpp
 *
 * Copyright 2002, Log4cpp Project. All rights reserved.
 *
 * See the COPYING file for the terms of usage and distribution.
 */
#include "PortabilityImpl.hh"

#include <log4cpp/BasicConfigurator.hh>
#include <log4cpp/Category.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/Priority.hh>

#include <cstdio>
#include <unistd.h>

namespace log4cpp {

    void BasicConfigurator::configure() {
        Category& root = Category::getRoot();
        root.setPriority(Priority::INFO);
        root.removeAllAppenders();
        root.addAppender(new FileAppender("_", ::dup(fileno(stdout))));
    }

}



