#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFT;

void create() 
{
    ::create();
    set_long(TO->query_long()+" %^BOLD%^%^YELLOW%^The tunnel continues "+
    "north and south into darkness.%^RESET%^");
    set_exits( ([ "south" : FFTR"38", "north" : FFTR"34"]) ); 
}
