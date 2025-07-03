#include <iostream>
#include "moves.h"

//using namespace clichess;
using namespace std;

void drawBoard(char** spaces);
void playerMove1(char** space, char*, char*);
void playerMove2(char** space, char*, char*);
bool checkCheck(char *spaces, char player, char player2);
bool checkCheckMate(char *spaces, char player, char player2);

int main()
{
    //moves moves;
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
        /*
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
        */
    } while (moved == false);
}
