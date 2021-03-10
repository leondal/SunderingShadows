#include <std.h>
#include "../inherits/area_stuff.h"
inherit WORMNAR;

void create() 
{
    ::create();
    set_long(TO->query_long()+"%^RESET%^%^ORANGE%^A breeze fills the passageway and "+
    "you can make out the surface world just above you. You could <%^WHITE%^climb%^RESET%^"+
    "%^ORANGE%^> out of the passageway and back to the surface or "+
    "<%^BOLD%^%^BLACK%^descend%^RESET%^%^ORANGE%^> "+
    "into the %^BOLD%^%^BLACK%^darkness%^RESET%^%^ORANGE%^.%^RESET%^");
    
    set_position(6);
    set_fall_to("wormtun1_1");
    set_climb_exits((["climb": ({OE, 20, 30, 100}), "descend" : ({WROOMS+"wormnar1_2", 20, 10, 100}) ]));
    set_fall_desc("%^BOLD%^%^RED%^You stumble and fall!^RESET%^");
}
