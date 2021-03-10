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
    set_exits(([       "up" : TECVOID + "outer_void5",
                       "left" : TECVOID + "inner_void3",
                       "down" : TECVOID + "outer_void9",
                       "forward" : TECVOID + "outer_void107"   ]));
    set_heart_beat(1);
}
