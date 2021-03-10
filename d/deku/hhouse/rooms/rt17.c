#include <std.h>
#include "../inherits/area_stuff.h"
inherit RT;

void create() 
{
    ::create();
	
    set_listen("default", "%^RESET%^%^ORANGE%^The chanting grows louder and "+
    "more chaotic toward the northeast.%^RESET%^");

    set_exits((["north" : RROOMS+"22", "northeast" : RROOMS+"23", "east" : RROOMS+"18", "southeast" : RROOMS+"13",
    "south" : RROOMS+"12", "southwest" : RROOMS+"11", "west" : RROOMS+"16", "northwest" : RROOMS+"21" ]));		

}
