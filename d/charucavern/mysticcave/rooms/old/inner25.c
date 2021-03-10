#include <std.h>
#include "../inherits/area_stuff.h"
inherit INNER;

void create() 
{
    ::create();
    set_long(TO->query_long()+"%^BOLD%^%^WHITE%^ Openings in the northern and eastern walls lead "+
    "to other sections of the cavern.%^RESET%^");
    set_exits((["north" : CRROOMS+"inner26", "east" : CRROOMS+"inner24"]));		

}
