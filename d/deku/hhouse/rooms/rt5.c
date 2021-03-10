#include <std.h>
#include "../inherits/area_stuff.h"
inherit RT;

void create() 
{
    ::create();
    set_long(TO->query_long() + "%^BOLD%^%^WHITE%^A rickety staircase "+
    "leads down to the second floor of the house. You are on the edge of the "+
    "roof and could %^BOLD%^%^MAGENTA%^jump%^BOLD%^%^WHITE%^ down into "+
    "the courtyard far below if you were so inclined.%^RESET%^");

    if(random(2)) set_property("jump_destination", "south");	
    else set_property("jump_destination", "east");

    set_exits((["west" : RROOMS+"4", "north" : RROOMS+"10", "northwest" : RROOMS+"9"]));		

}
