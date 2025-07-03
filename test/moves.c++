// my_class.cpp
#include "moves.h" // header in local directory
#include <iostream> // header in standard library
#include <cstring>

using namespace std;

bool Pawn(char** space, int rowi, char rowis, int slot, char moverow, int moverowi, int moveslot, bool moved, char piece, char* pos, char empty, int start, int mult)
{
    bool posible = false;
    //Möglichkeiten Pawn
    cout << "posible moves Pawn \n";
    if (rowi == start){
        if ((space[rowi+(1*mult)] [slot] == ' ') && (space[rowi+(2*mult)] [slot] == ' '))
        {
            rowis = rowi+97+(1*mult);
            cout << rowis << ',' << slot+1 << '|';
            posible = true;
        }
        if (space[rowi+(2*mult)] [slot] == ' ')
        {
            rowis = rowi+97+(2*mult);
            cout << rowis << ',' << slot+1 << '|';
            posible = true;
        }

        if ((memchr(pos, space[rowi+(1*mult)] [slot-1], strlen(pos-1)) != NULL) && (space[rowi+(1*mult)] [slot-1] != ' ') && (slot >= 0))
        {
            rowis = rowi+97+(1*mult);
            cout << rowis << ',' << slot << '|';
            posible = true;
        }
        if (memchr(pos, space[rowi+(1*mult)] [slot+1], strlen(pos-1)) != NULL && space[rowi+(1*mult)] [slot+1] != ' ' && slot <= 7)
        {
            rowis = rowi+97+(1*mult);
            cout << rowis << ',' << slot+2 << '|';
            posible = true;
        }

        cout <<"\n";
        if (posible == false)
        {
            cout << "no posible moves \n";
            return false;
        };
        //Move Pawn
        cout << "move row a-h: \n";
        cin >> moverow;
        moverowi = moverow - 97;
        cout << "move slot 1-8: \n";
        cin >> moveslot;
        moveslot--;
        if ((moveslot == slot && moverowi == rowi+(1*mult)) || (moveslot == slot && moverowi == rowi+(2*mult)))
        {
            space[rowi] [slot] = ' ';
            space[moverowi] [moveslot] = piece;
            moved = true;
        }
        if ((moveslot == slot-1 || moverowi == rowi+(1*mult)) && (memchr(pos, space[rowi+(1*mult)] [slot-1], strlen(pos-1)) != NULL) && (space[rowi+(1*mult)] [slot-1] != ' ') && (slot >= 0))
        {
            space[rowi] [slot] = ' ';
            space[moverowi] [moveslot] = piece;
            moved = true;
        }
        if ((moveslot == slot+1 || moverowi == rowi+(1*mult)) && memchr(pos, space[rowi+(1*mult)] [slot+1], strlen(pos-1)) != NULL && space[rowi+(1*mult)] [slot+1] != ' ' && slot <= 7)
        {
            space[rowi] [slot] = ' ';
            space[moverowi] [moveslot] = piece;
            moved = true;
        }
    }
    else if(rowi > 0 && rowi < 7)
    {
        if (space[rowi+(1*mult)] [slot] == ' ')
        {
            rowis = rowi+97+(1*mult);
            cout << rowis << ',' << slot+1 << '|';
        }

        if ((memchr(pos, space[rowi+(1*mult)] [slot-1], strlen(pos-1)) != NULL) && (space[rowi+(1*mult)] [slot-1] != ' ') && (slot >= 0))
        {
            rowis = rowi+97+(1*mult);
            cout << rowis << ',' << slot << '|';
            posible = true;
        }
        if (memchr(pos, space[rowi+(1*mult)] [slot+1], strlen(pos-1)) != NULL && space[rowi+(1*mult)] [slot+1] != ' ' && slot <= 7)
        {
            rowis = rowi+97+(1*mult);
            cout << rowis << ',' << slot+2 << '|';
            posible = true;
        }

        cout <<"\n";
        cout << "move row a-h: \n";
        cin >> moverow;
        moverowi = moverow - 97;
        cout << "move row 1-8: \n";
        cin >> moveslot;
        moveslot--;
        if (moveslot == slot && moverowi == rowi+(1*mult))
        {
        space[rowi] [slot] = ' ';
        space[moverowi] [moveslot] = piece;
        moved = true;
        }
        if ((moveslot == slot-1 || moverowi == rowi+(1*mult)) && (memchr(pos, space[rowi+(1*mult)] [slot-1], strlen(pos-1)) != NULL) && (space[rowi+(1*mult)] [slot-1] != ' ') && (slot >= 0))
        {
            space[rowi] [slot] = ' ';
            space[moverowi] [moveslot] = piece;
            moved = true;
        }
        if ((moveslot == slot+1 || moverowi == rowi+(1*mult)) && memchr(pos, space[rowi+(1*mult)] [slot+1], strlen(pos-1)) != NULL && space[rowi+(1*mult)] [slot+1] != ' ' && slot <= 7)
        {
            space[rowi] [slot] = ' ';
            space[moverowi] [moveslot] = piece;
            moved = true;
        }

    }
    else
    {
        return false;
    }
    return moved;
}

