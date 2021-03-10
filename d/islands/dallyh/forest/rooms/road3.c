#include "/d/islands/dallyh/fways.h"

inherit DVIL;

void create()
{
    ::create();
    set_long(TO->query_long()+"%^RESET%^%^ORANGE%^ Three shelters open up here. The one to "+
    "the east looks like it has been set up as a healer, the one to the west appears to have been "+
    "set up as a way of welcoming travelers through food and drink, and the one to the south looks "+
    "particularly interesting, as if it has been set up in preparation for your arrival.%^RESET%^");
        
    add_item(({"shelter", "shelters", "temple"}), "%^RESET%^%^ORANGE%^An opening leads into "+
    "one of the numerous shelters to the west here. From what you can tell it looks to be set up "+
    "like a makeshift temple.%^RESET%^");
    set_exits(([
              "north":FRPATH "road2",
              "south":FRPATH "throne",
              "east" : FRPATH "healer",
              "west":FRPATH "rest",
    ]));
}

