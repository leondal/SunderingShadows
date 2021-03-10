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
    set_exits(([       "up" : TECVOID + "outer_void1",
                       "right" : TECVOID + "inner_void1",
                       "down" : TECVOID + "outer_void8",
                       "forward" : TECVOID + "outer_void106"   ]));
    set_heart_beat(1);
}