bool Rock(char** space, int row, int slot, char piece, char* pos)
{
    bool posible = false;
    cout << "Posible Moves Rock: \n";
    //Möglichkeiten Rock
    if (slot < 7)
    {
        if (posiblemoveloop(slot, row, 1, 0, 1, space, pos))
        {
            posible = true;
        }
    }
    if (slot > 0)
    {
        if (posiblemoveloop(slot, row, -1, 0, 1, space, pos))
        {
            posible = true;
        }
    }
    if (row < 7)
    {
        if (posiblemoveloop(slot, row, 0, 1, 1, space, pos))
        {
            posible = true;
        }
    }
    if (row > 0)
    {
        if (posiblemoveloop(slot, row, 0, -1, 1, space, pos))
        {
            posible = true;
        }
    }
    if (posible == false)
    {
        cout << "no posible moves \n";
        return false;
    };
    //Move Rock
    char moverowi;
    int moverow;
    int moveslot;
    bool moved = false;
    cout << "\n move row a-h: \n";
    cin >> moverowi;
    moverow = moverowi - 97;
    cout << "move row 1-8: \n";
    cin >> moveslot;
    moveslot--;
    if (slot < 7)
    {
        if (moveloop(slot, row, 1, 0, moveslot, moverow, space, pos, piece))
        {
            moved = true;
        }
    }
    if (slot > 0)
    {
        if (moveloop(slot, row, -1, 0, moveslot, moverow, space, pos, piece))
        {
            moved = true;
        }
    }
    if (row < 7)
    {
        if (moveloop(slot, row, 0, 1, moveslot, moverow, space, pos, piece))
        {
            moved = true;
        }
    }
    if (row > 0)
    {
        if (moveloop(slot, row, 0, -1, moveslot, moverow, space, pos, piece))
        {
            moved = true;
        }
    }
    return moved;
}


