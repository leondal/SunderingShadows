#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFTE;

void create() 
{
    ::create();
    set_long(TO->query_long()+" %^BOLD%^%^YELLOW%^The tunnel comes to an "+
    "end here. An opening to the west leads into darkness.%^RESET%^");
    set_exits( (["west" : FFTR"24" ]) ); 	
}
