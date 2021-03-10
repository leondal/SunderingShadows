#include <std.h>
#include "../inherits/area_stuff.h"
#include "../inherits/door_stuff.h"
inherit HHROOM;

void create() 
{
    ::create();
	
    set_exits((["east" : SFROOMS+"iw4" ]));		
    set_door("door", SFROOMS+"iw4", "east");
    set_door_description("door", HALLGD);
}
