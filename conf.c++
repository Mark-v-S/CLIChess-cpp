#include <iostream>


static char empty = ' ';
static char charsp1[7] = {'|','+','r','x','*','#',empty};
static int eins = 1;
static char charsp2[7] = {'p','R','k','b','Q','K',empty};

/*
static char spaces[8] [8] =
{
    {chars[1][1], chars[1][0],empty ,empty ,empty ,empty ,chars[0][0] ,chars[0][1] },
    {chars[1][2], chars[1][0],empty ,empty ,empty ,empty ,chars[0][0] ,chars[0][2] },
    {chars[1][3], chars[1][0],empty ,empty ,empty ,empty ,chars[0][0] ,chars[0][3] },
    {chars[1][4], chars[1][0],empty ,empty ,empty ,empty ,chars[0][0] ,chars[0][4] },
    {chars[1][5], chars[1][0],empty ,empty ,empty ,empty ,chars[0][0] ,chars[0][5] },
    {chars[1][3], chars[1][0],empty ,empty ,empty ,empty ,chars[0][0] ,chars[0][3] },
    {chars[1][2], chars[1][0],empty ,empty ,empty ,empty ,chars[0][0] ,chars[0][2] },
    {chars[1][1], chars[1][0],empty ,empty ,empty ,empty ,chars[0][0] ,chars[0][1] }
};
*/

static char spaces[8] [8] =
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

static char* space[] = {
    spaces[0],
    spaces[1],
    spaces[2],
    spaces[3],
    spaces[4],
    spaces[5],
    spaces[6],
    spaces[7],
};

static std:: string dark = " \033[0m\033[1;40m\033[1;37m ";
static std:: string light = " \033[0m\033[1;47m\033[1;30m ";
