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
    set_exits(([       "up" : TECVOID + "outer_void7",
                       "left" : TECVOID + "inner_void5",
                       "down" : TECVOID + "outer_void11",
                       "forward" : TECVOID + "outer_void109"   ]));
    set_heart_beat(1);
}
