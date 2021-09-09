// Chernobog (9/6/21)
// Tharis Hotel

#include <std.h>
#include "../defs.h"
inherit INH+"hallway";

void create(){
    ::create();
    set_long(::query_long()+" %^BOLD%^%^BLACK%^The hallway ends here, an impressive floor length %^CYAN%^m%^RESET%^%^CYAN%^i%^BOLD%^rr%^RESET%^%^CYAN%^o%^BOLD%^r %^BLACK%^set against the far wall.%^RESET%^\n");
    add_item("mirror","Bordered by an o%^BOLD%^%^BLACK%^r%^RESET%^n%^BOLD%^a%^BLACK%^te s%^RESET%^i%^BOLD%^l%^RESET%^v%^BOLD%^%^BLACK%^er f%^RESET%^r%^BOLD%^a%^BLACK%^m%^RESET%^e, this floor length %^CYAN%^mi%^BOLD%^rr%^RESET%^%^CYAN%^o%^BOLD%^r %^RESET%^dominates the far wall. It creates %^BOLD%^%^BLACK%^di%^RESET%^s%^BOLD%^o%^CYAN%^r%^RESET%^i%^BOLD%^e%^CYAN%^n%^RESET%^t%^BOLD%^i%^BLACK%^ng i%^RESET%^l%^BOLD%^l%^CYAN%^u%^RESET%^s%^BOLD%^i%^CYAN%^o%^BLACK%^n %^RESET%^that the hallway continues endlessly.%^RESET%^");
    set_exits(([
        "west" : ROOMS "hotel_room3",
        "east" : ROOMS "hotel_room4",
        "south" : ROOMS "hallway1",
        ]));
    set_door("ebony door", ROOMS "hotel_room3", "west", 0);
	set_door_description("ebony door","%^RESET%^Fashioned from solid %^BOLD%^%^BLACK%^ebony%^RESET%^, this %^BOLD%^%^BLACK%^door %^RESET%^is massive and sturdy in construction. The %^BOLD%^%^BLACK%^door %^RESET%^is adorned with a %^BOLD%^%^BLACK%^s%^RESET%^i%^BOLD%^l%^RESET%^v%^BOLD%^%^BLACK%^er l%^RESET%^o%^BOLD%^c%^BLACK%^ks%^RESET%^e%^BOLD%^%^BLACK%^t %^RESET%^and a matching %^BOLD%^%^BLACK%^pl%^RESET%^a%^BOLD%^%^BLACK%^q%^RESET%^u%^BOLD%^e %^RESET%^that declares this to be room number three.");
    set_door("oak door", ROOMS "hotel_room4", "east", 0);
	set_door_description("oak door","%^RESET%^Fashioned from solid %^ORANGE%^oak%^WHITE%^, this %^ORANGE%^door %^RESET%^is massive and sturdy in construction. The %^ORANGE%^door %^WHITE%^is adorned with a %^BOLD%^%^BLACK%^s%^RESET%^i%^BOLD%^l%^RESET%^v%^BOLD%^%^BLACK%^er l%^RESET%^o%^BOLD%^c%^BLACK%^ks%^RESET%^e%^BOLD%^%^BLACK%^t %^RESET%^and a matching %^BOLD%^%^BLACK%^pl%^RESET%^a%^BOLD%^%^BLACK%^q%^RESET%^u%^BOLD%^e %^RESET%^that declares this to be room number four.");
}

