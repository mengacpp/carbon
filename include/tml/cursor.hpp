#pragma once

#include "utils.hpp"
namespace tml
{

namespace cursor
{

    void move_home();
    void move_to(int col, int row);
    void move_to_col(int col);
    void move_to_row(int row);
    void move_by(int col, int row);

    Vector2 get_pos();

}

}