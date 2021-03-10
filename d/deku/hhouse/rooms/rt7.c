#include <std.h>
#include "../inherits/area_stuff.h"
inherit RT;

void create() 
{
    ::create();

    set_exits((["north" : RROOMS+"12", "northeast" : RROOMS+"13", "east" : RROOMS+"8", "southeast" : RROOMS+"3",
    "south" : RROOMS+"2", "southwest" : RROOMS+"1", "west" : RROOMS+"6", "northwest" : RROOMS+"11" ]));		

}
