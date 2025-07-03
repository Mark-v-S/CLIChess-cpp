#include "moves.h" // header in local directory
#include <iostream> // header in standard library
#include <cstring>

using namespace std;

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
