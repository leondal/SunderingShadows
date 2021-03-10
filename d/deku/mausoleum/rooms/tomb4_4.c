#include <std.h>
#include "../inherits/area_stuff.h"
inherit TOMB;

void create() 
{
    ::create();
    set_exits(([
       "north" : MROOMS"tomb4_1",
       "east" : MROOMS"tomb4_5",
       "south" : MROOMS"tomb4_7",
       //"west" : MROOMS"east3",
    ] ));    
}
