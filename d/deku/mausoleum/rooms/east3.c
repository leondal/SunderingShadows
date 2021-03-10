#include <std.h>
#include "../inherits/area_stuff.h"
inherit HALL;

void create() 
{
    ::create();
    set_long(TO->query_long()+"%^BOLD%^%^BLACK%^ The hall continues west. "+
    "A %^WHITE%^white stone%^BOLD%^%^BLACK%^ door is set into the "+
    "east wall.%^RESET%^%^RESET%^");
   
    set_exits(([
       //"north" : MROOMS"south2",
       "east" : MROOMS"tomb3_4",
       //"south" : MROOMS"tomb2_2",
       "west" : MROOMS"east2",
    ] ));    
    set_door("white stone door", MROOMS"tomb3_4" ,"east", "","lock");
    set_door_description("white stone door",TOMB_DOOR);
}
