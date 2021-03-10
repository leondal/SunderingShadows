#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFT;

void create() 
{
    ::create();
    set_long(TO->query_long()+" %^BOLD%^%^YELLOW%^The tunnel continues "+
    "east, south, and southwest into darkness.%^RESET%^");
    set_exits( ([ "east" : FFTR"5", "southwest" : FFTR"3", "south" : FFTR"6" ]) ); 
}
