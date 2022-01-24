#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

#include <math.h>
#include "CharSymb.h"

std::string phrase = "This is my LED panel";

int p;
bool keepOpen;
int ptr;
int timer;
int pushCount;
olc::Pixel drawPixels[60][5];

void pushUp()
{
    for (int y = 0; y < 59; y++)
    {
        for (int x = 0; x < 5; x++)
        {
            drawPixels[y][x] = drawPixels[y + 1][x];
        }
    }
}

std::vector<olc::Pixel> splitter(int x)
{
    std::vector<olc::Pixel> line;

    for (int i = 4; i >= 0; i--)
    {
        if (x >= pow(2, i))
        {
            line.push_back(olc::WHITE);
            x -= pow(2, i);
        }
        else
        {
            line.push_back(olc::BLACK);
        }
    }

    return line;
}

void getSymb(char c, olc::Pixel* newChar)
{
    std::vector<int> cVals = getCharVals(c);

    std::vector<std::vector<olc::Pixel>> _newChar;

    for (int x = 0; x < 5; x++)
    {
        _newChar.push_back(splitter(cVals[x]));
    }

    for (int x = 0; x < 5; x++)
    {
        for (int y = 0; y < 5; y++)
        {
            *newChar = _newChar[x][y];
            newChar++;
        }
    }
}

void addChar(char c)
{
    olc::Pixel newChar[5][5];
    getSymb(c, *newChar);

    for (int i = 0; i < 5; i++)
    {
        for (int x = 0; x < 5; x++)
        {
            drawPixels[i + 54][x] = newChar[i][x];
        }
    }
}

void formatPhrase()
{
    for (int c = 0; c < phrase.length(); c++)
    {
        if (phrase[c] >= 65 && phrase[c] <= 90)
        {
            phrase[c] += 32;
        }
    }

    phrase += " ";
}

class WINDOW : public olc::PixelGameEngine
{
public:
    WINDOW() { sAppName = "SPT"; }

    bool OnUserCreate() override
    {
        formatPhrase();
        p = 0;
        keepOpen = true;
        ptr = 0;
        timer = 0;
        pushCount = 0;

        for (int x = 0; x < 5; x++)
        {
            for (int y = 0; y < 54; y++)
            {
                drawPixels[y][x] = olc::BLACK;
            }
        }

        return true;
    }

    bool OnUserUpdate(float fElapsedTime) override
    {
        timer = (timer + 1) % 500;
        if (timer == 0)
        {
            if (pushCount == 0)
            {
                addChar(phrase[p]);
                p = (p + 1) % phrase.length();
            }

            pushCount = (pushCount + 1) % 6;
            pushUp();
        }

        for (int x = 0; x < 5; x++)
        {
            for (int y = 0; y < 54; y++)
            {
                this->Draw(x, y, drawPixels[y][x]);
            }
        }

        return keepOpen;
    }
};

int main()
{
    ShowWindow(GetConsoleWindow(), SW_HIDE);

    WINDOW ScrollingPanelText;
    if (ScrollingPanelText.Construct(5, 54, 18, 10))
    {
        ScrollingPanelText.Start();
    }

    return 0;
}
