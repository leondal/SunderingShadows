#include <std.h>
#include "../inherits/area_stuff.h"
inherit INWALL;

void create() 
{
    sexit = "north";
    dest = FFROOMS+"r2";
    ::create();
    set_exits((["west" : FFROOMS+"iw4"]));		
}
