#include <iostream>
#include "moves.h"
#include "conf.c++"

using namespace std;

/*
void drawBoard(char** spaces)
{
    cout << "    Player1                ";
        cout << ' ' << '|' << ' ';
        cout << "    Player2                \n";
    cout << "    a  b  c  d  e  f  g  h ";
        cout << ' ' << '|' << ' ';
        cout << "    h  g  f  e  d  c  b  a \n";
    cout << " 1"
    << light << spaces[7] [0]
    << dark << spaces[6] [0]
    << light << spaces[5] [0]
    << dark << spaces[4] [0]
    << light << spaces[3] [0]
    << dark << spaces[2] [0]
    << light << spaces[1] [0]
    << dark << spaces[0] [0];
        cout << " \033[0m " << '|' << ' ';
        cout << " 8"
        << light << spaces[0] [7]
        << dark << spaces[1] [7]
        << light << spaces[2] [7]
        << dark << spaces[3] [7]
        << light << spaces[4] [7]
        << dark << spaces[5] [7]
        << light << spaces[6] [7]
        << dark << spaces[7] [7]
        <<" \033[0m\n";
    cout << " 2"
    << dark << spaces[0] [1]
    << light << spaces[1] [1]
    << dark << spaces[2] [1]
    << light << spaces[3] [1]
    << dark << spaces[4] [1]
    << light << spaces[5] [1]
    << dark << spaces[6] [1]
    << light << spaces[7] [1] ;
        cout << " \033[0m " << '|' << ' ';
        cout << " 7"
        << dark << spaces[7] [6]
        << light << spaces[6] [6]
        << dark << spaces[5] [6]
        << light << spaces[4] [6]
        << dark << spaces[3] [6]
        << light << spaces[2] [6]
        << dark << spaces[1] [6]
        << light << spaces[0] [6]
        <<" \033[0m\n";
        cout << " 3"
        << light << spaces[7] [2]
        << dark << spaces[6] [2]
        << light << spaces[5] [2]
        << dark << spaces[4] [2]
        << light << spaces[3] [2]
        << dark << spaces[2] [2]
        << light << spaces[1] [2]
        << dark << spaces[0] [2];
        cout << " \033[0m " << '|' << ' ';
        cout << " 6"
        << light << spaces[7] [5]
        << dark << spaces[6] [5]
        << light << spaces[5] [5]
        << dark << spaces[4] [5]
        << light << spaces[3] [5]
        << dark << spaces[2] [5]
        << light << spaces[1] [5]
        << dark << spaces[0] [5] <<" \033[0m\n";
    cout << " 4"
    << dark << spaces[0] [3]
    << light << spaces[1] [3]
    << dark << spaces[2] [3]
    << light << spaces[3] [3]
    << dark << spaces[4] [3]
    << light << spaces[5] [3]
    << dark << spaces[6] [3]
    << light << spaces[7] [3] ;
        cout << " \033[0m " << '|' << ' ';
        cout << " 5"
        << dark << spaces[7] [4]
        << light << spaces[6] [4]
        << dark << spaces[5] [4]
        << light << spaces[4] [4]
        << dark << spaces[3] [4]
        << light << spaces[2] [4]
        << dark << spaces[1] [4]
        << light << spaces[0] [4] <<" \033[0m\n";
    cout << " 5"
    << light << spaces[0] [4]
    << dark << spaces[1] [4]
    << light << spaces[2] [4]
    << dark << spaces[3] [4]
    << light << spaces[4] [4]
    << dark << spaces[5] [4]
    << light << spaces[6] [4]
    << dark << spaces[7] [4] ;
        cout << " \033[0m " << '|' << ' ';
        cout << " 4"
        << light << spaces[7] [3]
        << dark << spaces[6] [3]
        << light << spaces[5] [3]
        << dark << spaces[4] [3]
        << light << spaces[3] [3]
        << dark << spaces[2] [3]
        << light << spaces[1] [3]
        << dark << spaces[0] [3] <<" \033[0m\n";
    cout << " 6"
    << dark << spaces[0] [5]
    << light << spaces[1] [5]
    << dark << spaces[2] [5]
    << light << spaces[3] [5]
    << dark << spaces[4] [5]
    << light << spaces[5] [5]
    << dark << spaces[6] [5]
    << light << spaces[7] [5] ;
        cout << " \033[0m " << '|' << ' ';
        cout << " 3"
        << dark << spaces[7] [2]
        << light << spaces[6] [2]
        << dark << spaces[5] [2]
        << light << spaces[4] [2]
        << dark << spaces[3] [2]
        << light << spaces[2] [2]
        << dark << spaces[1] [2]
        << light << spaces[0] [2]
        <<" \033[0m\n";
        cout << " 7"
        << light << spaces[0] [6]
        << dark << spaces[1] [6]
        << light << spaces[2] [6]
        << dark << spaces[3] [6]
        << light << spaces[4] [6]
        << dark << spaces[5] [6]
        << light << spaces[6] [6]
        << dark << spaces[7] [6];
        cout << " \033[0m " << '|' << ' ';
        cout << " 2"
        << light << spaces[7] [1]
        << dark << spaces[6] [1]
        << light << spaces[5] [1]
        << dark << spaces[4] [1]
        << light << spaces[3] [1]
        << dark << spaces[2] [1]
        << light << spaces[1] [1]
        << dark << spaces[0] [1]
        <<" \033[0m\n";
    cout << " 8"
    << dark << spaces[7] [7]
    << light << spaces[6] [7]
    << dark << spaces[5] [7]
    << light << spaces[4] [7]
    << dark << spaces[3] [7]
    << light << spaces[2] [7]
    << dark << spaces[1] [7]
    << light << spaces[0] [7];
        cout << " \033[0m " << '|' << ' ';
        cout << " 1"
        << dark << spaces[0] [0]
        << light << spaces[1] [0]
        << dark << spaces[2] [0]
        << light << spaces[3] [0]
        << dark << spaces[4] [0]
        << light << spaces[5] [0]
        << dark << spaces[6] [0]
        << light << spaces[7] [0]
        <<" \033[0m\n";
}
*/



