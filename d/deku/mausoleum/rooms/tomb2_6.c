#include <std.h>
#include "../inherits/area_stuff.h"
inherit TOMB;

void create() 
{
    ::create();
    set_exits(([
       "north" : MROOMS"tomb2_3",
       "east" : MROOMS"west3",
       "south" : MROOMS"tomb2_9",
       "west" : MROOMS"tomb2_5",
    ] ));    
    set_door("white stone door", MROOMS"west3" ,"east", "","lock");
    set_door_description("white stone door",TOMB_DOOR);
}
