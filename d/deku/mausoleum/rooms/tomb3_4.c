#include <std.h>
#include "../inherits/area_stuff.h"
inherit TOMB;

void create() 
{
    ::create();
    set_exits(([
       "north" : MROOMS"tomb3_1",
       "east" : MROOMS"tomb3_5",
       "south" : MROOMS"tomb3_7",
       "west" : MROOMS"east3",
    ] ));    
    set_door("white stone door", MROOMS"east3" ,"west", "","lock");
    set_door_description("white stone door",TOMB_DOOR);
}
