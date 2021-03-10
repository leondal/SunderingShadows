#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFTN;

void create() 
{
    ::create();
    set_long(TO->query_long()+" %^BOLD%^%^MAGENTA%^"+
    "You can continue into the darkness of this "+
    "narrow crack to the east. It opens into a much "+
    "larger tunnel to the west.%^RESET%^");
    set_exits( (["east" : FFTR"29", "west" : FFTR"27" ]) ); 	
}
