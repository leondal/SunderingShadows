// Chernobog (9/6/21)
// Tharis Hotel

#include <std.h>
#include "../defs.h"
inherit INH+"stairs";

void create(){
    ::create();
    set_long(::query_long()+" There is a landing here that leads to a large %^RESET%^%^ORANGE%^oak %^BOLD%^%^BLACK%^door, standing solid and imposing. The staircase winds further upward but there is a black velvet rope barring anyone from ascending, a sign in %^RESET%^%^MAGENTA%^elegant script %^BOLD%^%^BLACK%^reads %^RESET%^ '%^RESET%^%^MAGENTA%^Under Construction%^BOLD%^%^BLACK%^'.%^RESET%^\n");
    set_exits(([
        "north" : ROOMS "drawing_room",
        "down" : ROOMS "stairs2",
        ]));
    set_door("oak door", ROOMS "drawing_room", "north", 0);
	set_door_description("oak door","%^RESET%^Fashioned from solid %^ORANGE%^oak%^WHITE%^, this %^ORANGE%^door %^RESET%^is massive and sturdy in construction. The %^ORANGE%^door %^WHITE%^is adorned with a %^BOLD%^%^BLACK%^s%^RESET%^i%^BOLD%^l%^RESET%^v%^BOLD%^%^BLACK%^er l%^RESET%^o%^BOLD%^c%^BLACK%^ks%^RESET%^e%^BOLD%^%^BLACK%^t %^RESET%^and a matching %^BOLD%^%^BLACK%^pl%^RESET%^a%^BOLD%^%^BLACK%^q%^RESET%^u%^BOLD%^e %^RESET%^that declares this to be the Grand Suite.%^RESET%^");
}

