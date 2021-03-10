#include <std.h>
#include <move.h>
#include "../tecqumin.h"

inherit TECVOID + "inner_void_base.c";
int vacuum;

string long_desc();

void create()
{
    ::create();
    vacuum = 1;
    set_exits(([       "up" : TECVOID + "inner_void101",
                       "right" : TECVOID + "inner_void100",
                       "left" : TECVOID + "outer_void108",
                       "down" : TECVOID + "inner_void106",
                       "backward" : TECVOID + "inner_void4"   ]));
    set_heart_beat(1);
}

int is_vacuum()
{
    return vacuum;
}

void set_vacuum(int vac)
{
    vacuum = vac;
}
