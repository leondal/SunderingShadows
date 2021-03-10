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
    set_exits(([    "right" : TECVOID + "outer_void3",
                    "left" : TECVOID + "outer_void1",
                    "down" : TECVOID + "inner_void1",
                    "forward" : TECVOID + "outer_void102"   ]));
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
