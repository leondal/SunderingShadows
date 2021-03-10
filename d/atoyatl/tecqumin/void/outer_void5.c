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
    set_exits(([     "left" : TECVOID + "outer_void4",
                     "down" : TECVOID + "outer_void7",
                     "forward" : TECVOID + "outer_void105"   ]));
    set_heart_beat(1);
}
