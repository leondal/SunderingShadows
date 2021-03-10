#include <std.h>
#include "../inherits/area_stuff.h"
#include "../inherits/door_stuff.h"
inherit HHROOM;

void create() 
{
    ::create();
	
    set_exits((["east" : FFROOMS+"37" ]));		
    set_door("door", FFROOMS+"37", "east");
    set_door_description("door", HALLGD);
}
