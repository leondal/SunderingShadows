#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFT;

void create() 
{
    ::create();
    set_long(TO->query_long()+" %^BOLD%^%^YELLOW%^The tunnel continues "+
    "northeast, southeast, and west into darkness.%^RESET%^");
    set_exits( ([ "northeast" : FFTR"23", "southeast" : FFTR"27", "west" : FFTR"32" ]) ); 
}
