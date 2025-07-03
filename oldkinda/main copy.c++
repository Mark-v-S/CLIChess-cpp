#include <algorithm>
#include<iostream>
#include <list>
using namespace std;

void drawBoard(char** spaces);
void playerMove1(char** space);
void playerMove2(char *spaces, char player);
bool checkCheck(char *spaces, char player, char player2);
bool checkCheckMate(char *spaces, char player, char player2);
void movep1(char Piece, int player);
bool Pawn(char**, int, char, int, char, int, int);


int main()
{
  char empty = ' ';
  char charsp1[10] = {'|','+','r','x','*','#',empty};
  char charsp2[10] = {'p','R','k','b','Q','K',empty};
  string name;
    char spaces[8] [8] = {
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
    while (running) {
        playerMove1(space);
        drawBoard(space);
    }

}

enum rowl{
    a = 0,
    b = 1,
    c = 2,
    d = 3,
    e = 4,
    f = 5,
    g = 6,
    h = 7
};

void drawBoard(char** spaces) {
    cout << "    Player1                ";
cout << ' ' << '|' << ' ';
cout << "    Player2                \n";

    cout << "    1  2  3  4  5  6  7  8 ";
cout << ' ' << '|' << ' ';
cout << "    1  2  3  4  5  6  7  8 \n";
    cout << " a \033[1;47m\033[1;30m "<< spaces[0] [0] <<" \033[0m\033[1;40m\033[1;37m "<< spaces[0] [1] <<" \033[0m\033[1;47m\033[1;30m "<< spaces[0] [2] <<" \033[0m\033[1;40m\033[1;37m "<< spaces[0] [3] <<" \033[0m\033[1;47m\033[1;30m "<< spaces[0] [4] <<" \033[0m\033[1;40m\033[1;37m "<< spaces[0] [5] <<" \033[0m\033[1;47m\033[1;30m "<< spaces[0] [6] <<" \033[0m\033[1;40m\033[1;37m "<< spaces[0] [7] <<" \033[0m";
cout << ' ' << '|' << ' ';
cout << " h \033[1;40m\033[1;37m "<< spaces[7] [0] <<" \033[0m\033[1;47m\033[1;30m "<< spaces[7] [1] <<" \033[0m\033[1;40m\033[1;37m "<< spaces[7] [2] <<" \033[0m\033[1;47m\033[1;30m "<< spaces[7] [3] <<" \033[0m\033[1;40m\033[1;37m "<< spaces[7] [4] <<" \033[0m\033[1;47m\033[1;30m "<< spaces[7] [5] <<" \033[0m\033[1;40m\033[1;37m "<< spaces[7] [6] <<" \033[0m\033[1;47m\033[1;30m "<< spaces[7] [7] <<" \033[0m\n";
    cout << " b \033[1;40m\033[1;37m "<< spaces[1] [0] <<" \033[0m\033[1;47m\033[1;30m "<< spaces[1] [1] <<" \033[0m\033[1;40m\033[1;37m "<< spaces[1] [2] <<" \033[0m\033[1;47m\033[1;30m "<< spaces[1] [3] <<" \033[0m\033[1;40m\033[1;37m "<< spaces[1] [4] <<" \033[0m\033[1;47m\033[1;30m "<< spaces[1] [5] <<" \033[0m\033[1;40m\033[1;37m "<< spaces[1] [6] <<" \033[0m\033[1;47m\033[1;30m "<< spaces[1] [7] <<" \033[0m";
cout << ' ' << '|' << ' ';
cout << " g \033[1;47m\033[1;30m "<< spaces[6] [0] <<" \033[0m\033[1;40m\033[1;37m "<< spaces[6] [1] <<" \033[0m\033[1;47m\033[1;30m "<< spaces[6] [2] <<" \033[0m\033[1;40m\033[1;37m "<< spaces[6] [3] <<" \033[0m\033[1;47m\033[1;30m "<< spaces[6] [4] <<" \033[0m\033[1;40m\033[1;37m "<< spaces[6] [5] <<" \033[0m\033[1;47m\033[1;30m "<< spaces[6] [6] <<" \033[0m\033[1;40m\033[1;37m "<< spaces[6] [7] <<" \033[0m\n";
    cout << " c \033[1;47m\033[1;30m "<< spaces[2] [0] <<" \033[0m\033[1;40m\033[1;37m "<< spaces[2] [1] <<" \033[0m\033[1;47m\033[1;30m "<< spaces[2] [2] <<" \033[0m\033[1;40m\033[1;37m "<< spaces[2] [3] <<" \033[0m\033[1;47m\033[1;30m "<< spaces[2] [4] <<" \033[0m\033[1;40m\033[1;37m "<< spaces[2] [5] <<" \033[0m\033[1;47m\033[1;30m "<< spaces[2] [6] <<" \033[0m\033[1;40m\033[1;37m "<< spaces[2] [7] <<" \033[0m";
cout << ' ' << '|' << ' ';
cout << " f \033[1;40m\033[1;37m "<< spaces[5] [0] <<" \033[0m\033[1;47m\033[1;30m "<< spaces[5] [1] <<" \033[0m\033[1;40m\033[1;37m "<< spaces[5] [2] <<" \033[0m\033[1;47m\033[1;30m "<< spaces[5] [3] <<" \033[0m\033[1;40m\033[1;37m "<< spaces[5] [4] <<" \033[0m\033[1;47m\033[1;30m "<< spaces[5] [5] <<" \033[0m\033[1;40m\033[1;37m "<< spaces[5] [6] <<" \033[0m\033[1;47m\033[1;30m "<< spaces[5] [7] <<" \033[0m\n";
    cout << " d \033[1;40m\033[1;37m "<< spaces[3] [0] <<" \033[0m\033[1;47m\033[1;30m "<< spaces[3] [1] <<" \033[0m\033[1;40m\033[1;37m "<< spaces[3] [2] <<" \033[0m\033[1;47m\033[1;30m "<< spaces[3] [3] <<" \033[0m\033[1;40m\033[1;37m "<< spaces[3] [4] <<" \033[0m\033[1;47m\033[1;30m "<< spaces[3] [5] <<" \033[0m\033[1;40m\033[1;37m "<< spaces[3] [6] <<" \033[0m\033[1;47m\033[1;30m "<< spaces[3] [7] <<" \033[0m";
cout << ' ' << '|' << ' ';
cout << " e \033[1;47m\033[1;30m "<< spaces[4] [0] <<" \033[0m\033[1;40m\033[1;37m "<< spaces[4] [1] <<" \033[0m\033[1;47m\033[1;30m "<< spaces[4] [2] <<" \033[0m\033[1;40m\033[1;37m "<< spaces[4] [3] <<" \033[0m\033[1;47m\033[1;30m "<< spaces[4] [4] <<" \033[0m\033[1;40m\033[1;37m "<< spaces[4] [5] <<" \033[0m\033[1;47m\033[1;30m "<< spaces[4] [6] <<" \033[0m\033[1;40m\033[1;37m "<< spaces[4] [7] <<" \033[0m\n";
    cout << " e \033[1;47m\033[1;30m "<< spaces[4] [0] <<" \033[0m\033[1;40m\033[1;37m "<< spaces[4] [1] <<" \033[0m\033[1;47m\033[1;30m "<< spaces[4] [2] <<" \033[0m\033[1;40m\033[1;37m "<< spaces[4] [3] <<" \033[0m\033[1;47m\033[1;30m "<< spaces[4] [4] <<" \033[0m\033[1;40m\033[1;37m "<< spaces[4] [5] <<" \033[0m\033[1;47m\033[1;30m "<< spaces[4] [6] <<" \033[0m\033[1;40m\033[1;37m "<< spaces[4] [7] <<" \033[0m";
cout << ' ' << '|' << ' ';
cout << " d \033[1;40m\033[1;37m "<< spaces[3] [0] <<" \033[0m\033[1;47m\033[1;30m "<< spaces[3] [1] <<" \033[0m\033[1;40m\033[1;37m "<< spaces[3] [2] <<" \033[0m\033[1;47m\033[1;30m "<< spaces[3] [3] <<" \033[0m\033[1;40m\033[1;37m "<< spaces[3] [4] <<" \033[0m\033[1;47m\033[1;30m "<< spaces[3] [5] <<" \033[0m\033[1;40m\033[1;37m "<< spaces[3] [6] <<" \033[0m\033[1;47m\033[1;30m "<< spaces[3] [7] <<" \033[0m\n";
    cout << " f \033[1;40m\033[1;37m "<< spaces[5] [0] <<" \033[0m\033[1;47m\033[1;30m "<< spaces[5] [1] <<" \033[0m\033[1;40m\033[1;37m "<< spaces[5] [2] <<" \033[0m\033[1;47m\033[1;30m "<< spaces[5] [3] <<" \033[0m\033[1;40m\033[1;37m "<< spaces[5] [4] <<" \033[0m\033[1;47m\033[1;30m "<< spaces[5] [5] <<" \033[0m\033[1;40m\033[1;37m "<< spaces[5] [6] <<" \033[0m\033[1;47m\033[1;30m "<< spaces[5] [7] <<" \033[0m";
cout << ' ' << '|' << ' ';
cout << " c \033[1;47m\033[1;30m "<< spaces[2] [0] <<" \033[0m\033[1;40m\033[1;37m "<< spaces[2] [1] <<" \033[0m\033[1;47m\033[1;30m "<< spaces[2] [2] <<" \033[0m\033[1;40m\033[1;37m "<< spaces[2] [3] <<" \033[0m\033[1;47m\033[1;30m "<< spaces[2] [4] <<" \033[0m\033[1;40m\033[1;37m "<< spaces[2] [5] <<" \033[0m\033[1;47m\033[1;30m "<< spaces[2] [6] <<" \033[0m\033[1;40m\033[1;37m "<< spaces[2] [7] <<" \033[0m\n";
    cout << " g \033[1;47m\033[1;30m "<< spaces[6] [0] <<" \033[0m\033[1;40m\033[1;37m "<< spaces[6] [1] <<" \033[0m\033[1;47m\033[1;30m "<< spaces[6] [2] <<" \033[0m\033[1;40m\033[1;37m "<< spaces[6] [3] <<" \033[0m\033[1;47m\033[1;30m "<< spaces[6] [4] <<" \033[0m\033[1;40m\033[1;37m "<< spaces[6] [5] <<" \033[0m\033[1;47m\033[1;30m "<< spaces[6] [6] <<" \033[0m\033[1;40m\033[1;37m "<< spaces[6] [7] <<" \033[0m";
cout << ' ' << '|' << ' ';
cout << " b \033[1;40m\033[1;37m "<< spaces[1] [0] <<" \033[0m\033[1;47m\033[1;30m "<< spaces[1] [1] <<" \033[0m\033[1;40m\033[1;37m "<< spaces[1] [2] <<" \033[0m\033[1;47m\033[1;30m "<< spaces[1] [3] <<" \033[0m\033[1;40m\033[1;37m "<< spaces[1] [4] <<" \033[0m\033[1;47m\033[1;30m "<< spaces[1] [5] <<" \033[0m\033[1;40m\033[1;37m "<< spaces[1] [6] <<" \033[0m\033[1;47m\033[1;30m "<< spaces[1] [7] <<" \033[0m\n";
    cout << " h \033[1;40m\033[1;37m "<< spaces[7] [0] <<" \033[0m\033[1;47m\033[1;30m "<< spaces[7] [1] <<" \033[0m\033[1;40m\033[1;37m "<< spaces[7] [2] <<" \033[0m\033[1;47m\033[1;30m "<< spaces[7] [3] <<" \033[0m\033[1;40m\033[1;37m "<< spaces[7] [4] <<" \033[0m\033[1;47m\033[1;30m "<< spaces[7] [5] <<" \033[0m\033[1;40m\033[1;37m "<< spaces[7] [6] <<" \033[0m\033[1;47m\033[1;30m "<< spaces[7] [7] <<" \033[0m";
cout << ' ' << '|' << ' ';
cout << " a \033[1;47m\033[1;30m "<< spaces[0] [0] <<" \033[0m\033[1;40m\033[1;37m "<< spaces[0] [1] <<" \033[0m\033[1;47m\033[1;30m "<< spaces[0] [2] <<" \033[0m\033[1;40m\033[1;37m "<< spaces[0] [3] <<" \033[0m\033[1;47m\033[1;30m "<< spaces[0] [4] <<" \033[0m\033[1;40m\033[1;37m "<< spaces[0] [5] <<" \033[0m\033[1;47m\033[1;30m "<< spaces[0] [6] <<" \033[0m\033[1;40m\033[1;37m "<< spaces[0] [7] <<" \033[0m\n";
}

void playerMove1(char** space) {
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
            /*
            //Möglichkeiten Pawn
            cout << "posible moves Pawn: \n";
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
                    moved = true;
                };
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
                moved = true;
                };
            }
            */
            moved = Pawn(space, rowi, rowis, slot, moverow, moverowi, moveslot);
            break;
            case '+':
            i = slot;
            cout << "posible Moves Rock: \n";
            //Möglichkeiten Rock
            do
            {
                if(i != slot)
                {
                    i++;
                    rowis = rowi+97;
                    cout << rowis << ',' << i <<'|';
                }
                else
                {
                    i++;
                }
            }while(space[rowi] [i] == ' ' && i <= 8);
            i = slot;
            do
            {
                if(i != slot)
                {
                    rowis = rowi+97;
                    cout << rowis << ',' << i+1 <<'|';
                    i--;
                }
                else
                {
                    i--;
                }
            }while(space[rowi] [i] == ' ' && i >= 0);
            i = rowi;
            do
            {
                if(i != rowi)
                {
                    rowis = i+97;
                    cout << rowis << ',' << slot+1 <<'|';
                    i++;
                }
                else
                {
                    i++;
                }
            }while(space[i] [slot] == ' ' && i <= 8);
            i = rowi;
            do
            {
                if(i != rowi)
                {
                    rowis = i+97;
                    cout << rowis << ',' << slot+1 <<'|';
                    i--;
                }
                else
                {
                    i--;
                }
            }while(space[i] [slot] == ' ' && i >= 0);
            cout <<"\n";

            //Move Rock
            cout << "move row a-h: \n";
            cin >> moverow;
            moverowi = moverow - 97;
            cout << "move row 1-8: \n";
            cin >> moveslot;
            moveslot--;
            i = slot;
            do
            {
                if(i == moveslot && rowi == moverowi)
                {
                    space[rowi] [slot] = ' ';
                    space[moverowi] [moveslot] = '+';
                    moved = true;
                    break;
                }
            i++;
            }while(space[rowi] [i] == ' ' && i <= 8);
            i = slot;
            do
            {
            if(i == moveslot && rowi == moverowi)
                {
                    space[rowi] [slot] = ' ';
                    space[moverowi] [moveslot] = '+';
                    moved = true;
                    break;
                }
            i--;
            }while(space[rowi] [i] == ' ' && i >= 0);
            i = rowi;
            do
            {
                if(slot == moveslot && i == moverowi)
                {
                    space[rowi] [slot] = ' ';
                    space[moverowi] [moveslot] = '+';
                    moved = true;
                    break;
                }
                i++;
            }while(space[i] [slot] == ' ' && i <= 8);
            i = rowi;
            do
            {
                if(slot == moveslot && i == moverowi)
                {
                    space[rowi] [slot] = ' ';
                    space[moverowi] [moveslot] = '+';
                    moved = true;
                    break;
                }
                i--;
            }while(space[i] [slot] == ' ' && i >= 0);

            case 'r':
            cout << "posible moves Knight: \n";
            //möglichkeiten Knight
            if ((rowi-1 > 0 && slot-1 > 0) || (rowi-1 > 0 && slot+3 > 0))
            {
                if (space[rowi-1] [slot-1] == ' ')
                {
                    rowis = rowi+97-1;
                    cout << rowis << ',' << slot-1 << '|';
                }
                if (space[rowi-1] [slot+3] == ' ')
                {
                    rowis = rowi+97-1;
                    cout << rowis << ',' << slot+3 << '|';
                }
            }
            if ((rowi+1 > 0 && slot-1 > 0) || (rowi+1 > 0 && slot+3 > 0))
            {
                if (space[rowi+1] [slot-1] == ' ')
                {
                    rowis = rowi+97+1;
                    cout << rowis << ',' << slot-1 << '|';
                }
                if (space[rowi+1] [slot+3] == ' ')
                {
                    rowis = rowi+97+1;
                    cout << rowis << ',' << slot+3 << '|';
                }
            }
            if ((rowi-2 > 0 && slot-1 > 0) || (rowi-2 > 0 && slot+1 > 0))
            {
                if (space[rowi-2] [slot-1] == ' ')
                {
                    rowis = rowi+97-2;
                    cout << rowis << ',' << slot << '|';
                }
                if (space[rowi-2] [slot+1] == ' ')
                {
                    rowis = rowi+97-2;
                    cout << rowis << ',' << slot+2 << '|';
                }
            }
            if ( (rowi+2 < 9 && slot-1 > 0) || (rowi+2 < 9 && slot < 8))
            {
                if (space[rowi+2] [slot-1] == ' ')
                {
                    rowis = rowi+97+2;
                    cout << rowis << ',' << slot << '|';
                }
                if (space[rowi+2] [slot] == ' ')
                {
                    rowis = rowi+97+2;
                    cout << rowis << ',' << slot+2 << '|';
                }
            }
            cout <<"\n";

            //Move Knight
            cout << "move row a-h: \n";
            cin >> moverow;
            moverowi = moverow - 97;
            cout << "move row 1-8: \n";
            cin >> moveslot;
            moveslot--;
            if (space[rowi-1] [slot-1] == ' ')
            {
                space[rowi] [slot] = ' ';
                space[moverowi] [moveslot] = 'r';
                moved = true;
                break;
            }
            if (space[rowi-1] [slot+2] == ' ')
            {
                space[rowi] [slot] = ' ';
                space[moverowi] [moveslot] = 'r';
                moved = true;
                break;
            }
            if ((space[rowi+1] [slot-2] == ' ') && (rowi+1 == moverowi && slot-2 == moveslot))
            {
                space[rowi] [slot] = ' ';
                space[moverowi] [moveslot] = 'r';
                moved = true;
                break;
            }
            if ((space[rowi+1] [slot+2] == ' ') && (rowi+1 == moverowi && slot+2 == moveslot))
            {
                space[rowi] [slot] = ' ';
                space[moverowi] [moveslot] = 'r';
                moved = true;
                break;
            }
            if ((space[rowi-2] [slot-1] == ' ') && (rowi-2 == moverowi && slot-1 == moveslot))
            {
                space[rowi] [slot] = ' ';
                space[moverowi] [moveslot] = 'r';
                moved = true;
                break;
            }
            if ((space[rowi-2] [slot+1] == ' ') && (rowi-2 == moverowi && slot+1 == moveslot))
            {
                space[rowi] [slot] = ' ';
                space[moverowi] [moveslot] = 'r';
                moved = true;
                break;
            }

            if ((space[rowi+2] [slot-1] == ' ') && (rowi+2 == moverowi && slot-1 == moveslot))
            {
                space[rowi] [slot] = ' ';
                space[moverowi] [moveslot] = 'r';
                moved = true;
                break;
            }
            if ((space[rowi+2] [slot] == ' ') && (rowi+2 == moverowi && slot+1 == moveslot))
            {
                space[rowi] [slot] = ' ';
                space[moverowi] [moveslot] = 'r';
                moved = true;
                break;
            }

            case 'x':
            i = slot;
            j = rowi;
            cout << "posible moves Bishop: \n";
            //Möglichkeiten Bishop
            do
            {
                if(i != slot && j != rowi)
                {
                    rowis = j+97;
                    cout << rowis << ',' << i+1 <<'|';
                    i++;
                    j++;
                }
                else
                {
                    i++;
                    j++;
                }
            }while(space[j] [i] == ' ' && i <= 8 && j <= 8);
            i = slot;
            j = rowi;
            do
            {
                if(i != slot && j != rowi)
                {
                    rowis = j+97;
                    cout << rowis << ',' << i+1 <<'|';
                    i--;
                    j--;
                }
                else
                {
                    i--;
                    j--;
                }
            }while(space[j] [i] == ' ' && i >= 0 && j >= 0);
            i = slot;
            j = rowi;
            do
            {
                if(i != slot && j != rowi)
                {
                    rowis = j+97;
                    cout << rowis << ',' << i+1 <<'|';
                    i++;
                    j--;
                }
                else
                {
                    i++;
                    j--;
                }
            }while(space[j] [i] == ' ' && i <= 8 && j >= 0);
            i = slot;
            j = rowi;
            do
            {
                if(i != slot && j != rowi)
                {
                    rowis = j+97;
                    cout << rowis << ',' << i+1 <<'|';
                    i--;
                    j++;
                }
                else
                {
                    i--;
                    j++;
                }
            }while(space[j] [i] == ' ' && i >= 0 && j <= 8);
            cout <<"\n";

            //Move Bishop
            cout << "move row a-h: \n";
            cin >> moverow;
            moverowi = moverow - 97;
            cout << "move row 1-8: \n";
            cin >> moveslot;
            moveslot--;
            i = slot;
            j = rowi;
            do
            {
                if(i == moveslot && j == moverowi)
                {
                    space[rowi] [slot] = ' ';
                    space[moverowi] [moveslot] = 'x';
                    moved = true;
                    break;
                }
                i++;
                j++;
            }while(space[j] [i] == ' ' && i <= 8 && j <= 8);
            i = slot;
            j = rowi;
            do
            {
                if(i == moveslot && j == moverowi)
                {
                    space[rowi] [slot] = ' ';
                    space[moverowi] [moveslot] = 'x';
                    moved = true;
                    break;
                }
                i--;
                j--;
            }while(space[j] [i] == ' ' && i >= 0 && j >= 0);
            i = slot;
            j = rowi;
            do
            {
                if(i == moveslot && j == moverowi)
                {
                    space[rowi] [slot] = ' ';
                    space[moverowi] [moveslot] = 'x';
                    moved = true;
                    break;
                }
                i++;
                j--;
            }while(space[j] [i] == ' ' && i <= 8 && j >= 0);
            i = slot;
            j = rowi;
            do
            {
                if(i == moveslot && j == moverowi)
                {
                    space[rowi] [slot] = ' ';
                    space[moverowi] [moveslot] = 'x';
                    moved = true;
                    break;
                }
                i--;
                j++;
            }while(space[j] [i] == ' ' && i >= 0 && j <= 8);
            case '*':
            i = slot;
            j = rowi;
            cout << "posible moves Quine: \n";
            //Möglichkeiten Quine
            do
            {
                if(i != slot)
                {
                    i++;
                    rowis = rowi+97;
                    cout << rowis << ',' << i <<'|';
                }
                else
                {
                    i++;
                }
            }while(space[rowi] [i] == ' ' && i <= 8);
            i = slot;
            j = rowi;
            do
            {
                if(i != slot)
                {
                    rowis = rowi+97;
                    cout << rowis << ',' << i+1 <<'|';
                    i--;
                }
                else
                {
                    i--;
                }
            }while(space[rowi] [i] == ' ' && i >= 0);
            i = slot;
            j = rowi;
            do
            {
                if(j != rowi)
                {
                    rowis = j+97;
                    cout << rowis << ',' << slot+1 <<'|';
                    j++;
                }
                else
                {
                    j++;
                }
            }while(space[j] [slot] == ' ' && j <= 8);
            i = slot;
            j = rowi;
            do
            {
                if(j != rowi)
                {
                    rowis = j+97;
                    cout << rowis << ',' << slot+1 <<'|';
                    j--;
                }
                else
                {
                    j--;
                }
            }while(space[j] [slot] == ' ' && j >= 0);
            i = slot;
            j = rowi;
            do
            {
                if(j != slot && j != rowi)
                {
                    rowis = j+97;
                    cout << rowis << ',' << i+1 <<'|';
                    i++;
                    j++;
                }
                else
                {
                    i++;
                    j++;
                }
            }while(space[j] [i] == ' ' && i <= 8 && j <= 8);
            i = slot;
            j = rowi;
            do
            {
                if(i != slot && j != rowi)
                {
                    rowis = j+97;
                    cout << rowis << ',' << i+1 <<'|';
                    i--;
                    j--;
                }
                else
                {
                    i--;
                    j--;
                }
            }while(space[j] [i] == ' ' && i >= 0 && j >= 0);
            i = slot;
            j = rowi;
            do
            {
                if(i != slot && j != rowi)
                {
                    rowis = j+97;
                    cout << rowis << ',' << i+1 <<'|';
                    i++;
                    j--;
                }
                else
                {
                    i++;
                    j--;
                }
            }while(space[j] [i] == ' ' && i <= 8 && j >= 0);
            i = slot;
            j = rowi;
            do
            {
                if(i != slot && j != rowi)
                {
                    rowis = j+97;
                    cout << rowis << ',' << i+1 <<'|';
                    i--;
                    j++;
                }
                else
                {
                    i--;
                    j++;
                }
            }while(space[j] [i] == ' ' && i >= 0 && j <= 8);
            cout <<"\n";

            //Move Quine
            cout << "move row a-h: \n";
            cin >> moverow;
            moverowi = moverow - 97;
            cout << "move row 1-8: \n";
            cin >> moveslot;
            moveslot--;
            i = slot;
            j = rowi;
            do
            {
                if(i == moveslot && rowi == moverowi)
                {
                    space[rowi] [slot] = ' ';
                    space[moverowi] [moveslot] = '*';
                    moved = true;
                    break;
                }
            i++;
            }while(space[rowi] [i] == ' ' && i <= 8);
            i = slot;
            do
            {
                if(i == moveslot && rowi == moverowi)
                {
                    space[rowi] [slot] = ' ';
                    space[moverowi] [moveslot] = '*';
                    moved = true;
                    break;
                }
            i--;
            }while(space[rowi] [i] == ' ' && i >= 0);
            j = rowi;
            do
            {
                if(slot == moveslot && j == moverowi)
                {
                    space[rowi] [slot] = ' ';
                    space[moverowi] [moveslot] = '*';
                    moved = true;
                    break;
                }
                j++;
            }while(space[j] [slot] == ' ' && j <= 8);
            j = rowi;
            do
            {
                if(slot == moveslot && j == moverowi)
                {
                    space[rowi] [slot] = ' ';
                    space[moverowi] [moveslot] = '*';
                    moved = true;
                    break;
                }
                j--;
            }while(space[j] [slot] == ' ' && j >= 0);
            i = slot;
            j = rowi;
            do
            {
                if(i == moveslot && j == moverowi)
                {
                    space[rowi] [slot] = ' ';
                    space[moverowi] [moveslot] = '*';
                    moved = true;
                    break;
                }
                i++;
                j++;
            }while(space[j] [i] == ' ' && i <= 8 && j <= 8);
            i = slot;
            j = rowi;
            do
            {
                if(i == moveslot && j == moverowi)
                {
                    space[rowi] [slot] = ' ';
                    space[moverowi] [moveslot] = '*';
                    moved = true;
                    break;
                }
                i--;
                j--;
            }while(space[j] [i] == ' ' && i >= 0 && j >= 0);
            i = slot;
            j = rowi;
            do
            {
                if(i == moveslot && j == moverowi)
                {
                    space[rowi] [slot] = ' ';
                    space[moverowi] [moveslot] = '*';
                    moved = true;
                    break;
                }
                i++;
                j--;
            }while(space[j] [i] == ' ' && i <= 8 && j >= 0);
            i = slot;
            j = rowi;
            do
            {
                if(i == moveslot && j == moverowi)
                {
                    space[rowi] [slot] = ' ';
                    space[moverowi] [moveslot] = '*';
                    moved = true;
                    break;
                }
                i--;
                j++;
            }while(space[j] [i] == ' ' && i >= 0 && j <= 8);
            break;


            case '#':
            cout << "posible: moves King \n";
            //möglichkeiten King
            if (space[rowi] [slot+1] == ' ')
            {
                rowis = rowi+97;
                cout << rowis << ',' << slot+2 << '|';
            }
            if (space[rowi] [slot-1] == ' ')
            {
                rowis = rowi+97;
                cout << rowis << ',' << slot << '|';
            }
            if (space[rowi+1] [slot] == ' ')
            {
                rowis = rowi+97+1;
                cout << rowis << ',' << slot+1 << '|';
            }
            if (space[rowi-1] [slot] == ' ')
            {
                rowis = rowi+97-1;
                cout << rowis << ',' << slot+1 << '|';
            }
            if (space[rowi+1] [slot+1] == ' ')
            {
                rowis = rowi+97+1;
                cout << rowis << ',' << slot+2 << '|';
            }
            if (space[rowi-1] [slot-1] == ' ')
            {
                rowis = rowi+97-1;
                cout << rowis << ',' << slot << '|';
            }
            if (space[rowi+1] [slot-1] == ' ')
            {
                rowis = rowi+97+1;
                cout << rowis << ',' << slot << '|';
            }
            if (space[rowi-1] [slot+1] == ' ')
            {
                rowis = rowi+97-1;
                cout << rowis << ',' << slot+2 << '|';
            }
            cout <<"\n";

            //Move King
            cout << "move row a-h: \n";
            cin >> moverow;
            moverowi = moverow - 97;
            cout << "move row 1-8: \n";
            cin >> moveslot;
            moveslot--;
            if ((space[rowi] [slot+1] == ' ') && (rowi == moverowi && slot+1 == moveslot))
            {
                space[rowi] [slot] = ' ';
                space[moverowi] [moveslot] = '#';
                moved = true;
                break;
            }
            if ((space[rowi] [slot-1] == ' ') && (rowi == moverowi && slot-1 == moveslot))
            {
                space[rowi] [slot] = ' ';
                space[moverowi] [moveslot] = '#';
                moved = true;
                break;
            }
            if ((space[rowi+1] [slot] == ' ') && (rowi+1 == moverowi && slot == moveslot))
            {
                space[rowi] [slot] = ' ';
                space[moverowi] [moveslot] = '#';
                moved = true;
                break;
            }
            if ((space[rowi-1] [slot] == ' ') && (rowi-1 == moverowi && slot == moveslot))
            {
                space[rowi] [slot] = ' ';
                space[moverowi] [moveslot] = '#';
                moved = true;
                break;
            }
            if ((space[rowi+1] [slot+1] == ' ') && (rowi+1 == moverowi && slot+1 == moveslot))
            {
                space[rowi] [slot] = ' ';
                space[moverowi] [moveslot] = '#';
                moved = true;
                break;
            }
            if ((space[rowi-1] [slot-1] == ' ') && (rowi-1 == moverowi && slot-1 == moveslot))
            {
                space[rowi] [slot] = ' ';
                space[moverowi] [moveslot] = '#';
                moved = true;
                break;
            }
            if ((space[rowi+1] [slot-1] == ' ') && (rowi+1 == moverowi && slot-1 == moveslot))
            {
                space[rowi] [slot] = ' ';
                space[moverowi] [moveslot] = '#';
                moved = true;
                break;
            }
            if ((space[rowi-1] [slot+1] == ' ') && (rowi-1 == moverowi && slot+1 == moveslot))
            {
                space[rowi] [slot] = ' ';
                space[moverowi] [moveslot] = '#';
                moved = true;
                break;
            }
        }
    } while (moved == false);
}






