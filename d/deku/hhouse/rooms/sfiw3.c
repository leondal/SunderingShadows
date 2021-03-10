#include <std.h>
#include "../inherits/area_stuff.h"
inherit INWALL;

void create() 
{
    sexit = "north";
    dest = SFROOMS+"r8";
    ::create();
    set_exits((["south" : SFROOMS+"iw2"]));		
}
