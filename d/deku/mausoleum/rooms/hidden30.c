#include <std.h>
#include "../inherits/area_stuff.h"
inherit HID;

void create() 
{
    ::create();   
    set_exits(([
       "southeast" : MROOMS"hidden31",       
       "southwest" : MROOMS"hidden29",
    ] ));    
    set_long((string)TO->query_long()+"%^BOLD%^%^BLACK%^ The tunnel "+
    "continues southeast and southwest.%^RESET%^");
}
