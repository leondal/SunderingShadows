#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();
    set_long(TO->query_long()+"  %^BOLD%^%^BLACK%^A massive tower "+
    "rests in the woods northwest of here.%^RESET%^");
    set_exits(([
       "west" : F_ROOMS"35-14",
       "east" : F_ROOMS"33-14",
       "south" : F_ROOMS"34-13",
       "north" : F_ROOMS"34-15",
       "northwest" : F_ROOMS"35-15",
       "southwest" : F_ROOMS"35-13",
       "southeast" : F_ROOMS"33-13",
       "northeast" : F_ROOMS"33-15",       
    ] ));
}
