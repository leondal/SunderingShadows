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
    set_exits(([    "right" : TECVOID + "outer_void4",
                    "left" : TECVOID + "outer_void2",
                    "down" : TECVOID + "inner_void2",
                    "forward" : TECVOID + "outer_void103"   ]));
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
