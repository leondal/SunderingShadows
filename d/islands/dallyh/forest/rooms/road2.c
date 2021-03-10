#include "/d/islands/dallyh/fways.h"

inherit DVIL;

void create()
{
    ::create();
    set_long(TO->query_long()+"%^RESET%^%^ORANGE%^ One of the shelters opens up to "+
    "the west here. It appears to have been set up like a makeshift temple.%^RESET%^");
    
    add_item(({"shelter", "shelters", "temple"}), "%^RESET%^%^ORANGE%^An opening leads into "+
    "one of the numerous shelters to the west here. From what you can tell it looks to be set up "+
    "like a makeshift temple.%^RESET%^");
    set_exits(([
        "north":FRPATH "road1",
        "south":FRPATH "road3",
        "west": FRPATH "church",
    ]));
}

