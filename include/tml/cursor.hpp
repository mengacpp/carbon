#pragma once

namespace tml
{

class Cursor
{
public:
    
private:
};

Cursor &get_cursor()
{
    static Cursor instance;
    return instance;
}

}