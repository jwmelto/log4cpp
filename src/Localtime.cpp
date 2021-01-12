/*
 * Copyright 2002, Log4cpp Project. All rights reserved.
 *
 * See the COPYING file for the terms of usage and distribution.
 */

#include <log4cpp/Portability.hh>
#include "Localtime.hh"
#include <ctime>

namespace log4cpp         
{

// Portability of reentrant forms of localtime is problematic. POSIX
// defines localtime_r but Microsoft wanted to invent their own (which
// is non-standards conforming). For now, don't worry about it.
   void localtime(std::time_t time, std::tm& t)
   {
       auto tmp = std::localtime(&time);
       if (tmp != nullptr)
       {
	   t = *tmp;
       }
   }

}
