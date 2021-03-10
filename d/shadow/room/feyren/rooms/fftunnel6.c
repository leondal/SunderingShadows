#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFT;

void create() 
{
    ::create();
    set_long(TO->query_long()+" %^BOLD%^%^YELLOW%^The tunnel continues "+
    "north and south into darkness.%^RESET%^");
    set_exits( ([ "north" : FFTR"4", "south" : FFTR"7" ]) ); 
}
