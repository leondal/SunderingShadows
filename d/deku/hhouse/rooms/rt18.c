#include <std.h>
#include "../inherits/area_stuff.h"
inherit RT;

void create() 
{
    ::create();
	
    set_listen("default", "%^RESET%^%^ORANGE%^The chanting grows louder and "+
    "more chaotic toward the north.%^RESET%^");

    set_exits((["north" : RROOMS+"23", "northeast" : RROOMS+"24", "east" : RROOMS+"19", "southeast" : RROOMS+"14",
    "south" : RROOMS+"13", "southwest" : RROOMS+"12", "west" : RROOMS+"17", "northwest" : RROOMS+"22" ]));		

}
