#include <std.h>
#include "../inherits/area_stuff.h"
#include "../inherits/door_stuff.h"
inherit HHROOM;

void create() 
{
    ::create();
	
    set_exits((["south" : SFROOMS+"h4" ]));		
    set_door("door", SFROOMS+"h4", "south");
    set_door_description("door", HALLGD);
}
