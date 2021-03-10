#include <std.h>
#include "../inherits/area_stuff.h"
inherit TOMB;

void create() 
{
    ::create();
    set_exits(([
       "north" : MROOMS"tomb1_5",
       "east" : MROOMS"tomb1_9",
       "south" : MROOMS"north3",
       "west" : MROOMS"tomb1_7",
    ] ));    
    set_door("white stone door", MROOMS"north3" ,"south", "","lock");
    set_door_description("white stone door",TOMB_DOOR);
}
