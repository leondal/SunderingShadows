#include <std.h>
#include "../inherits/area_stuff.h"
inherit LOWER;

void create() 
{
    ::create();     
    set_exits((["east" : CRROOMS +"lower2_1"]));		

    set_climb_exits((["climb": ({CRROOMS+"mid3", 20, 30, 100}) ]));
    set_fall_desc("%^BOLD%^%^RED%^You stumble and fall landing hard on the sandy floor of the cavern!%^RESET%^");
    
    set_search("default", "%^RESET%^%^YELLOW%^You do not think that there is "+
    "any place to hide anything here. However, you do notice a small hole near the top of "+
    "west wall that you could likely <%^BOLD%^%^CYAN%^climb%^RESET%^%^YELLOW%^> "+
    "through if you were so inclined.%^RESET%^");    
}
