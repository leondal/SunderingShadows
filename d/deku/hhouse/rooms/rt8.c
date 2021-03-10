#include <std.h>
#include "../inherits/area_stuff.h"
inherit RT;

void create() 
{
    ::create();

    set_exits((["north" : RROOMS+"13", "northeast" : RROOMS+"14", "east" : RROOMS+"9", "southeast" : RROOMS+"4",
    "south" : RROOMS+"3", "southwest" : RROOMS+"2", "west" : RROOMS+"7", "northwest" : RROOMS+"12" ]));		

}
