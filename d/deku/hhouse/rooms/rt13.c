#include <std.h>
#include "../inherits/area_stuff.h"
inherit RT;

void create() 
{
    ::create();

    set_exits((["north" : RROOMS+"18", "northeast" : RROOMS+"19", "east" : RROOMS+"14", "southeast" : RROOMS+"9",
    "south" : RROOMS+"8", "southwest" : RROOMS+"7", "west" : RROOMS+"12", "northwest" : RROOMS+"17" ]));		

}
