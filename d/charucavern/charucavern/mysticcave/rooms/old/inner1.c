#include <std.h>
#include "../inherits/area_stuff.h"
inherit INNER;

void create() 
{
    ::create();
    set_long(TO->query_long()+"%^BOLD%^%^WHITE%^ An opening in the eastern wall leads "+
    "to another section of the cavern. A small hole is visible in the ceiling far overhead.%^RESET%^");
    set_exits((["east" : CRROOMS+"inner10"]));		
    set_climb_exits((["climb": ({CRROOMS+"out13", 20, 30, 100}) ]));
    set_fall_desc("%^BOLD%^%^RED%^You stumble and fall almost thirty feet before landing on hard obsidian rock!%^RESET%^");

}
