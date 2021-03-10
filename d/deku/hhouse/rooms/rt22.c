#include <std.h>
#include "../inherits/area_stuff.h"
inherit RT;

void create() 
{
    ::create();
	
    set_listen("default", "%^RESET%^%^ORANGE%^The chanting grows louder and "+
    "more chaotic toward the east.%^RESET%^");

    set_exits((["north" : RROOMS+"27", "northeast" : RROOMS+"28", "east" : RROOMS+"23", "southeast" : RROOMS+"18",
    "south" : RROOMS+"17", "southwest" : RROOMS+"16", "west" : RROOMS+"21", "northwest" : RROOMS+"26" ]));		

}
