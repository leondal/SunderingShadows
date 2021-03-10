#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFT;

void create() 
{
    ::create();
    set_long(TO->query_long()+" %^BOLD%^%^YELLOW%^The tunnel continues "+
    "to the northwest into darkness and opens up into a much "+
    "larger chamber directly to the east.%^RESET%^");
    set_exits( ([ "east" : FFTR"40", "northwest" : FFTR"38"]) ); 
}
