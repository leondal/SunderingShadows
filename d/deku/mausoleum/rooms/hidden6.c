#include <std.h>
#include "../inherits/area_stuff.h"
inherit HID;

void create() 
{
    ::create();   
    set_exits(([
       "northwest" : MROOMS"hidden2",       
       "southeast" : MROOMS"hidden7",
    ] ));    
    set_long((string)TO->query_long()+"%^BOLD%^%^BLACK%^ The tunnel "+
    "continues northwest and southeast.%^RESET%^");
}
