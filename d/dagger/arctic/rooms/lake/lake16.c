#include <std.h>
#include "../../arctic.h"
inherit ROOMS"lake.c";

int FLAG;

void create()
{
    ::create();
    
    FLAG = 0;
    set_exits(([
        "north"     : LAKE"lake13",
        "west"      : LAKE"lake15",
        "northeast" : LAKE"lake14",
             ]));
    check_ice();
}

void reset()
{
    ::reset();
    if(!FLAG) { FLAG = 1; return; } 
    check_ice();
}