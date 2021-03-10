#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFT;

void create() 
{
    ::create();
    set_long(TO->query_long()+" %^BOLD%^%^YELLOW%^The tunnel continues "+
    "south and northwest into darkness.%^RESET%^");
    set_exits( ([ "south" : FFTR"34", "northwest" : FFTR"36"]) ); 
}
