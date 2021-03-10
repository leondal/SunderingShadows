#include <std.h>
#include "../inherits/area_stuff.h"
inherit WORMNAR2;

void create() 
{
    ::create();
    set_long(TO->query_long()+"%^RESET%^%^ORANGE%^You could <%^WHITE%^climb%^RESET%^"+
    "%^ORANGE%^> or "+
    "<%^BOLD%^%^BLACK%^descend%^RESET%^%^ORANGE%^> "+
    "into the %^BOLD%^%^BLACK%^darkness%^RESET%^%^ORANGE%^.%^RESET%^");
    
    set_position(3);
    set_fall_to("wormtun3_1");  
    set_climb_exits((["climb": ({WROOMS+"wormnar3_3", 20, 30, 100}), "descend" : ({WROOMS+"wormnar3_5", 20, 10, 100}) ]));
    set_fall_desc("%^BOLD%^%^RED%^You stumble and fall!%^RESET%^");
    

}
