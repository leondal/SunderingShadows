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
    set_exits(([       "up" : TECVOID + "outer_void3",
                       "right" : TECVOID + "inner_void3",
                       "left" : TECVOID + "inner_void1",
                       "down" : TECVOID + "inner_void0",
                       "forward" : TECVOID + "inner_void102"   ]));
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
