// Chernobog (1/5/21)
// Tonovi Hotel

#include <std.h>
#include "../defs.h"
inherit INH+"hallway";

void create(){
    ::create();
    set_long(::query_long()+" The hallway continues from here, or returns to the grand "+
        "staircase.\n");
    set_exits(([
        "north" : ROOMS "hallway2",
        "west" : ROOMS "hotel_room1",
        "east" : ROOMS "hotel_room2",
        "south" : ROOMS "stairs2",
        ]));
    set_door("ebony door", ROOMS "hotel_room1", "west", 0);
	set_door_description("ebony door","%^RESET%^%^CYAN%^Fashioned from %^BOLD%^%^BLACK%^"+
        "solid ebony%^RESET%^%^CYAN%^, this door is massive and sturdy in construction. "+
        "A %^YELLOW%^br%^RESET%^%^ORANGE%^a%^BOLD%^s%^RESET%^%^ORANGE%^s %^BOLD%^k"+
        "%^RESET%^%^ORANGE%^n%^BOLD%^ob %^RESET%^%^CYAN%^and %^YELLOW%^k%^RESET%^"+
        "%^ORANGE%^e%^BOLD%^yh%^RESET%^%^ORANGE%^o%^BOLD%^le %^RESET%^%^CYAN%^have been "+
        "inset to one side, and a %^YELLOW%^br%^RESET%^%^ORANGE%^a%^BOLD%^s%^RESET%^"+
        "%^ORANGE%^s %^BOLD%^pl%^RESET%^%^ORANGE%^a%^BOLD%^qu%^RESET%^%^ORANGE%^e "+
        "%^CYAN%^declares this to be room number one.%^RESET%^");
    set_door("oak door", ROOMS "hotel_room2", "east", 0);
	set_door_description("oak door","%^RESET%^%^CYAN%^Fashioned from %^ORANGE%^solid oak"+
        "%^CYAN%^, this door is massive and sturdy in construction. A %^YELLOW%^br"+
        "%^RESET%^%^ORANGE%^a%^BOLD%^s%^RESET%^%^ORANGE%^s %^BOLD%^k%^RESET%^%^ORANGE%^n"+
        "%^BOLD%^ob %^RESET%^%^CYAN%^and %^YELLOW%^k%^RESET%^%^ORANGE%^e%^BOLD%^yh"+
        "%^RESET%^%^ORANGE%^o%^BOLD%^le %^RESET%^%^CYAN%^have been inset to one side, "+
        "and a %^YELLOW%^br%^RESET%^%^ORANGE%^a%^BOLD%^s%^RESET%^%^ORANGE%^s %^BOLD%^pl"+
        "%^RESET%^%^ORANGE%^a%^BOLD%^qu%^RESET%^%^ORANGE%^e %^CYAN%^declares this to be "+
        "room number two.%^RESET%^");
}

