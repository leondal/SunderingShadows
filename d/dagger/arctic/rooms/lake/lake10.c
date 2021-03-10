#include <std.h>
#include "../../arctic.h"
inherit ROOMS"lake.c";

int FLAG;

void create()
{
    ::create();

    FLAG = 0;

    set_exits(([
        "south"     : LAKE"lake14",
        "west"      : LAKE"lake9",
        "northwest" : LAKE"lake5",
             ]));
    check_ice();
}

void reset()
{
    ::reset();
    if(!FLAG) { FLAG = 1; return; }
    check_ice();
}