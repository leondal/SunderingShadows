#include <std.h>
#include "../inherits/area_stuff.h"
inherit INNER;

void create() 
{
    ::create();
    set_long(TO->query_long()+"%^BOLD%^%^WHITE%^ Openings in the northern and southern walls lead "+
    "to other sections of the cavern.%^RESET%^");
    set_exits((["south" : CRROOMS+"inner22", "north" : CRROOMS+"inner20"]));		

}
