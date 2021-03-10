#include <std.h>
#include "../inherits/area_stuff.h"
inherit HALL;

void create() 
{
    ::create();
    set_long(TO->query_long()+"%^BOLD%^%^BLACK%^ The hall continues north. It opens "+
    "up into a center area of the mausoleum to the south.%^RESET%^");
   
    set_exits(([
       "north" : MROOMS"north2",
       //"east" : MROOMS"east1",
       "south" : MROOMS"center",
       //"west" : MROOMS"west1",
    ] ));    
}
