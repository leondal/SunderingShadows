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
    set_exits(([       "up" : TECVOID + "outer_void6",
                       "right" : TECVOID + "inner_void4",
                       "down" : TECVOID + "outer_void10",
                       "forward" : TECVOID + "outer_void108"   ]));
    set_heart_beat(1);
}
