#include <std.h>
#include "../inherits/area_stuff.h"
inherit TOMB;

void create() 
{
    ::create();
    set_exits(([
       "north" : MROOMS"south3",
       "east" : MROOMS"tomb4_3",
       "south" : MROOMS"tomb4_5",
       "west" : MROOMS"tomb4_1",
    ] ));    
    set_door("white stone door", MROOMS"south3" ,"north", "","lock");
    set_door_description("white stone door",TOMB_DOOR);
}
