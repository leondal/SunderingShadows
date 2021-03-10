#include <std.h>
#include "../../arctic.h"
inherit ROOMS"lake.c";

int FLAG;

void create()
{
    ::create();

    FLAG = 0;

    set_exits(([
        "north"     : LAKE"lake4",
        "east"      : LAKE"lake9",
        "south"     : LAKE"lake12",
        "west"      : LAKE"lake7",
             ]));
    check_ice();
}

void reset()
{
    ::reset();
    if(!FLAG) { FLAG = 1; return; }
    check_ice();
}