bool Pawn(char** space, int rowi, char rowis, int slot, char moverow, int moverowi, int moveslot)
{
    //Möglichkeiten Pawn
    cout << "posible moves Pawn \n";
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
        }
        else
        {
            return false;
        }
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
        }
        else
        {
            return false;
        }
    }
}





/*
cout<< "testostooooo"<< rowi+2 << "," << slot << "\n";
if (space[rowi+2] [slot] == ' ' && rowi+2 < 104 && slot > 0)
{
    rowis = rowi+97+2;
    cout << rowis << ',' << slot << '|';
    cout << "test r7 \n";
}
cout<< "testostooooo2" << rowi+2 << "," << slot+1 << "\n";
if (space[rowi+2] [slot+1] == ' ' && rowi+2 < 104 && slot+1 < 8)
{
    rowis = rowi+97+2;
    cout << rowis << ',' << slot+2 << '|';
    cout << "test r8 \n";
}
if (space[rowi-2] [slot-1] == ' ' && rowi-2 > 0 && slot > 0)
{
    rowis = rowi+97-2;
    cout << rowis << ',' << slot << '|';
    cout << "test r5 \n";
}
if (space[rowi-2] [slot+1] == ' ' && rowi-2 > 0 && slot+1 > 0)
{
    rowis = rowi+97-2;
    cout << rowis << ',' << slot+2 << '|';
    cout << "test r6 \n";
}
if (space[rowi+1] [slot-2] == ' ' && rowi+1 > 0 && slot-2 > 0)
{
    rowis = rowi+97+1;
    cout << rowis << ',' << slot-1 << '|';
    cout << "test r3 \n";
}
if (space[rowi+1] [slot+2] == ' ' && rowi+1 > 0 && slot+2 > 0)
{
    rowis = rowi+97+1;
    cout << rowis << ',' << slot+3 << '|';
    cout << "test r4 \n";
}
if ((space[rowi-1] [slot-2] == ' ' && rowi-1 > 0 && slot-2 > 0) || (space[rowi-1] [slot+2] == ' ' && rowi-1 > 0 && slot+2 > 0))
{
    rowis = rowi+97-1;
    cout << rowis << ',' << slot-1 << '|';
    cout << "test r1 \n";
}
if (space[rowi-1] [slot-2] == ' ' && rowi-1 > 0 && slot-2 > 0)
{
    rowis = rowi+97-1;
    cout << rowis << ',' << slot-1 << '|';
    cout << "test r1 \n";
}
if (space[rowi-1] [slot+2] == ' ' && rowi-1 > 0 && slot+2 > 0)
{
    rowis = rowi+97-1;
    cout << rowis << ',' << slot+3 << '|';
    cout << "test r2 \n";
}



if ((rowi-1 == moverowi && slot-2 == moveslot) || (rowi-1 == moverowi && slot+2 == moveslot))
{
    if (space[rowi-1] [slot-1] == ' ')
    {
        space[rowi] [slot] = ' ';
        space[moverowi] [moveslot] = 'r';
        moved = true;
        cout << "moved r 1";
        break;
    }
    if (space[rowi-1] [slot+2] == ' ')
    {
        space[rowi] [slot] = ' ';
        space[moverowi] [moveslot] = 'r';
        moved = true;
        cout << "moved r 2";
        break;
    }
}

if ((rowi+1 == moverowi && slot-1 == moveslot) || (rowi+1 == moverowi && slot+3 == moveslot))
{
    if ((space[rowi+1] [slot-2] == ' ') && (rowi+1 == moverowi && slot-2 == moveslot))
    {
        space[rowi] [slot] = ' ';
        space[moverowi] [moveslot] = 'r';
        moved = true;
        cout << "moved r 3";
        break;
    }
    if ((space[rowi+1] [slot+2] == ' ') && (rowi+1 == moverowi && slot+2 == moveslot))
    {
        space[rowi] [slot] = ' ';
        space[moverowi] [moveslot] = 'r';
        moved = true;
        cout << "moved r 4";
        break;
    }
}
if ((rowi-2 == moverowi && slot-1 == moveslot) || (rowi-2 == moverowi && slot+1 == moveslot))
{
    if ((space[rowi-2] [slot-1] == ' ') && (rowi-2 == moverowi && slot-1 == moveslot))
    {
        space[rowi] [slot] = ' ';
        space[moverowi] [moveslot] = 'r';
        moved = true;
        cout << "moved r 5"; //geht
        break;
    }
    if ((space[rowi-2] [slot+1] == ' ') && (rowi-2 == moverowi && slot+1 == moveslot))
    {
        space[rowi] [slot] = ' ';
        space[moverowi] [moveslot] = 'r';
        moved = true;
        cout << "moved r 6"; //geht
        break;
    }
}
if ((rowi+2 == moverowi && slot-1 == moveslot) || (rowi+2 == moverowi && slot+1 == moveslot))
{
    if ((space[rowi+2] [slot-1] == ' ') && (rowi+2 == moverowi && slot-1 == moveslot))
    {
        space[rowi] [slot] = ' ';
        space[moverowi] [moveslot] = 'r';
        moved = true;
        cout << "moved 7"; //geht
        break;
    }
    if ((space[rowi+2] [slot] == ' ') && (rowi+2 == moverowi && slot+1 == moveslot))
    {
        space[rowi] [slot] = ' ';
        space[moverowi] [moveslot] = 'r';
        moved = true;
        cout << "moved r 8"; //geht
        break;
    }
}
*/
