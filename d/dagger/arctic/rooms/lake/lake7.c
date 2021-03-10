#include <std.h>
#include "../../arctic.h"
inherit ROOMS"lake.c";

int FLAG;

void create()
{
    ::create();

    FLAG = 0;

    set_exits(([
        "north"     : LAKE"lake3",
        "east"      : LAKE"lake8",
        "south"     : LAKE"lake11",
        "west"      : LAKE"lake6",
             ]));
    check_ice();
}

void reset()
{
    ::reset();
    if(!FLAG) { FLAG = 1; return; }
    check_ice();
}