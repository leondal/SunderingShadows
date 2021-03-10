#include <std.h>
#include "../inherits/area_stuff.h"
inherit HID;

void create() 
{
    ::create();   
    set_exits(([
       "southeast" : MROOMS"hidden16",       
       "west" : MROOMS"hidden18",
    ] ));    
    set_long((string)TO->query_long()+"%^BOLD%^%^BLACK%^ The tunnel "+
    "continues southeast and west.%^RESET%^");
}
