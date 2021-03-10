#include <std.h>
#include "../inherits/area_stuff.h"
inherit HALL;

void create() 
{
    ::create();
    set_long(TO->query_long()+"%^BOLD%^%^BLACK%^ The hall continues south. It opens "+
    "up into a center area of the mausoleum to the north.%^RESET%^");
   
    set_exits(([
       "north" : MROOMS"center",
       //"east" : MROOMS"east1",
       "south" : MROOMS"south2",
       //"west" : MROOMS"west1",
    ] ));    
}
