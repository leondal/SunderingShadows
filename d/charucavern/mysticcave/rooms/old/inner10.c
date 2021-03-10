#include <std.h>
#include "../inherits/area_stuff.h"
inherit INNER;

void create() 
{
    ::create();
    set_long(TO->query_long()+"%^BOLD%^%^WHITE%^ Openings in the western and southern walls lead "+
    "to other sections of the cavern.%^RESET%^");
    set_exits((["west" : CRROOMS+"inner1", "south" : CRROOMS+"inner11"]));		

}
