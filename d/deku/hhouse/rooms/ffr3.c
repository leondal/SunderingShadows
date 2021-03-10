#include <std.h>
#include "../inherits/area_stuff.h"
#include "../inherits/door_stuff.h"
inherit HHROOM;

void create() 
{
    sexit = "west";
    dest = FFROOMS+"iw9";
    ::create();
	
    set_exits((["east" : FFROOMS+"12" ]));		
    set_door("door", FFROOMS+"12", "east");
    set_door_description("door", HALLGD);
}
