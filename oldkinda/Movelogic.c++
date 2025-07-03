//#include <algorithm>
#include<iostream>
//#include <list>
#include "Movelogic.h"
using namespace std;
/*
int i;
int j;
char row;

int rowi;
char rowis;
int slot;
char moverow;
int moverowi;
int moveslot;

*/
bool Pawn(char**, int, char, int, char, int, int);

bool Pawn(char** space, int rowi, char rowis, int slot, char moverow, int moverowi, int moveslot)
{
    //Möglichkeiten Pawn
    cout << "posible moves Pawn";
    if (rowi == 6){
        if (space[rowi-1] [slot] == ' ')
        {
            rowis = rowi+97-1;
            cout << rowis << ',' << slot+1 << '|';
        }
        if (space[rowi-2] [slot] == ' ')
        {
            rowis = rowi+97-2;
            cout << rowis << ',' << slot+1;
        }
        cout <<"\n";

        //Move Pawn
        cout << "move row a-h: \n";
        cin >> moverow;
        moverowi = moverow - 97;
        cout << "move row 1-8: \n";
        cin >> moveslot;
        moveslot--;
        if ((moveslot == slot && moverowi == rowi-1) || (moveslot == slot && moverowi == rowi-2))
        {
            space[rowi] [slot] = ' ';
            space[moverowi] [moveslot] = '|';
            return true;
        }/*
        else
        {
            return false;
        }*/
    }
    else {
        if (space[rowi-1] [slot] == ' ')
        {
            rowis = rowi+97-1;
            cout << rowis << ',' << slot+1;
        }
        cout <<"\n";
        cout << "move row a-h: \n";
        cin >> moverow;
        moverowi = moverow - 97;
        cout << "move row 1-8: \n";
        cin >> moveslot;
        moveslot--;
        if (moveslot == slot && moverowi == rowi-1)
        {
        space[rowi] [slot] = ' ';
        space[moverowi] [moveslot] = '|';
        return true;
        }/*
        else
        {
            return false;
        }*/;
    }
    return false;
}
