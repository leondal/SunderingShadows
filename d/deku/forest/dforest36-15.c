#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();
     set_long(TO->query_long()+"  %^BOLD%^%^BLACK%^A massive tower "+
    "rests in the woods east of here.%^RESET%^");
    set_exits(([
       "west" : F_ROOMS"37-15",
       "east" : F_ROOMS"35-15",
       "south" : F_ROOMS"36-14",
       "north" : F_ROOMS"36-16",
       "northwest" : F_ROOMS"37-16",
       "southeast" : F_ROOMS"35-14",
       "northeast" : F_ROOMS"35-16"
       
    ] ));
}
