#pragma once

#include <iostream>

#define LOG_FUNCTION() \
    std::clog << __PRETTY_FUNCTION__ << '\n'
