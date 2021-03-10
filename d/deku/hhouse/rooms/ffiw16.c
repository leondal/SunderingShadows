#include <std.h>
#include "../inherits/area_stuff.h"
inherit INWALL;

void create() 
{	
    ::create();
    set_exits((["south" : FFROOMS+"iw17", "east" : FFROOMS+"iw13"]));		
}
