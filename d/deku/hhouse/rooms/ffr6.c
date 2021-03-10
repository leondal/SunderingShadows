#include <std.h>
#include "../inherits/area_stuff.h"
#include "../inherits/door_stuff.h"
inherit HHROOM;

void create() 
{
    sexit = "east";
    dest = FFROOMS+"iw18";
    ::create();
	
    set_exits((["west" : FFROOMS+"28" ]));		
    set_door("door", FFROOMS+"28", "west");
    set_door_description("door", HALLGD);
}
