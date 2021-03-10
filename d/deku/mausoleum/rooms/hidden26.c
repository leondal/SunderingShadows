#include <std.h>
#include "../inherits/area_stuff.h"
inherit HID;

void create() 
{
    ::create();   
    set_exits(([
       "north" : MROOMS"hidden27",
       "south" : MROOMS"hidden25",       
    ] ));    
    set_long((string)TO->query_long()+"%^BOLD%^%^BLACK%^ The tunnel continues "+
    "to the north and south.%^RESET%^");    
}
