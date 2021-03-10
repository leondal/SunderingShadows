#include <std.h>
#include "../inherits/area_stuff.h"
inherit INWALL;

void create() 
{	
    sexit = "east";
    dest = FFROOMS+"39";
    ::create();
    set_exits((["west" : FFROOMS+"iw13"]));		
}
