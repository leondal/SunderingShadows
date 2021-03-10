#include <std.h>
#include "../inherits/area_stuff.h"
#include "../inherits/door_stuff.h"
inherit HHROOM;

void create() 
{
    ::create();
	
    set_exits((["south" : FFROOMS+"4" ]));		
    set_door("door", FFROOMS+"4", "south");
    set_door_description("door", HALLGD);
}
