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

/*
// move.h
#ifndef MOVE_H // include guard
#define MOVE_H

namespace clichess
{
    class moves
    {
    public:
    void test();
    //bool Pawn(char**, int, char, int, char, int, int, bool, char, char*, char, int, int);
    //bool Rock(char**, int, int, char, char*);
    //bool Knight(char**, int, int, char, char*);
    //bool Bishop(char**, int, int, char, char*);
    //bool Quin(char**, int, int, char, char*);
    //bool King(char**, int, int, char, char*);
    };
    class logic
    {
    public:
    bool posiblemoveloop(int, int, int, int, int, char**, char*);
    bool moveloop(int, int, int, int, int, int, char**, char*, char);
    bool posiblemove(int, int, int, int, int, char**, char*);
    bool move(int, int, int, int, int, int, char**, char*, char);
    };
}

#endif MOVE_H
*/
