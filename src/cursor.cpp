#include <iostream>

#include "carbon/cursor.hpp"

#ifdef _WIN32
#include <windows.h>
#else
#include <cstdio>
#include <cstdlib>
#include <termios.h>
#include <unistd.h>
#endif

static bool s_is_visible = true;

void carbon::cursor::move_home() { move_to(0, 0); }

void carbon::cursor::move_to(int col, int row)
{
    std::cout << "\033[" << row << ";" << col << "H";
    std::cout.flush();
}

void carbon::cursor::move_to_col(int col) { move_to(col, get_pos().y); }

void carbon::cursor::move_to_row(int row) { move_to(get_pos().x, row); }

void carbon::cursor::move_by(int col, int row)
{
    char dir;

    if (col != 0)
    {
        dir = col > 0 ? 'C' : 'D';
        std::cout << "\033[" << std::abs(col) << dir;
    }

    if (row != 0)
    {
        dir = row > 0 ? 'B' : 'A';
        std::cout << "\033[" << std::abs(row) << dir;
    }

    std::cout.flush();
}

carbon::Vector2 carbon::cursor::get_pos()
{
    Vector2 vec;
#ifdef _WIN32
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO info;
    if (!GetConsoleScreenBufferInfo(h, &info))
    {
        // error
        return vec;
    }
    vec.x = info.dwCursorPosition.X + 1; // X is 0-based
    vec.y = info.dwCursorPosition.Y + 1; // Y is 0-based
#else
    struct termios orig, raw;
    if (tcgetattr(STDIN_FILENO, &orig) == -1)
    {
        // error
        return vec;
    }
    raw = orig;
    raw.c_lflag &= ~(ICANON | ECHO);
    if (tcsetattr(STDIN_FILENO, TCSANOW, &raw) == -1)
    {
        // error
        return vec;
    }

    // Request cursor position
    std::cout << "\033[6n" << std::flush;

    // Read “ESC [ row ; col R”
    char buf[32] = {};
    size_t i = 0;
    while (i < sizeof(buf) - 1)
    {
        if (read(STDIN_FILENO, buf + i, 1) != 1)
            break;
        if (buf[i] == 'R')
            break;
        ++i;
    }
    buf[i + 1] = '\0';

    // Restore
    tcsetattr(STDIN_FILENO, TCSANOW, &orig);

    // Parse
    if (sscanf(buf, "\033[%d;%dR", &vec.y, &vec.x) != 2)
    {
        // error
        return vec;
    }

#endif

    return vec;
}

void carbon::cursor::save_pos() { std::cout << "\033[s"; }

void carbon::cursor::restore_pos() { std::cout << "\033[u"; }

void carbon::cursor::show()
{
    std::cout << "\033[?25h";
    s_is_visible = true;
}

void carbon::cursor::hide()
{
    std::cout << "\033[?25l";
    s_is_visible = false;
}

bool carbon::cursor::is_visible() { return s_is_visible; }
