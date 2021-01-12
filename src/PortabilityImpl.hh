/*
 * PortabilityImpl.hh
 *
 * Copyright 2002, Log4cpp Project. All rights reserved.
 *
 * See the COPYING file for the terms of usage and distribution.
 */

#ifndef _LOG4CPP_PORTABILITYIMPL_HH
#define _LOG4CPP_PORTABILITYIMPL_HH

#include <log4cpp/Portability.hh>

namespace log4cpp
{
    template<typename T> const T& min(const T& a, const T& b)
    {
       return a < b ? a : b;
    }

    template<typename T> const T& max(const T& a, const T& b)
    {
       return a > b ? a : b;
    }
}

#endif // _LOG4CPP_PORTABILITYIMPL_HH
