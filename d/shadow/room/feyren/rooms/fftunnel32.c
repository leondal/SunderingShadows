#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFT;

void create() 
{
    ::create();
    set_long(TO->query_long()+" %^BOLD%^%^YELLOW%^The tunnel continues "+
    "east and west into darkness.%^RESET%^");
    set_exits( ([ "east" : FFTR"26", "west" : FFTR"33"]) ); 
}
