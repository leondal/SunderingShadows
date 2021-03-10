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
    set_exits(([       "up" : TECVOID + "inner_void105",
                       "right" : TECVOID + "outer_void111",
                       "left" : TECVOID + "inner_void107",
                       "down" : TECVOID + "outer_void115",
                       "backward" : TECVOID + "inner_void8"   ]));
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
