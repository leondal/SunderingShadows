#include <std.h>
#include "../inherits/area_stuff.h"
inherit INWALL;

void create() 
{	
    sexit = "north";
    dest = FFROOMS+"16";
    ::create();
    set_exits((["south" : FFROOMS+"iw9"]));		
}
