#include <std.h>
#include <daemons.h>
#include "../inherits/area_stuff.h"
inherit INWALL;

void create() 
{	
    sexit = "west";
    dest = FFROOMS+"iw19";
    ::create();
    set_exits(([ "down" : BROOMS+"1" ]));
    set_long(TO->query_long() + "%^BOLD%^%^BLACK%^ A narrow rickety staircase leads down into "+
    "what looks to be a poorly constructed basement.%^RESET%^");
}

