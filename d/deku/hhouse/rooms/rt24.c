#include <std.h>
#include "../inherits/area_stuff.h"
inherit RT;

void create() 
{
    ::create();
	
    set_listen("default", "%^RESET%^%^ORANGE%^The chanting grows louder and "+
    "more chaotic toward the west.%^RESET%^");

    set_exits((["north" : RROOMS+"29", "northeast" : RROOMS+"30", "east" : RROOMS+"25", "southeast" : RROOMS+"20",
    "south" : RROOMS+"19", "southwest" : RROOMS+"18", "west" : RROOMS+"23", "northwest" : RROOMS+"28" ]));		

}
