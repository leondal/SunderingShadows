#include <std.h>
#include "../inherits/area_stuff.h"
inherit INNER;

void create() 
{
    ::create();
    set_long(TO->query_long()+"%^BOLD%^%^WHITE%^ Openings in the northern, southern, and western walls lead "+
    "to other sections of the cavern.%^RESET%^");
    set_exits((["north" : CRROOMS+"inner21", "south" : CRROOMS+"inner23", "west" : CRROOMS+"inner27"]));		

}
