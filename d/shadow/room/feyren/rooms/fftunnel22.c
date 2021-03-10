#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFT;

void create() 
{
    ::create();
    set_long(TO->query_long()+" %^BOLD%^%^YELLOW%^The tunnel continues "+
    "northeast, southeast, and southwest into darkness.%^RESET%^");
    set_exits( ([ "northeast" : FFTR"16", "southeast" : FFTR"24", "southwest" : FFTR"23" ]) ); 
}
