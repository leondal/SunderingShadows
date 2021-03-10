#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();
    set_short("%^YELLOW%^A dirt trail through the forest.%^RESET%^");
    
    set_long(TO->query_long()+"  %^BOLD%^%^BLACK%^A %^YELLOW%^dirt "+
    "trail%^BOLD%^%^BLACK%^ here leads east up to the bank "+
    "of a large %^BLUE%^lake%^BOLD%^%^BLACK%^ or west "+
    "through the forest.%^RESET%^");

    add_items(({"lake","large lake","shadowlord lake"}),"%^BLUE%^"+
    "Only the bank of this large lake is visible from here and "+
    "what you can make out of its surface paints it a "+
    "blue-green.%^RESET%^"); 

    set_exits(([
       "west" : F_ROOMS"34-5",
       "east" : F_ROOMS"32-5",
       "north" : F_ROOMS"33-6",
       "south" : F_ROOMS"33-4",
       "southeast" : F_ROOMS"32-4",
       "southwest" : F_ROOMS"34-4",
       "northeast" : F_ROOMS"32-6",
       "northwest" : F_ROOMS"34-6",
    ] ));
    bandit_ambush("west","east","west",TO);
}
