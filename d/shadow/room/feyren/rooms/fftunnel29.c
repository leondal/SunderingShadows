#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFTN;

void create() 
{
    ::create();
    set_long(TO->query_long()+" %^BOLD%^%^MAGENTA%^"+
    "You can continue into the darkness of this "+
    "narrow crack to the east and west.%^RESET%^");
    set_exits( (["east" : FFTR"30", "west" : FFTR"28" ]) ); 	
}
