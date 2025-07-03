#include <cstring>
#include<iostream>
using namespace std;

void drawBoard(char** spaces);
void playerMove1(char** space, char*, char*);
void playerMove2(char** space, char*, char*);
bool checkCheck(char *spaces, char player, char player2);
bool checkCheckMate(char *spaces, char player, char player2);
bool Pawn(char**, int, char, int, char, int, int, bool, char, char*, char, int, int);
bool Rock(char**, int, int, char, char*);
bool Knight(char**, int, int, char, char*);
bool Bishop(char**, int, int, char, char*);
bool Quin(char**, int, int, char, char*);
bool King(char**, int, int, char, char*);
bool posiblemoveloop(int, int, int, int, int, char**, char*);
bool moveloop(int, int, int, int, int, int, char**, char*, char);
bool posiblemove(int, int, int, int, int, char**, char*);
bool move(int, int, int, int, int, int, char**, char*, char);


int main()
{
    char empty = ' ';
    char charsp1[7] = {'|','+','r','x','*','#',empty};
    char charsp2[7] = {'p','R','k','b','Q','K',empty};
    char spaces[8] [8] =
    {
        {charsp2[1], charsp2[2], charsp2[3], charsp2[4], charsp2[5], charsp2[3], charsp2[2], charsp2[1]},
        {charsp2[0], charsp2[0], charsp2[0], charsp2[0], charsp2[0], charsp2[0], charsp2[0], charsp2[0]},
        {empty , empty, empty, empty, empty, empty, empty, empty},
        {empty , empty, empty, empty, empty, empty, empty, empty},
        {empty , empty, empty, empty, empty, empty, empty, empty},
        {empty , empty, empty, empty, empty, empty, empty, empty},
        {charsp1[0], charsp1[0], charsp1[0], charsp1[0], charsp1[0], charsp1[0], charsp1[0], charsp1[0]},
        {charsp1[1], charsp1[2], charsp1[3], charsp1[4], charsp1[5], charsp1[3], charsp1[2], charsp1[1]}
    };
    char* space[]= { spaces[0],
        spaces[1],
        spaces[2],
        spaces[3],
        spaces[4],
        spaces[5],
        spaces[6],
        spaces[7],};
    drawBoard(space);
    bool running = true;
    while (running)
    {
        playerMove1(space, charsp1, charsp2);
        drawBoard(space);
        //playerMove2(space, charsp2, charsp1);
        //drawBoard(space);
    }
}

