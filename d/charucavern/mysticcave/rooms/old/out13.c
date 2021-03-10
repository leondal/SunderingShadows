#include <std.h>
#include "../inherits/area_stuff.h"
inherit OUTTER2;

void create() 
{
    ::create();
    set_long(TO->query_long()+"%^RESET%^%^ORANGE%^ Some of the earth here has caved in leaving a small "+
    "hole.%^RESET%^");
    set_exits((["north" : CRROOMS+"out12", "northeast" : CRROOMS+"17", "east" : CRROOMS+"out18", "south" : CRROOMS+"out14", 
    "west" : CRROOMS+"out15", "northwest" : CRROOMS+"out16"]));		
    set_climb_exits((["descend": ({CRROOMS + "inner1", 20, 30, 100}) ]));
    set_fall_desc("%^BOLD%^%^RED%^You stumble and fall perhaps thirty feet before landing on hard obsidian rock!%^RESET%^");

    set_search("default", "%^RESET%^%^ORANGE%^The hole draws your attention.%^RESET%^");
    set_search("hole", (:TO, "hole_search":));
}

int hole_search(string str)
{
    if(!objectp(TO)) return 0;
    if(!objectp(TP)) return 0;
    tell_object(TP, "%^RESET%^%^ORANGE%^You determine that the small hole leads to a much larger "+
    "cavern below. You could probably descend into it, if you were brave enough.%^RESET%^");
    return 1;
}