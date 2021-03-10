#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFT;

void create() 
{
    ::create();
    set_long(TO->query_long()+" %^BOLD%^%^YELLOW%^The tunnel continues "+
    "northwest, southeast, and southwest into darkness.%^RESET%^");
    set_exits( ([ "southwest" : FFTR"14", "southeast" : FFTR"11", "northwest" : FFTR"9"]) ); 

}
