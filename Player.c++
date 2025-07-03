#include <iostream>
#include "moves.h"

using namespace std;

void playerMove1(char** space, char* charsp, char* charspe)
{
    bool moved = false;
    int i;
    int j;
    char row;
    int rowi;
    char rowis;
    int slot;
    char moverow;
    int moverowi;
    int moveslot;
    do {
        cout << "select row a-h:\n";
        cin >> row;
        rowi = row - 97;
        cout << "select slot 1-8:\n";
        cin >> slot;
        slot--;
        switch (space[rowi] [slot])
        {
            case '|':
            moved = Pawn(space, rowi, rowis, slot, moverow, moverowi, moveslot, moved, charsp[0], charspe, charsp[6], 6, -1);
            break;
            case '+':
            moved = Rock(space, rowi, slot, charsp[1], charspe);
            break;

            case 'r':
            moved = Knight(space, rowi, slot, charsp[2], charspe);
            break;
            case 'x':
            moved = Bishop(space, rowi, slot, charsp[3], charspe);
            break;
            case '*':
            moved = Quin(space, rowi, slot, charsp[4], charspe);
            break;
            case '#':
            moved = King(space, rowi, slot, charsp[5], charspe);
            break;
        }
    } while (moved == false);
}
void playerMove2(char** space, char* charsp, char* charspe)
{
    //char charsply[7] = {'|','+','r','x','*','#',' '};
    bool moved = false;
    int i;
    int j;
    char row;
    char rowis;
    int slot;
    char moverow;
    int moveslot;
    do {
        cout << "select row a-h:\n";
        cin >> row;
        row = row - 97;
        cout << "select slot 1-8:\n";
        cin >> slot;
        slot--;
        switch (space[row] [slot])
        {
            case 'p':
            moved = Pawn(space, row, rowis, slot, moverow, moverow, moveslot, moved, charsp[0], charspe /*charsply*/, charsp[6], 1, 1);
            break;
            case 'R':
            moved = Rock(space, row, slot, charsp[1], charspe /*charsply*/);
            break;
            case 'k':
            moved = Knight(space, row, slot, charsp[2], charspe /*charsply*/);
            break;
            case 'b':
            moved = Bishop(space, row, slot, charsp[3], charspe /*charsply*/);
            break;
            case 'Q':
            moved = Quin(space, row, slot, charsp[4], charspe /*charsply*/);
            break;
            case 'K':
            moved = King(space, row, slot, charsp[1], charspe /*charsply*/);
            break;
        }
    } while (moved == false);
}
