/*
 * Copyright 2002, Log4cpp Project. All rights reserved.
 *
 * See the COPYING file for the terms of usage and distribution.
 */

#include <log4cpp/threading/Threading.hh>

namespace log4cpp {
    namespace threading {

        std::string getThreadId() {
            // more useful would be to return the PID.
            return std::string("thread1");
        }

    }
}

