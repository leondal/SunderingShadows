#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFT;

void create() 
{
    ::create();
    set_long(TO->query_long()+" %^BOLD%^%^YELLOW%^The tunnel continues "+
    "northeast and west into darkness.%^RESET%^");
    set_exits( ([ "northeast" : FFTR"17", "west" : FFTR"19" ]) ); 
}
