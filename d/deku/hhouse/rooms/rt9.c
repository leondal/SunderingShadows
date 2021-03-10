#include <std.h>
#include "../inherits/area_stuff.h"
inherit RT;

void create() 
{
    ::create();

    set_exits((["north" : RROOMS+"14", "northeast" : RROOMS+"15", "east" : RROOMS+"10", "southeast" : RROOMS+"5",
    "south" : RROOMS+"4", "southwest" : RROOMS+"3", "west" : RROOMS+"8", "northwest" : RROOMS+"13" ]));		

}
