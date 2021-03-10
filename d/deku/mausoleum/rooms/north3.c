#include <std.h>
#include "../inherits/area_stuff.h"
inherit HALL;

void create() 
{
    ::create();
    set_long(TO->query_long()+"%^BOLD%^%^BLACK%^ The hall continues south. "+
    "A %^WHITE%^white stone%^BOLD%^%^BLACK%^ door is set into the "+
    "north wall.%^RESET%^");
   
    set_exits(([
       "north" : MROOMS"tomb1_8",
       //"east" : MROOMS"east1",
       "south" : MROOMS"north2",
       //"west" : MROOMS"west1",
    ] ));    
    set_door("white stone door", MROOMS"tomb1_8" ,"north", "","lock");
    set_door_description("white stone door",TOMB_DOOR);
}
