#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFT;

void create() 
{
    ::create();
    set_long(TO->query_long()+" %^BOLD%^%^YELLOW%^The tunnel continues "+
    "southeast and southwest into darkness.%^RESET%^");
    set_exits( ([ "southeast" : FFTR"16", "southwest" : FFTR"18" ]) ); 
}
