#include <std.h>
#include "../inherits/area_stuff.h"
inherit MID;

void create() 
{
    ::create();
    set_exits((["west" : CRROOMS+"mid2_1"]));		
    
    set_search("default", "%^BOLD%^%^CYAN%^You notice crack near the top of the east wall that "+
    "looks big enough to <%^BOLD%^%^WHITE%^climb%^BOLD%^%^CYAN%^> through if you were so inclined.%^RESET%^");    
    
    set_climb_exits((["climb": ({CRROOMS+"upper8", 20, 30, 100}) ]));
    set_fall_desc("%^BOLD%^%^RED%^You stumble and fall landing hard on the floor of the cavern!%^RESET%^");
    
}
