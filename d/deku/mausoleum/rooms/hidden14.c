#include <std.h>
#include "../inherits/area_stuff.h"
inherit HID;

void create() 
{
    ::create();   
    set_exits(([
       "northeast" : MROOMS"hidden13",       
       "west" : MROOMS"hidden15",
    ] ));    
    set_long((string)TO->query_long()+"%^BOLD%^%^BLACK%^ The tunnel "+
    "continues northeast and west.%^RESET%^");
}
