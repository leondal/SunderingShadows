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
    set_exits(([       "up" : TECVOID + "outer_void104",
                       "right" : TECVOID + "outer_void107",
                       "left" : TECVOID + "inner_void102",
                       "down" : TECVOID + "inner_void105",
                       "forward" : TECVOID + "inner_void3"   ]));
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
