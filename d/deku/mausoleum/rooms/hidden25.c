#include <std.h>
#include "../inherits/area_stuff.h"
inherit HID;

void create() 
{
    ::create();   
    set_exits(([
       "north" : MROOMS"hidden26",
       "east" : MROOMS"hidden29",       
       "southwest" : MROOMS"hidden24",
    ] ));    
    set_long((string)TO->query_long()+"%^BOLD%^%^BLACK%^ The tunnel splits "+
    "to the north, east, and southwest.%^RESET%^");    
}