void drawBoard(char** spaces)
{
    string dark = " \033[0m\033[1;40m\033[1;37m ";
    string light = " \033[0m\033[1;47m\033[1;30m ";

    cout << "    Player1                ";
cout << ' ' << '|' << ' ';
cout << "    Player2                \n";
    cout << "    1  2  3  4  5  6  7  8 ";
cout << ' ' << '|' << ' ';
cout << "    8  7  6  5  4  3  2  1 \n";
    cout << " a"<< light << spaces[0] [0] << dark << spaces[0] [1] << light << spaces[0] [2] << dark << spaces[0] [3] << light << spaces[0] [4] << dark << spaces[0] [5] << light << spaces[0] [6] << dark << spaces[0] [7] ;
cout << " \033[0m " << '|' << ' ';
cout << " h" << dark << spaces[7] [7] << light << spaces[7] [6] << dark << spaces[7] [5] << light << spaces[7] [4] << dark << spaces[7] [3] << light << spaces[7] [2] << dark << spaces[7] [1] << light << spaces[7] [0] <<" \033[0m\n";
    cout << " b" << dark << spaces[1] [0] << light << spaces[1] [1] << dark << spaces[1] [2] << light << spaces[1] [3] << dark << spaces[1] [4] << light << spaces[1] [5] << dark << spaces[1] [6] << light << spaces[1] [7] ;
cout << " \033[0m " << '|' << ' ';
cout << " g" << light << spaces[6] [7] << dark << spaces[6] [6] << light << spaces[6] [5] << dark << spaces[6] [4] << light << spaces[6] [3] << dark << spaces[6] [2] << light << spaces[6] [1] << dark << spaces[6] [0] <<" \033[0m\n";
    cout << " c" << light << spaces[2] [0] << dark << spaces[2] [1] << light << spaces[2] [2] << dark << spaces[2] [3] << light << spaces[2] [4] << dark << spaces[2] [5] << light << spaces[2] [6] << dark << spaces[2] [7] ;
cout << " \033[0m " << '|' << ' ';
cout << " f" << dark << spaces[5] [7] << light << spaces[5] [6] << dark << spaces[5] [5] << light << spaces[5] [4] << dark << spaces[5] [3] << light << spaces[5] [2] << dark << spaces[5] [1] << light << spaces[5] [0] <<" \033[0m\n";
    cout << " d" << dark << spaces[3] [0] << light << spaces[3] [1] << dark << spaces[3] [2] << light << spaces[3] [3] << dark << spaces[3] [4] << light << spaces[3] [5] << dark << spaces[3] [6] << light << spaces[3] [7] ;
cout << " \033[0m " << '|' << ' ';
cout << " e" << light << spaces[4] [7] << dark << spaces[4] [6] << light << spaces[4] [5] << dark << spaces[4] [4] << light << spaces[4] [3] << dark << spaces[4] [2] << light << spaces[4] [1] << dark << spaces[4] [0] <<" \033[0m\n";
    cout << " e" << light << spaces[4] [0] << dark << spaces[4] [1] << light << spaces[4] [2] << dark << spaces[4] [3] << light << spaces[4] [4] << dark << spaces[4] [5] << light << spaces[4] [6] << dark << spaces[4] [7] ;
cout << " \033[0m " << '|' << ' ';
cout << " d" << dark << spaces[3] [7] << light << spaces[3] [6] << dark << spaces[3] [5] << light << spaces[3] [4] << dark << spaces[3] [3] << light << spaces[3] [2] << dark << spaces[3] [1] << light << spaces[3] [0] <<" \033[0m\n";
    cout << " f" << dark << spaces[5] [0] << light << spaces[5] [1] << dark << spaces[5] [2] << light << spaces[5] [3] << dark << spaces[5] [4] << light << spaces[5] [5] << dark << spaces[5] [6] << light << spaces[5] [7] ;
cout << " \033[0m " << '|' << ' ';
cout << " c" << light << spaces[2] [7] << dark << spaces[2] [6] << light << spaces[2] [5] << dark << spaces[2] [4] << light << spaces[2] [3] << dark << spaces[2] [2] << light << spaces[2] [1] << dark << spaces[2] [0] <<" \033[0m\n";
    cout << " g" << light << spaces[6] [0] << dark << spaces[6] [1] << light << spaces[6] [2] << dark << spaces[6] [3] << light << spaces[6] [4] << dark << spaces[6] [5] << light << spaces[6] [6] << dark << spaces[6] [7] ;
cout << " \033[0m " << '|' << ' ';
cout << " b" << dark << spaces[1] [7] << light << spaces[1] [6] << dark << spaces[1] [5] << light << spaces[1] [4] << dark << spaces[1] [3] << light << spaces[1] [2] << dark << spaces[1] [1] << light << spaces[1] [0] <<" \033[0m\n";
    cout << " h" << dark << spaces[7] [0] << light << spaces[7] [1] << dark << spaces[7] [2] << light << spaces[7] [3] << dark << spaces[7] [4] << light << spaces[7] [5] << dark << spaces[7] [6] << light << spaces[7] [7] ;
cout << " \033[0m " << '|' << ' ';
cout << " a" << light << spaces[0] [7] << dark << spaces[0] [6] << light << spaces[0] [5] << dark << spaces[0] [4] << light << spaces[0] [3] << dark << spaces[0] [2] << light << spaces[0] [1] << dark << spaces[0] [0] <<" \033[0m\n";
}

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
    char charsply[7] = {'|','+','r','x','*','#',' '};
    bool moved = false;
    int i;
    int j;
    char row;
    //int rowi;
    char rowis;
    int slot;
    char moverow;
    //int moverowi;
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
            moved = Pawn(space, row, rowis, slot, moverow, moverow, moveslot, moved, charsp[0], charsply, charsp[6], 1, 1);
            break;
            case 'R':
            moved = Rock(space, row, slot, charsp[1], charsply);
            break;
            case 'k':
            moved = Knight(space, row, slot, charsp[2], charsply);
            break;
            case 'b':
            moved = Bishop(space, row, slot, charsp[3], charsply);
            break;
            case 'Q':
            moved = Quin(space, row, slot, charsp[4], charsply);
            break;
            case 'K':
            moved = King(space, row, slot, charsp[1], charsply);
            break;
        }
    } while (moved == false);
}






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




