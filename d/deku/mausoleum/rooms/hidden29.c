#include <std.h>
#include "../inherits/area_stuff.h"
inherit HID;

void create() 
{
    ::create();   
    set_exits(([
       "northeast" : MROOMS"hidden30",       
       "west" : MROOMS"hidden25",
    ] ));    
    set_long((string)TO->query_long()+"%^BOLD%^%^BLACK%^ The tunnel "+
    "continues northeast and west.%^RESET%^");
}
