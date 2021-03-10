#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFT;

void create() 
{
    ::create();
    set_long(TO->query_long()+" %^BOLD%^%^YELLOW%^The tunnel continues "+
    "northwest and east into darkness.%^RESET%^");
    set_exits( ([ "northwest" : FFTR"22", "east" : FFTR"25" ]) ); 
}
