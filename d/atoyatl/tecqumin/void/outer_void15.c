#include <std.h>
#include <move.h>
#include "../tecqumin.h"

inherit TECVOID + "outer_void_base.c";
int vacuum;

string long_desc();

void create()
{
    ::create();
    vacuum = 1;
    set_exits(([     "left" : TECVOID + "outer_void14",
                     "up" : TECVOID + "inner_void8",
                     "right" : TECVOID + "outer_void16",
                     "forward" : TECVOID + "outer_void115"  ]));
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
