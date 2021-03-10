#include <std.h>
#include "../inherits/area_stuff.h"
inherit INWALL;

void create() 
{	
    sexit = "north";
    dest = FFROOMS+"r9";
    ::create();
    set_exits((["south" : FFROOMS+"iw14"]));		
}
