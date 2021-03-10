#include <std.h>
#include "../inherits/area_stuff.h"
inherit INWALL;

void create() 
{	
    ::create();
    set_exits((["west" : FFROOMS+"iw16", "east" : FFROOMS+"iw12", "north" : FFROOMS+"iw14"]));		
}
