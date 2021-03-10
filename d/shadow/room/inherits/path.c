#include <std.h>
#include "../shadow.h"

inherit ROOM;

void create(){
    ::create();
    set_property("light",2);
    set_name("Path along the wall");
    set_short("%^RESET%^%^ORANGE%^Path along the wall%^RESET%^");
    set_terrain(ROCKY);
    set_travel(RUTTED_TRACK);
    set_long("%^RESET%^%^GREEN%^This weathered path arounds around the city of %^BOLD%^%^WHITE%^Shadow%^RESET%^%^GREEN%^"+
      " and maintains steady use. While not the busiest of roots, this trail is"+
      " most often used by wagons and other caravans looking to avoid the taxes"+
      " of traveling the the big city streets. To the west you see the %^BOLD%^%^GREEN%^lush trees%^RESET%^%^GREEN"+
      " of the forest. The high %^BOLD%^%^WHITE%^stone walls%^RESET%^%^GREEN%^ to the east"+
      " block your view of the city, but you can hear the hustle and bustle no matter"+
       " the time of day.");
    set_listen("default","%^RESET%^%^CYAN%^You hear the endless hustle and bustle of the city to the east.%^RESET%^");
}
