#include <std.h>
#include "../inherits/area_stuff.h"
inherit MID;

void create() 
{
    ::create();    
    set_long(TO->query_long() + "%^BOLD%^%^CYAN%^ A small %^BOLD%^%^BLACK%^hole"+
    "%^BOLD%^%^CYAN%^ has been hollowed out in the center of the "+
    "floor. The air stirs here slightly, yet it "+
    "does little to help with the stagnation.%^RESET%^");
    
    set_exits((["north" : CRROOMS +"mid10"]));		
    
    set_climb_exits((["descend": ({CRROOMS+"lowerenter", 20, 30, 100}) ]));
    set_fall_desc("%^BOLD%^%^RED%^You stumble and fall landing hard on the floor of the cavern!%^RESET%^");
    
    add_item("hole", "%^BOLD%^%^BLACK%^This small hole has been hollowed out by something or "+
    "someone in the center of the floor in this part of the cavern. From what you can tell it leads to "+
    "a much darker portion of the cavern. You could likely <%^BOLD%^%^CYAN%^"+
    "descend%^BOLD%^%^BLACK%^> into it, if you were so inclined.%^RESET%^");
    
}
