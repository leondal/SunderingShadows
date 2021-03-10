#include <std.h>
#include "../inherits/area_stuff.h"
inherit HID;

void create() 
{
    ::create();   
    set_exits(([
       "north" : MROOMS"hidden7",       
       "southwest" : MROOMS"hidden9",
    ] ));    
    set_long((string)TO->query_long()+"%^BOLD%^%^BLACK%^ The tunnel "+
    "continues north and southwest.%^RESET%^");
}
