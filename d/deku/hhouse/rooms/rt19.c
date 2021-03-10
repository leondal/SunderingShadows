#include <std.h>
#include "../inherits/area_stuff.h"
inherit RT;

void create() 
{
    ::create();
	
    set_listen("default", "%^RESET%^%^ORANGE%^The chanting grows louder and "+
    "more chaotic toward the northwest.%^RESET%^");

    set_exits((["north" : RROOMS+"24", "northeast" : RROOMS+"25", "east" : RROOMS+"20", "southeast" : RROOMS+"15",
    "south" : RROOMS+"14", "southwest" : RROOMS+"13", "west" : RROOMS+"18", "northwest" : RROOMS+"23" ]));		

}
