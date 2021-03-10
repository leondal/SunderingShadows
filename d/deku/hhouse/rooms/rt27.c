#include <std.h>
#include "../inherits/area_stuff.h"
inherit RT;

void create() 
{
    ::create();
    set_long(TO->query_long() + "%^BOLD%^%^WHITE%^ You are on the edge of the "+
    "roof and could %^BOLD%^%^MAGENTA%^jump%^BOLD%^%^WHITE%^ down "+
    "into the courtyard far below if you were so inclined.%^RESET%^");

    set_listen("default", "%^RESET%^%^ORANGE%^The chanting grows louder and "+
    "more chaotic toward the southeast.%^RESET%^");

    set_exits((["east" : RROOMS+"28", "south" : RROOMS+"22", "southeast" : RROOMS+"23",
    "west" : RROOMS+"26", "southwest" : RROOMS+"21" ]));

    set_property("jump_destination", "north");		

}
