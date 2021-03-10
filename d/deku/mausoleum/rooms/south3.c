#include <std.h>
#include "../inherits/area_stuff.h"
inherit HALL;

void create() 
{
    ::create();
    set_long(TO->query_long()+"%^BOLD%^%^BLACK%^ The hall continues north. "+
    "A %^WHITE%^white stone%^BOLD%^%^BLACK%^ door is set into the "+
    "south wall.%^RESET%^%^RESET%^");
   
    set_exits(([
       "north" : MROOMS"south2",
       //"east" : MROOMS"east1",
       "south" : MROOMS"tomb4_2",
       //"west" : MROOMS"west1",
    ] ));    
    set_door("white stone door", MROOMS"tomb4_2" ,"south", "","lock");
    set_door_description("white stone door",TOMB_DOOR);
}
