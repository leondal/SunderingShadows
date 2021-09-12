// Chernobog (9/6/21)
// Tharis Hotel

#include <std.h>
#include "../defs.h"
inherit INH+"hallway";

void create(){
    ::create();
    set_long(::query_long()+" %^BOLD%^%^BLACK%^The hallway continues from here, or returns to the grand staircase.%^RESET%^\n");
    set_exits(([
        "north" : ROOMS "hallway2",
        "west" : ROOMS "hotel_room1",
        "east" : ROOMS "hotel_room2",
        "south" : ROOMS "stairs2",
        ]));
    set_door("ebony door", ROOMS "hotel_room1", "west", 0);
	set_door_description("ebony door","%^RESET%^Fashioned from solid %^BOLD%^%^BLACK%^ebony%^RESET%^, this %^BOLD%^%^BLACK%^door %^RESET%^is massive and sturdy in construction. The %^BOLD%^%^BLACK%^door %^RESET%^is adorned with a %^BOLD%^%^BLACK%^s%^RESET%^i%^BOLD%^l%^RESET%^v%^BOLD%^%^BLACK%^er l%^RESET%^o%^BOLD%^c%^BLACK%^ks%^RESET%^e%^BOLD%^%^BLACK%^t %^RESET%^and a matching %^BOLD%^%^BLACK%^pl%^RESET%^a%^BOLD%^%^BLACK%^q%^RESET%^u%^BOLD%^e %^RESET%^that declares this to be room number one.");
    set_door("oak door", ROOMS "hotel_room2", "east", 0);
	set_door_description("oak door","%^RESET%^Fashioned from solid %^ORANGE%^oak%^WHITE%^, this %^ORANGE%^door %^RESET%^is massive and sturdy in construction. The %^ORANGE%^door %^WHITE%^is adorned with a %^BOLD%^%^BLACK%^s%^RESET%^i%^BOLD%^l%^RESET%^v%^BOLD%^%^BLACK%^er l%^RESET%^o%^BOLD%^c%^BLACK%^ks%^RESET%^e%^BOLD%^%^BLACK%^t %^RESET%^and a matching %^BOLD%^%^BLACK%^pl%^RESET%^a%^BOLD%^%^BLACK%^q%^RESET%^u%^BOLD%^e %^RESET%^that declares this to be room number two.");
}

