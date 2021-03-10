#include <std.h>
#include "../inherits/area_stuff.h"
inherit HID;

void create() 
{
    ::create();   
    set_exits(([
       "northeast" : MROOMS"hidden12",       
       "southwest" : MROOMS"hidden14",
    ] ));    
    set_long((string)TO->query_long()+"%^BOLD%^%^BLACK%^ The tunnel "+
    "continues northeast and southwest.%^RESET%^");
}
