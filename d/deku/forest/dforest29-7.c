#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();
    set_long(TO->query_long()+"  %^BOLD%^%^BLACK%^The bank of a "+
    "large %^BLUE%^lake%^BOLD%^%^BLACK%^ is visible to the west "+
    "of here.%^RESET%^");
    add_items(({"lake","large lake","shadowlord lake"}),"%^BLUE%^"+
    "Only the bank of this large lake is visible from here and "+
    "what you can make out of its surface paints it a "+
    "blue-green.%^RESET%^"); 
    set_exits(([
       "west" : F_ROOMS"30-7",
       "east" : F_ROOMS"28-7",
       "north" : F_ROOMS"29-8",
       "south" : F_ROOMS"29-6",
       "southeast" : F_ROOMS"28-6",
       "southwest" : F_ROOMS"30-6",
       "northeast" : F_ROOMS"28-8",
       "northwest" : F_ROOMS"30-8",
    ] ));
}
