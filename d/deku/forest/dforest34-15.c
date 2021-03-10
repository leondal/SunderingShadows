#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();
    set_long(TO->query_long()+"  %^BOLD%^%^BLACK%^A massive tower "+
    "rests in the woods west of here.%^RESET%^");
    set_exits(([
       "west" : F_ROOMS"35-15",
       "east" : F_ROOMS"33-15",
       "south" : F_ROOMS"34-14",
       "north" : F_ROOMS"34-16",
       "northwest" : F_ROOMS"35-16",
       "southwest" : F_ROOMS"35-14",
       "southeast" : F_ROOMS"33-14",
       "northeast" : F_ROOMS"33-16"
       
    ] ));
}
