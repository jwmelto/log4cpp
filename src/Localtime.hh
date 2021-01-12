/*
 * Copyright 2002, Log4cpp Project. All rights reserved.
 *
 * See the COPYING file for the terms of usage and distribution.
 */

#ifndef _LOG4CPP_LOCALTIME_HH
#define _LOG4CPP_LOCALTIME_HH

#include <ctime>

namespace log4cpp
{
   void localtime(std::time_t time, std::tm& t);
}

#endif
