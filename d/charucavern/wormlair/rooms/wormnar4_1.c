#include <std.h>
#include "../inherits/area_stuff.h"
inherit WORMNAR2;

void create() 
{
    ::create();
    set_long(TO->query_long()+"%^RESET%^%^ORANGE%^You could <%^WHITE%^climb%^RESET%^"+
    "%^ORANGE%^> out of the passageway and back into the cavern or "+
    "<%^BOLD%^%^BLACK%^descend%^RESET%^%^ORANGE%^> "+
    "into the %^BOLD%^%^BLACK%^darkness%^RESET%^%^ORANGE%^.%^RESET%^");
    
    set_position(6);
    set_fall_to("wormnar4_6");
    set_land_on("metal grate");
    set_climb_exits((["climb": ({WROOMS+"wormtun3_11", 20, 30, 100}), "descend" : ({WROOMS+"wormnar4_2", 20, 10, 100}) ]));
    set_fall_desc("%^BOLD%^%^RED%^You stumble and fall!^RESET%^");
}
