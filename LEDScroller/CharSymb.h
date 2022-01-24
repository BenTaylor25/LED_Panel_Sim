#include <vector>

std::vector<int> getCharVals(char c)
{
    switch (c)
    {
    case 'a':
        return { 14, 17, 17, 31, 17 };
    case 'b':
        return { 30, 17, 30, 17, 30 };
    case 'c':
        return { 14, 17, 16, 17, 14 };
    case 'd':
        return { 30, 17, 17, 17, 30 };
    case 'e':
        return { 31, 16, 28, 16, 31 };
    case 'f':
        return { 31, 16, 30, 16, 16 };
    case 'g':
        return { 15, 16, 23, 17, 15 };
    case 'h':
        return { 17, 17, 31, 17, 17 };
    case 'i':
        return { 31, 4, 4, 4, 31 };
    case 'j':
        return { 7, 4, 4, 20, 8 };
    case 'k':
        return { 17, 18, 20, 26, 17 };
    case 'l':
        return { 16, 16, 16, 16, 31 };
    case 'm':
        return { 17, 27, 21, 17, 17 };
    case 'n':
        return { 17, 25, 21, 19, 17 };
    case 'o':
        return { 14, 17, 17, 17, 14 };
    case 'p':
        return { 30, 17, 30, 16, 16 };
    case 'q':
        return { 14, 17, 21, 18, 13 };
    case 'r':
        return { 30, 17, 30, 18, 17 };
    case 's':
        return { 15, 16, 14, 1, 30 };
    case 't':
        return { 31, 4, 4, 4, 4 };
    case 'u':
        return { 17, 17, 17, 17, 14 };
    case 'v':
        return { 17, 10, 10, 4, 4 };
    case 'w':
        return { 17, 21, 21, 10, 10 };
    case 'x':
        return { 17, 10, 4, 10, 17 };
    case 'y':
        return { 17, 10, 4, 4, 4 };
    case 'z':
        return { 31, 2, 4, 8, 31 };
    case '!':
        return { 4, 4, 4, 0, 4 };
    }

    return { 0,0,0,0,0 };
}
