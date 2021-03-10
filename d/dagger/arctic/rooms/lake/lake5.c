#include <std.h>
#include "../../arctic.h"
inherit ROOMS"lake.c";

int FLAG;

void create()
{
    ::create();

    FLAG = 0;

    set_exits(([
        "north"     : LAKE"lake2",
        "south"     : LAKE"lake9",
        "west"      : LAKE"lake4",
        "southeast" : LAKE"lake10",
             ]));
    check_ice();
}

void reset()
{
    ::reset();
    if(!FLAG) { FLAG = 1; return; }
    check_ice();
}