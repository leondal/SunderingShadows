#include <std.h>
#include "../inherits/area_stuff.h"
inherit MID;

void create() 
{
    ::create();
    
    set_long(TO->query_long() + "%^BOLD%^%^CYAN%^ The air stirs here, though it "+
    "does little to help with the stagnation that hangs in the air.%^RESET%^");

    set_exits((["west" : CRROOMS+"mid4", "northwest" : CRROOMS +"mid2"]));		
    
    set_climb_exits((["descend": ({CRROOMS+"lower2_enter", 20, 30, 100}) ]));
    set_fall_desc("%^BOLD%^%^RED%^You stumble and fall landing hard on the sandy floor of the cavern!%^RESET%^");
    
    set_search("default", "%^BOLD%^%^CYAN%^You notice a hole near the base of the east wall that you could "+
    "probably <%^BOLD%^%^WHITE%^descend%^BOLD%^%^CYAN%^> into if you were so inclined.%^RESET%^");     
    
}
