#include <std.h>
#include "../../arctic.h"
inherit ROOMS"lake.c";

int FLAG;

void create()
{
    ::create();

    FLAG = 0;

    set_exits(([
        "north"     : LAKE"lake8",
        "east"      : LAKE"lake13",
        "south"     : LAKE"lake15",
        "west"      : LAKE"lake11",
             ]));
    check_ice();
}

void reset()
{
    ::reset();
    if(!FLAG) { FLAG = 1; return; }
    check_ice();
}