#include <std.h>
#include "../inherits/area_stuff.h"
inherit HALL;

void create() 
{
    ::create();
    set_long(TO->query_long()+"%^BOLD%^%^BLACK%^ The hall continues north and south.%^RESET%^");
   
    set_exits(([
       "north" : MROOMS"south1",
       //"east" : MROOMS"east1",
       "south" : MROOMS"south3",
       //"west" : MROOMS"west1",
    ] ));    
}
