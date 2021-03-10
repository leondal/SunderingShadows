#include <std.h>
#include "../inherits/area_stuff.h"
inherit HID;

void create() 
{
    ::create();   
    set_exits(([
       "east" : MROOMS"hidden17",       
       "northwest" : MROOMS"hidden19",
    ] ));    
    set_long((string)TO->query_long()+"%^BOLD%^%^BLACK%^ The tunnel "+
    "continues east and northwest.%^RESET%^");
}
