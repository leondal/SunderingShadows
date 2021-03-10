#include <std.h>
#include "../inherits/area_stuff.h"
inherit HALL;

void create() 
{
    ::create();
    set_long(TO->query_long()+"%^BOLD%^%^BLACK%^ The hall continues north and "+
    "south.%^RESET%^");
   
    set_exits(([
       "north" : MROOMS"north3",
       //"east" : MROOMS"east1",
       "south" : MROOMS"north1",
       //"west" : MROOMS"west1",
    ] ));    
}
