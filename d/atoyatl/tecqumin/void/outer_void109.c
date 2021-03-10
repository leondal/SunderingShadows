#include <std.h>
#include <move.h>
#include "../tecqumin.h"

inherit VOID_ROOM + "outer_void_base.c";
int vacuum;

string long_desc();

void create()
{
    ::create();
    vacuum = 1;
    set_exits(([       "up" : JUNG_ROOM + "outer_void107",
                       "left" : JUNG_ROOM + "inner_void105",
                       "down" : JUNG_ROOM + "outer_void111",
                       "backward" : JUNG_ROOM + "outer_void9"   ]));
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
