#include <std.h>
#include "../inherits/area_stuff.h"
inherit OUTTER2;

void create() 
{
    ::create();
    set_long(TO->query_long()+"%^RESET%^%^ORANGE%^ A rickety wooden ladder leads up to the path far overhead.%^RESET%^");
    set_exits((["south" : CRROOMS+"out12", "southeast" : CRROOMS+"out17", "southwest" : CRROOMS+"out16", "ladder" : CRROOMS+"out6"]));		

}
