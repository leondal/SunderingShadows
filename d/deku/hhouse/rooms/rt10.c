#include <std.h>
#include "../inherits/area_stuff.h"
inherit RT;

void create() 
{
    ::create();
    set_long(TO->query_long() + "%^BOLD%^%^WHITE%^ You are on the edge of the "+
    "roof and could %^BOLD%^%^MAGENTA%^jump%^BOLD%^%^WHITE%^ down into the "+
    "courtyard far below if you were so inclined.%^RESET%^");

    set_exits((["west" : RROOMS+"9", "south" : RROOMS+"5", "north" : RROOMS+"15", 
    "southwest" : RROOMS+"4", "northwest" : RROOMS+"14"]));

    set_property("jump_destination", "east");

}
