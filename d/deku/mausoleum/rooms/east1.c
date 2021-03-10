#include <std.h>
#include "../inherits/area_stuff.h"
inherit HALL;

void create() 
{
    ::create();
    set_long(TO->query_long()+"%^BOLD%^%^BLACK%^ The hall continues east. It opens "+
    "up into a center area of the mausoleum to the west.%^RESET%^");
   
    set_exits(([
       //"north" : MROOMS"center",
       "east" : MROOMS"east2",
       //"south" : MROOMS"south2",
       "west" : MROOMS"center",
    ] ));    
}
