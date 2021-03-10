#include <std.h>
#include "../inherits/area_stuff.h"
inherit HALL;

void create() 
{
    ::create();
    set_long(TO->query_long()+"%^BOLD%^%^BLACK%^ The hall continues east. "+
    "A %^WHITE%^white stone%^BOLD%^%^BLACK%^ door is set into the "+
    "west wall.%^RESET%^%^RESET%^");
   
    set_exits(([
       //"north" : MROOMS"south2",
       "east" : MROOMS"west2",
       //"south" : MROOMS"tomb2_2",
       "west" : MROOMS"tomb2_6",
    ] ));    
    set_door("white stone door", MROOMS"tomb2_6" ,"west", "","lock");
    set_door_description("white stone door",TOMB_DOOR);
}
