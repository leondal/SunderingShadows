#include <std.h>
#include "../inherits/area_stuff.h"
inherit TOMB;

void create() 
{
    ::create();
    set_exits(([
       "north" : MROOMS"tomb3_3",
       //"east" : MROOMS"west3",
       "south" : MROOMS"tomb3_9",
       "west" : MROOMS"tomb3_5",
    ] ));    
}
