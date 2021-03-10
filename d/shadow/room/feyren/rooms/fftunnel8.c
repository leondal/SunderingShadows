#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFTE;

void create() 
{
    ::create();
    set_long(TO->query_long()+" %^BOLD%^%^YELLOW%^The tunnel comes to an "+
    "end here. An opening to the northwest leads into darkness.%^RESET%^");
    set_exits( (["northwest" : FFTR"7" ]) ); 	
}
