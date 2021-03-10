#include <std.h>
#include "../inherits/area_stuff.h"
#include "../inherits/door_stuff.h"
inherit HHROOM;

void create() 
{
    sexit = "south";
    dest = FFROOMS+"iw5";
    ::create();
	
    set_exits((["east" : FFROOMS+"9" ]));		
    set_door("door", FFROOMS+"9", "east");
    set_door_description("door", HALLGD);
}
