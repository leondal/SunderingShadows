#include <std.h>
#include "../inherits/area_stuff.h"
inherit UPPER;

void create() 
{
    ::create();    
    set_long(TO->query_long() + "%^BOLD%^%^CYAN%^ The air stirs here slightly, yet it "+
    "does little to help with the stagnation.%^RESET%^");
    set_exits((["west" : CRROOMS+"upper13", "north" : CRROOMS +"upper15"]));		
}
