#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFT;

void create() 
{
    ::create();
    set_long(TO->query_long()+" %^BOLD%^%^YELLOW%^The tunnel continues "+
    "north and southeast into darkness.%^RESET%^");
    set_exits( ([ "southeast" : FFTR"39", "north" : FFTR"37"]) ); 
}
