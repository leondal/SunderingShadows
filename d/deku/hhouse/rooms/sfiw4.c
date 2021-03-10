#include <std.h>
#include "../inherits/area_stuff.h"
#include "../inherits/door_stuff.h"
inherit INWALL;

void create() 
{
    sexit = "south";
    dest = SFROOMS+"r5";
    ::create();
    set_exits((["west" : SFROOMS+"r6", "east" : SFROOMS+"iw5"]));
    set_door("door", SFROOMS+"r6", "west");	
    set_door_description("door", HALLBD);
}
