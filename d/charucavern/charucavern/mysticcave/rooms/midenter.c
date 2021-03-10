#include <std.h>
#include "../inherits/area_stuff.h"
inherit MID;

void create() 
{
    ::create();    
    set_long(TO->query_long()+"%^BOLD%^%^CYAN%^ A %^BOLD%^%^BLACK%^small hole%^BOLD%^%^CYAN%^"+
    " has been hallowed out of the odd blue stone in the ceiling here, through which "+
    "some slightly fresher air blows.%^RESET%^");
    
    set_exits((["southeast" : CRROOMS +"mid1"]));		
    
    set_climb_exits((["climb": ({CRROOMS+"upper15", 20, 30, 100}) ]));
    set_fall_desc("%^BOLD%^%^RED%^You stumble and fall landing hard on the floor of the cavern!%^RESET%^");
    
    add_item("hole", "%^BOLD%^%^BLACK%^This small hole has been hollowed out by something or "+
    "someone in the ceiling near the top of the west wall here. From what you can tell it leads to "+
    "a brighter portion of the cavern. You could likely <%^BOLD%^%^CYAN%^"+
    "climb%^BOLD%^%^BLACK%^> through it, if you were so inclined.%^RESET%^");
    
}
