#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFT;

void create() 
{
    ::create();
    set_long(TO->query_long()+" %^BOLD%^%^YELLOW%^The tunnel continues "+
    "north, east, and south into darkness.%^RESET%^");
    set_exits( ([ "east" : FFTR"33", "north" : FFTR"35", "south" : FFTR"37"]) ); 
}
