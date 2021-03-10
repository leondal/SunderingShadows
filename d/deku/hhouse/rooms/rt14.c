#include <std.h>
#include "../inherits/area_stuff.h"
inherit RT;

void create() 
{
    ::create();

    set_exits((["north" : RROOMS+"19", "northeast" : RROOMS+"20", "east" : RROOMS+"15", "southeast" : RROOMS+"10",
    "south" : RROOMS+"9", "southwest" : RROOMS+"8", "west" : RROOMS+"13", "northwest" : RROOMS+"18" ]));		

}
