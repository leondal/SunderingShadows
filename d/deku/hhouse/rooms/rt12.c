#include <std.h>
#include "../inherits/area_stuff.h"
inherit RT;

void create() 
{
    ::create();

    set_exits((["north" : RROOMS+"17", "northeast" : RROOMS+"18", "east" : RROOMS+"13", "southeast" : RROOMS+"8",
    "south" : RROOMS+"7", "southwest" : RROOMS+"6", "west" : RROOMS+"11", "northwest" : RROOMS+"16" ]));		

}