void drawBoard(char** spaces)
{
    cout << "    Player1                ";
        cout << ' ' << '|' << ' ';
        cout << "    Player2                \n";
    cout << "    1  2  3  4  5  6  7  8 ";
        cout << ' ' << '|' << ' ';
        cout << "    8  7  6  5  4  3  2  1 \n";
    cout << " a"
    << light << spaces[0] [0]
    << dark << spaces[0] [1]
    << light << spaces[0] [2]
    << dark << spaces[0] [3]
    << light << spaces[0] [4]
    << dark << spaces[0] [5]
    << light << spaces[0] [6]
    << dark << spaces[0] [7] ;
        cout << " \033[0m " << '|' << ' ';
        cout << " h"
        << dark << spaces[7] [7]
        << light << spaces[7] [6]
        << dark << spaces[7] [5]
        << light << spaces[7] [4]
        << dark << spaces[7] [3]
        << light << spaces[7] [2]
        << dark << spaces[7] [1]
        << light << spaces[7] [0] <<" \033[0m\n";
    cout << " b"
    << dark << spaces[1] [0]
    << light << spaces[1] [1]
    << dark << spaces[1] [2]
    << light << spaces[1] [3]
    << dark << spaces[1] [4]
    << light << spaces[1] [5]
    << dark << spaces[1] [6]
    << light << spaces[1] [7] ;
        cout << " \033[0m " << '|' << ' ';
        cout << " g"
        << light << spaces[6] [7]
        << dark << spaces[6] [6]
        << light << spaces[6] [5]
        << dark << spaces[6] [4]
        << light << spaces[6] [3]
        << dark << spaces[6] [2]
        << light << spaces[6] [1]
        << dark << spaces[6] [0] <<" \033[0m\n";
    cout << " c"
    << light << spaces[2] [0]
    << dark << spaces[2] [1]
    << light << spaces[2] [2]
    << dark << spaces[2] [3]
    << light << spaces[2] [4]
    << dark << spaces[2] [5]
    << light << spaces[2] [6]
    << dark << spaces[2] [7] ;
        cout << " \033[0m " << '|' << ' ';
        cout << " f"
        << dark << spaces[5] [7]
        << light << spaces[5] [6]
        << dark << spaces[5] [5]
        << light << spaces[5] [4]
        << dark << spaces[5] [3]
        << light << spaces[5] [2]
        << dark << spaces[5] [1]
        << light << spaces[5] [0] <<" \033[0m\n";
    cout << " d"
    << dark << spaces[3] [0]
    << light << spaces[3] [1]
    << dark << spaces[3] [2]
    << light << spaces[3] [3]
    << dark << spaces[3] [4]
    << light << spaces[3] [5]
    << dark << spaces[3] [6]
    << light << spaces[3] [7] ;
        cout << " \033[0m " << '|' << ' ';
        cout << " e"
        << light << spaces[4] [7]
        << dark << spaces[4] [6]
        << light << spaces[4] [5]
        << dark << spaces[4] [4]
        << light << spaces[4] [3]
        << dark << spaces[4] [2]
        << light << spaces[4] [1]
        << dark << spaces[4] [0] <<" \033[0m\n";
    cout << " e"
    << light << spaces[4] [0]
    << dark << spaces[4] [1]
    << light << spaces[4] [2]
    << dark << spaces[4] [3]
    << light << spaces[4] [4]
    << dark << spaces[4] [5]
    << light << spaces[4] [6]
    << dark << spaces[4] [7] ;
        cout << " \033[0m " << '|' << ' ';
        cout << " d"
        << dark << spaces[3] [7]
        << light << spaces[3] [6]
        << dark << spaces[3] [5]
        << light << spaces[3] [4]
        << dark << spaces[3] [3]
        << light << spaces[3] [2]
        << dark << spaces[3] [1]
        << light << spaces[3] [0] <<" \033[0m\n";
    cout << " f"
    << dark << spaces[5] [0]
    << light << spaces[5] [1]
    << dark << spaces[5] [2]
    << light << spaces[5] [3]
    << dark << spaces[5] [4]
    << light << spaces[5] [5]
    << dark << spaces[5] [6]
    << light << spaces[5] [7] ;
        cout << " \033[0m " << '|' << ' ';
        cout << " c"
        << light << spaces[2] [7]
        << dark << spaces[2] [6]
        << light << spaces[2] [5]
        << dark << spaces[2] [4]
        << light << spaces[2] [3]
        << dark << spaces[2] [2]
        << light << spaces[2] [1]
        << dark << spaces[2] [0] <<" \033[0m\n";
    cout << " g"
    << light << spaces[6] [0]
    << dark << spaces[6] [1]
    << light << spaces[6] [2]
    << dark << spaces[6] [3]
    << light << spaces[6] [4]
    << dark << spaces[6] [5]
    << light << spaces[6] [6]
    << dark << spaces[6] [7] ;
        cout << " \033[0m " << '|' << ' ';
        cout << " b"
        << dark << spaces[1] [7]
        << light << spaces[1] [6]
        << dark << spaces[1] [5]
        << light << spaces[1] [4]
        << dark << spaces[1] [3]
        << light << spaces[1] [2]
        << dark << spaces[1] [1]
        << light << spaces[1] [0] <<" \033[0m\n";
    cout << " h"
    << dark << spaces[7] [0]
    << light << spaces[7] [1]
    << dark << spaces[7] [2]
    << light << spaces[7] [3]
    << dark << spaces[7] [4]
    << light << spaces[7] [5]
    << dark << spaces[7] [6]
    << light << spaces[7] [7] ;
        cout << " \033[0m " << '|' << ' ';
        cout << " a"
        << light << spaces[0] [7]
        << dark << spaces[0] [6]
        << light << spaces[0] [5]
        << dark << spaces[0] [4]
        << light << spaces[0] [3]
        << dark << spaces[0] [2]
        << light << spaces[0] [1]
        << dark << spaces[0] [0] <<" \033[0m\n";
}