bool Knight(char** space, int row, int slot, char piece, char* pos)
{
    bool posible = false;
    cout << "posible moves Knight: \n";
    //möglichkeiten Knight
    if (slot-2 >= 0 && row-1 >= 0)
    {
        if (posiblemove(slot, row, -2, -1, 1, space, pos))
        {
            posible = true;
        }
    }
    if (slot+2 <= 7 && row-1 >= 0)
    {
        if (posiblemove(slot, row, 2, -1, 1, space, pos))
        {
            posible = true;
        }
    }
    if (slot-2 >= 0 && row+1 <= 7)
    {
        if (posiblemove(slot, row, -2, -1, 1, space, pos))
        {
            posible = true;
        }
    }
    if (slot+2 <= 7 && row+1 <= 7)
    {
        if (posiblemove(slot, row, 2, 1, 1, space, pos))
        {
            posible = true;
        }
    }
    if (slot-1 >= 0 && row-2 >= 0)
    {
        if (posiblemove(slot, row, -1, -2, 1, space, pos))
        {
            posible = true;
        }
    }
    if (slot+1 <= 7 && row-2 >= 0)
    {
        if (posiblemove(slot, row, 1, -2, 1, space, pos))
        {
            posible = true;
        }
    }
    if (slot-1 >= 0 && row+2 <= 7)
    {
        if (posiblemove(slot, row, -1, 2, 1, space, pos))
        {
            posible = true;
        }
    }
    if (slot+1 <= 7 && row+2 <= 7)
    {
        if (posiblemove(slot, row, 1, 2, 1, space, pos))
        {
            posible = true;
        }
    }
    cout <<"\n";
    if (posible == false)
    {
        cout << "no posible moves \n";
        return false;
    };
    //Move Knight
    char moverowl;
    int moverow;
    int moveslot;
    bool moved;
    cout << "move row a-h: \n";
    cin >> moverowl;
    moverow = moverowl - 97;
    cout << "move row 1-8: \n";
    cin >> moveslot;
    moveslot--;
    if (slot-2 >= 0 && row-1 >= 0)
    {
        if (move(slot, row, -2, -1, moveslot, moverow, space, pos, piece))
        {
            moved = true;
        }
    }
    if (slot+2 <= 7 && row-1 >= 0)
    {
        if (move(slot, row, 2, -1, moveslot, moverow, space, pos, piece))
        {
            moved = true;
        }
    }
    if (slot-2 >= 0 && row+1 <= 7)
    {
        if (move(slot, row, -1, 1, moveslot, moverow, space, pos, piece))
        {
            moved = true;
        }
    }
    if (slot+2 <= 7 && row+1 <= 7)
    {
        if (move(slot, row, 2, 1, moveslot, moverow, space, pos, piece))
        {
            moved = true;
        }
    }
    if (slot-1 >= 0 && row-2 >= 0)
    {
        if (move(slot, row, -1, -2, moveslot, moverow, space, pos, piece))
        {
            moved = true;
        }
    }
    if (slot+1 <= 7 && row-2 >= 0)
    {
        if (move(slot, row, 1, -2, moveslot, moverow, space, pos, piece))
        {
            moved = true;
        }
    }
    if (slot-1 >= 0 && row+2 <= 7)
    {
        if (move(slot, row, 0, 2, moveslot, moverow, space, pos, piece))
        {
            moved = true;
        }
    }
    if (slot+1 <= 7 && row+2 <= 7)
    {
        if (move(slot, row, 1, 2, moveslot, moverow, space, pos, piece))
        {
            moved = true;
        }
    }
    return true;
}

bool Bishop(char** space, int row, int slot, char piece, char* pos)
{
    bool posible = false;
    cout << "posible moves Bishop: \n";
    //Möglichkeiten Bishop
    if (slot < 7 && row < 7)
    {
        if (posiblemoveloop(slot, row, 1, 1, 1, space, pos))
        {
            posible = true;
            cout <<'\n';
        }
    }
    if (slot > 0 && row > 0)
    {
        if (posiblemoveloop(slot, row, -1, -1, 1, space, pos))
        {
            posible = true;
            cout <<'\n';
        }
    }
    if (slot < 7 && row > 0)
    {
        if (posiblemoveloop(slot, row, 1, -1, 1, space, pos))
        {
            posible = true;
            cout <<'\n';
        }
    }
    if (slot > 0 && row < 7)
    {
        if (posiblemoveloop(slot, row, -1, 1, 1, space, pos))
        {
            posible = true;
            cout <<'\n';
        }
    }
    if (posible == false)
    {
        cout << "no posible moves \n";
        return false;
    };
    //Move Bishop
    char moverowi;
    int moverow;
    int moveslot;
    bool moved = false;
    cout << "move row a-h: \n";
    cin >> moverowi;
    moverow = moverowi - 97;
    cout << "move row 1-8: \n";
    cin >> moveslot;
    moveslot--;
    if (slot < 7 && row < 7)
    {
        if (moveloop(slot, row, 1, 1, moveslot, moverow, space, pos, piece))
        {
            moved = true;
        }
    }
    if (slot > 0 && row > 0)
    {
        if (moveloop(slot, row, -1, -1, moveslot, moverow, space, pos, piece))
        {
            moved = true;
        }
    }
    if (slot < 7 && row > 0)
    {
        if (moveloop(slot, row, 1, -1, moveslot, moverow, space, pos, piece))
        {
            moved = true;
        }
    }
    if (slot > 0 && row < 7)
    {
        if (moveloop(slot, row, -1, 1, moveslot, moverow, space, pos, piece))
        {
            moved = true;
        }
    }
    return moved;
}

