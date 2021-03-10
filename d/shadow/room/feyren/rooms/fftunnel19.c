#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFT;

void create() 
{
    ::create();
    set_long(TO->query_long()+" %^BOLD%^%^YELLOW%^The tunnel continues "+
    "east, south, and northwest into darkness.%^RESET%^");
    set_exits( ([ "east" : FFTR"18", "south" : FFTR"21", "northwest" : FFTR"20" ]) ); 
}
