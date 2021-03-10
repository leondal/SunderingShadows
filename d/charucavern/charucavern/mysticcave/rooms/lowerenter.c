#include <std.h>
#include "../inherits/area_stuff.h"
inherit LOWER;

void create() 
{
    ::create();    
    set_long(TO->query_long()+"%^RESET%^%^CYAN%^ A %^BOLD%^%^BLACK%^small hole%^RESET%^%^CYAN%^"+
    " has been hallowed out of the odd blue stone in the ceiling here, through which "+
    "some air seems to waft.%^RESET%^");
    
    set_exits((["north" : CRROOMS +"lower1"]));		
    
    set_climb_exits((["climb": ({CRROOMS+"mid11", 20, 30, 100}) ]));
    set_fall_desc("%^BOLD%^%^RED%^You stumble and fall landing hard on the floor of the cavern!%^RESET%^");
    
    add_item("hole", "%^BOLD%^%^BLACK%^This small hole has been hollowed out by something or "+
    "someone in the ceiling near the top of the east wall here. From what you can tell it leads to "+
    "a slightly brighter portion of the cavern. You could likely <%^BOLD%^%^CYAN%^"+
    "climb%^BOLD%^%^BLACK%^> through it, if you were so inclined.%^RESET%^");
    
}
