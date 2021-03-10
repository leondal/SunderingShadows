#include <std.h>
#include "../inherits/area_stuff.h"
inherit UPPER;

void create() 
{
    ::create();
    
    /*set_long(TO->query_long() + "%^BOLD%^%^CYAN%^ A slight breeze is felt here, though it "+
    "does little to help with the stagnation that hangs in the air.%^RESET%^");*/

    set_exits((["north" : CRROOMS+"upperout", "east" : CRROOMS +"upper2"]));		
}