bool Quin(char** space, int row, int slot, char piece, char* pos)
{
    bool posible = false;
    cout << "Posible Moves Quin: \n";
    //Möglichkeiten Quin
    if (slot < 7)
    {
        if (posiblemoveloop(slot, row, 1, 0, 0, space, pos))
        {
            posible = true;
            cout <<'\n';
        }
    }
    if (slot > 0)
    {
        if (posiblemoveloop(slot, row, -1, 0, 1, space, pos))
        {
            posible = true;
            cout <<'\n';
        }
    }
    if (row < 7)
    {
        if (posiblemoveloop(slot, row, 0, 1, 1, space, pos))
        {
            posible = true;
            cout <<'\n';
        }
    }
    if (row > 0)
    {
        if (posiblemoveloop(slot, row, 0, -1, 1, space, pos))
        {
            posible = true;
            cout <<'\n';
        }
    }
    if (slot < 7 && row < 7)
    {
        if (posiblemoveloop(slot, row, 1, 1, 1, space, pos))
        {
            posible = true;
            cout <<'\n';
        }
    }
    if (slot > 0 && row > 0)
    {
        if (posiblemoveloop(slot, row, -1, -1, 1, space, pos))
        {
            posible = true;
            cout <<'\n';
        }
    }
    if (slot < 7 && row > 0)
    {
        if (posiblemoveloop(slot, row, 1, -1, 1, space, pos))
        {
            posible = true;
            cout <<'\n';
        }
    }
    if (slot > 0 && row < 7)
    {
        if (posiblemoveloop(slot, row, -1, 1, 1, space, pos))
        {
            posible = true;
            cout <<'\n';
        }
    }
    if (posible == false)
    {
        cout << "no posible moves \n";
        return false;
    };
    //Move Quine
    char moverowi;
    int moverow;
    int moveslot;
    bool moved = false;
    cout << "move row a-h: \n";
    cin >> moverowi;
    moverow = moverowi - 97;
    cout << "move row 1-8: \n";
    cin >> moveslot;
    moveslot--;
    if (slot < 7)
    {
        if (moveloop(slot, row, 1, 0, moveslot, moverow, space, pos, piece))
        {
            moved = true;
        }
    }
    if (slot > 0)
    {
        if (moveloop(slot, row, -1, 0, moveslot, moverow, space, pos, piece))
        {
            moved = true;
        }
    }
    if (row < 7)
    {
        if (moveloop(slot, row, 0, 1, moveslot, moverow, space, pos, piece))
        {
            moved = true;
        }
    }
    if (row > 0)
    {
        if (moveloop(slot, row, 0, -1, moveslot, moverow, space, pos, piece))
        {
            moved = true;
        }
    }
    if (slot < 7 && row < 7)
    {
        if (moveloop(slot, row, 1, 1, moveslot, moverow, space, pos, piece))
        {
            moved = true;
        }
    }
    if (slot > 0 && row > 0)
    {
        if (moveloop(slot, row, -1, -1, moveslot, moverow, space, pos, piece))
        {
            moved = true;
        }
    }
    if (slot < 7 && row > 0)
    {
        if (moveloop(slot, row, 1, -1, moveslot, moverow, space, pos, piece))
        {
            moved = true;
        }
    }
    if (slot > 0 && row < 7)
    {
        if (moveloop(slot, row, -1, 1, moveslot, moverow, space, pos, piece))
        {
            moved = true;
        }
    }
    return true;
}

