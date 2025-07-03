#include "moves.h"
#include "conf.c++"

int main()
{
    drawBoard(space);
    bool running = true;
    while (running)
    {
        playerMove1(space, charsp1, charsp2);
        drawBoard(space);
        playerMove2(space, charsp2, charsp1);
        drawBoard(space);
    }
}
