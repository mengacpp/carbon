#include "tml/core.hpp"
#include "tml/cursor.hpp"

#include <iostream>

void tml::clear()
{
    //TODO use custom cout instead of normal one
    
    std::cout << "\033[2J";
    cursor::move_home();
    std::cout.flush();
}
