#include <std.h>
#include "../inherits/area_stuff.h"
#include "../inherits/door_stuff.h"
inherit HHROOM;

void create() 
{
    ::create();
	
    set_exits((["west" : FFROOMS+"23" ]));		
    set_door("door", FFROOMS+"23", "west");
    set_door_description("door", HALLGD);
}
