#include <std.h>
#include "../inherits/area_stuff.h"
inherit INNER;

void create() 
{
    ::create();
    set_long(TO->query_long()+"%^BOLD%^%^WHITE%^ An opening in the western wall leads "+
    "to another section of the cavern.%^RESET%^");
    set_exits((["west" : CRROOMS+"inner24"]));		

}