bool King(char** space, int row, int slot, char piece, char* pos)
{
    bool posible = false;
    cout << "posible: moves King \n";
    //möglichkeiten King
    if (slot+1 < 8)
    {
        if (posiblemove(slot, row, 1, 0, 1, space, pos))
        {
            posible = true;
        }
    }
    if (slot-1 >= 0)
    {
        if (posiblemove(slot, row, -1, 0, 1, space, pos))
        {
            posible = true;
        }
    }
    if (row+1 < 8)
    {
        if (posiblemove(slot, row, 0, 1, 1, space, pos))
        {
            posible = true;
        }
    }
    if (row-1 >= 0)
    {
        if (posiblemove(slot, row, 0, -1, 1, space, pos))
        {
            posible = true;
        }
    }
    if (slot+1 < 8 && row+1 < 8)
    {
        if (posiblemove(slot, row, 1, 1, 1, space, pos))
        {
            posible = true;
        }
    }
    if (slot-1 >= 0 && row-1 >= 0)
    {
        if (posiblemove(slot, row, -1, -1, 1, space, pos))
        {
            posible = true;
        }
    }
    if (slot+1 < 8 && row-1 >= 0)
    {
        if (posiblemove(slot, row, 1, -1, 1, space, pos))
        {
            posible = true;
        }
    }
    if (slot-1 < 8 && row+1 >= 0)
    {
        if (posiblemove(slot, row, -1, 1, 1, space, pos))
        {
            posible = true;
        }
    }
    if (posible == false)
    {
        cout << "no posible moves \n";
        return false;
    };
    cout <<"\n";

    //Move King
    char moverowl;
    int moverow;
    int moveslot;
    bool moved;
    cout << "move row a-h: \n";
    cin >> moverowl;
    moverow = moverowl - 97;
    cout << "move row 1-8: \n";
    cin >> moveslot;
    moveslot--;
    if (slot+1 < 8)
    {
        if (move(slot, row, 1, 0, moveslot, moverow, space, pos, piece))
        {
            moved = true;
        }
    }
    if (slot-1 >= 0)
    {
        if (move(slot, row, -1, 0, moveslot, moverow, space, pos, piece))
        {
            moved = true;
        }
    }
    if (row+1 < 8)
    {
        if (move(slot, row, 0, 1, moveslot, moverow, space, pos, piece))
        {
            moved = true;
        }
    }
    if (row-1 >= 0)
    {
        if (move(slot, row, 0, -1, moveslot, moverow, space, pos, piece))
        {
            moved = true;
        }
    }
    if (slot+1 < 8 && row+1 < 8)
    {
        if (move(slot, row, 1, 1, moveslot, moverow, space, pos, piece))
        {
            moved = true;
        }
    }
    if (slot-1 >= 0 && row-1 >= 0)
    {
        if (move(slot, row, -1, -1, moveslot, moverow, space, pos, piece))
        {
            moved = true;
        }
    }
    if (slot+1 < 8 && row-1 >= 0)
    {
        if (move(slot, row, 1, -1, moveslot, moverow, space, pos, piece))
        {
            moved = true;
        }
    }
    if (slot-1 < 8 && row+1 >= 0)
    {
        if (move(slot, row, -1, 1, moveslot, moverow, space, pos, piece))
        {
            moved = true;
        }
    }
    return moved;
}
