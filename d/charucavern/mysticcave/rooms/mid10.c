#include <std.h>
#include "../inherits/area_stuff.h"
inherit MID;

void create() 
{
    ::create();
    set_long(TO->query_long() + "%^BOLD%^%^CYAN%^ The air stirs here, though it "+
    "does little to help with the stagnation that hangs in the air.%^RESET%^");
    set_exits((["west" : CRROOMS+"mid9", "south" : CRROOMS +"mid11"]));		
}
