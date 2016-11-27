#ifndef COLORIZE_H
#define COLORIZE_H
using namespace std;
#include <string>
#include <sstream>


#ifdef __linux__

class Colorize
{
public:
    template<class T> static string redBold(const T& t)
    {
        stringstream sd;
        sd << "\033[1;31m" << t << "\033[0m";

        return  sd.str();
    }

    template<class T> static string greenBold(const T& t)
    {
        stringstream sd;
        sd << "\033[1;32m" << t << "\033[0m";

        return  sd.str();
    }

    template<class T> static string yellowBold(const T& t)
    {
        stringstream sd;
        sd << "\033[1;33m" << t << "\033[0m";

        return  sd.str();
    }

    template<class T> static string blueBold(const T& t)
    {
        stringstream sd;
        sd << "\033[1;34m" << t << "\033[0m";

        return  sd.str();
    }

    template<class T> static string redBackground(const T& t)
    {
        stringstream sd;
        sd << "\033[41m" << t << "\033[0m";

        return  sd.str();
    }

    template<class T> static string greenBackground(const T& t)
    {
        stringstream sd;
        sd << "\033[42m" << t << "\033[0m";

        return  sd.str();
    }

    template<class T> static string yellowBackground(const T& t)
    {
        stringstream sd;
        sd << "\033[43m" << t << "\033[0m";

        return  sd.str();
    }

    template<class T> static string blueBackground(const T& t)
    {
        stringstream sd;
        sd << "\033[44m" << t << "\033[0m";

        return  sd.str();
    }
};
#endif // __linux__
#ifdef _WIN32
#include <windows.h>

class ColoredString : public string
{
    static HANDLE  hConsole;
    static unsigned char defColor;
    unsigned char color;
public:
    ColoredString(const string &str, unsigned char _color);

    friend ostream &operator<<(ostream &os, const ColoredString &cs)
    {
        SetConsoleTextAttribute(hConsole, cs.color);
        os << static_cast<const string &>(cs);
        SetConsoleTextAttribute(hConsole, defColor);
        return os;
    }
};

class Colorize
{
public:
    template<class T> static ColoredString redBold(const T& t)
    {
        stringstream sd;
        sd << t;
        return  ColoredString(sd.str(),0X0C);
    }

    template<class T> static ColoredString greenBold(const T& t)
    {
        stringstream sd;
        sd << t;
        return  ColoredString(sd.str(),0X0A);
    }

    template<class T> static ColoredString yellowBold(const T& t)
    {
        stringstream sd;
        sd << t;
        return  ColoredString(sd.str(),0X0E);
    }

    template<class T> static ColoredString blueBold(const T& t)
    {
        stringstream sd;
        sd << t;
        return  ColoredString(sd.str(),0X09);
    }

    template<class T> static ColoredString redBackground(const T& t)
    {
        stringstream sd;
        sd << t;
        return  ColoredString(sd.str(),0X4F);
    }

    template<class T> static ColoredString greenBackground(const T& t)
    {
        stringstream sd;
        sd << t;
        return  ColoredString(sd.str(),0X2F);
    }

    template<class T> static ColoredString yellowBackground(const T& t)
    {
        stringstream sd;
        sd << t;
        return  ColoredString(sd.str(),0X6F);
    }

    template<class T> static ColoredString blueBackground(const T& t)
    {
        stringstream sd;
        sd << t;
        return  ColoredString(sd.str(),0X9F);
    }
};

#endif // _WIN32


#endif // COLORIZE_H
