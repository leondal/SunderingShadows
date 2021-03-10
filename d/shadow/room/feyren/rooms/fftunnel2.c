#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFT;

void create() 
{
    ::create();
    set_long(TO->query_long()+" %^BOLD%^%^YELLOW%^The tunnel continues "+
    "to the northeast and the southwest into darkness.%^RESET%^");
    set_exits( ([ "southwest" : FFTR"1", "northeast" : FFTR"3"]) ); 
}
