#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFT;

void create() 
{
    ::create();
    set_long(TO->query_long()+" %^BOLD%^%^YELLOW%^The tunnel continues "+
    "northeast and northwest into darkness.%^RESET%^");
    set_exits( ([ "northwest" : FFTR"10", "northeast" : FFTR"12"]) ); 
}
