#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit NFTRAIL;

void create() {
    ::create();
    set_long(TO->query_long()+"  %^BOLD%^%^BLACK%^A massive tower "+
    "rests in the woods south of here.%^RESET%^");
    set_exits(([
       "east" : F_ROOMS"34-16",
       "west" : F_ROOMS"36-16",
       "south" : F_ROOMS"35-15",
       "southwest" : F_ROOMS"36-15",
       "southeast" : F_ROOMS"34-15",       
    ] ));
}
