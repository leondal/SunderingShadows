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
    set_exits(([       "up" : TECVOID + "inner_void4",
                       "right" : TECVOID + "inner_void7",
                       "left" : TECVOID + "outer_void10",
                       "down" : TECVOID + "outer_void13",
                       "forward" : TECVOID + "inner_void106"   ]));
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
