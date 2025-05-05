#include "carbon/core.hpp"
#include "carbon/cursor.hpp"

#include <iostream>

void carbon::clear()
{
    // TODO use custom cout instead of normal one

    std::cout << "\033[2J";
    cursor::move_home();
    std::cout.flush();
}
