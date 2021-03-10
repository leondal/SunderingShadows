#include <std.h>
#include "../inherits/area_stuff.h"
inherit HALL;

void create() 
{
    ::create();
    set_long(TO->query_long()+"%^BOLD%^%^BLACK%^ The hall continues west. It opens "+
    "up into a center area of the mausoleum to the east.%^RESET%^");
   
    set_exits(([
       //"north" : MROOMS"center",
       "east" : MROOMS"center",
       //"south" : MROOMS"south2",
       "west" : MROOMS"west2",
    ] ));    
}
