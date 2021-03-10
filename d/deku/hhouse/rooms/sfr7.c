#include <std.h>
#include "../inherits/area_stuff.h"
#include "../inherits/door_stuff.h"
inherit HHROOM;

void create() 
{
    ::create();
	
    set_exits((["west" : SFROOMS+"h22" ]));		
    set_door("door", SFROOMS+"h22", "west");
    set_door_description("door", HALLGD);
}
