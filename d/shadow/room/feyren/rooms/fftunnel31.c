#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFTN;

void create() 
{
    ::create();
    set_long(TO->query_long()+" %^BOLD%^%^MAGENTA%^"+
    "You can continue into the darkness of this "+
    "narrow crack to the west. It opens into a much "+
    "larger tunnel to the east.%^RESET%^");
    set_exits( (["east" : FFTR"15", "west" : FFTR"30" ]) ); 	
}
