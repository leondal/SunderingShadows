#include <std.h>
#include "../inherits/area_stuff.h"
inherit HID;

void create() 
{
    ::create();   
    set_exits(([
       "north" : MROOMS"hidden3",
       "southwest" : MROOMS"hidden1", 
       "southeast" : MROOMS"hidden6",
    ] ));    
    set_long((string)TO->query_long()+"%^BOLD%^%^BLACK%^ The tunnel "+
    "splits to the north, southeast, and southwest.%^RESET%^");
}
