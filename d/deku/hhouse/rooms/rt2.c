#include <std.h>
#include "../inherits/area_stuff.h"
inherit RT;

void create() 
{
    ::create();
    set_long(TO->query_long() + "%^BOLD%^%^WHITE%^ You are on the edge of the "+
    "roof and could %^BOLD%^%^MAGENTA%^jump%^BOLD%^%^WHITE%^ down into "+
    "the courtyard far below if you were so inclined.%^RESET%^");
    set_property("jump_destination", "south");	

    set_exits((["west" : RROOMS+"1", "east" : RROOMS+"3", "north" : RROOMS+"7", "northeast" : RROOMS+"8",
    "northwest" : RROOMS+"6" ]));		

}