bool posiblemoveloop(int slot, int row, int diri, int dirj, int mi, char** space, char* posible)
{
    bool testet = false;
    int i = slot;
    int j = row;
    do
    {
        if(i != slot || j != row)
        {
            if (memchr(posible, space[j] [i], strlen(posible)) == NULL)
            {
                break;
            }
            else if ((memchr(posible, space[j] [i], strlen(posible)) != NULL && space[j] [i] != ' '))
            {
                char rowl = j+97;
                cout << rowl << ',' << i+mi;
                testet = true;
                break;
            }
            else if (memchr(posible, space[j] [i], strlen(posible)) != NULL)
            {
                char rowl = j+97;
                cout << rowl << ',' << i+mi << '|';
                testet = true;
                i = i+diri;
                j = j+dirj;
            }
            else
            {
                i = i+diri;
                j = j+dirj;
            }
        }
        else
        {
            i = i+diri;
            j = j+dirj;
        }
    }while(((i-(7*diri) != 8 && (j-(7*dirj) != 8)) || ((j-(7*dirj) != 0) || (i-(7*diri) != 0))) && i >= 0 && i <= 7);
    return testet;
}

bool moveloop(int slot, int row, int diri, int dirj, int moveslot, int moverow, char** space, char* posible, char piece)
{
    bool moved = false;
    int i = slot;
    int j = row;
    do
    {
        if((i == moveslot && j == moverow))
        {
            space[row] [slot] = ' ';
            space[moverow] [moveslot] = piece;
            moved = true;
            break;
        }
        else if ((j == 7 && dirj > 0) || (i == 7 && diri > 0) || (j == 0 && dirj < 0) || (i == 0 && diri < 0))
        {
            break;
        }
        else
        {
            i = i+diri;
            j = j+dirj;
        }
    }while(memchr(posible, space[j] [i], strlen(posible)) != NULL);
    return moved;
}

bool posiblemove(int slot, int row, int diri, int dirj, int mi, char** space, char* posible)
{
    bool testet = false;
    char rowl;
    int i = slot;
    int j = row;
    if (memchr(posible, space[j+dirj] [i+diri], strlen(posible)) != NULL)
        {
            rowl = j+97+dirj;
            cout << rowl << ',' << slot+diri+mi << '|' << '\n';
            testet = true;
        }
    return testet;
}

bool move(int slot, int row, int diri, int dirj, int moveslot, int moverow, char** space, char* posible, char piece)
{
    bool moved = false;
    int i = slot;
    int j = row;
    if ((memchr(posible, space[j+dirj] [i+diri], strlen(posible)) != NULL || space[j+dirj] [i+diri] == ' ') && j+dirj == moverow && i+diri == moveslot)
        {
            space[row] [slot] = ' ';
            space[moverow] [moveslot] = piece;
            moved = true;
        }
    return moved;
}
