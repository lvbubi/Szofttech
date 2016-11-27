#include "colorize.h"

#ifdef _WIN32

HANDLE ColoredString::hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
unsigned char ColoredString::defColor = 0x0F;

ColoredString::ColoredString(const string &str, unsigned char _color):
    string(str),
    color(_color)
{
}


#endif // _WIN32
