// Chernobog (1/5/21)
// Tonovi Hotel

#include <std.h>
#include "../defs.h"
inherit INH+"hallway";

void create(){
    ::create();
    set_long(::query_long()+" The hallway ends here, with an %^YELLOW%^im%^RESET%^"+
        "%^ORANGE%^p%^BOLD%^re%^RESET%^%^ORANGE%^s%^BOLD%^si%^RESET%^%^ORANGE%^v"+
        "%^BOLD%^e %^BLACK%^m%^RESET%^i%^BOLD%^rr%^RESET%^o%^BOLD%^%^BLACK%^r %^RESET%^"+
        "set against the far wall.%^RESET%^\n");
    add_item("mirror","%^RESET%^%^CYAN%^Bordered with an elaborate %^YELLOW%^g%^WHITE%^o"+
        "%^ORANGE%^ld l%^WHITE%^e%^ORANGE%^af f%^RESET%^%^ORANGE%^r%^BOLD%^am%^RESET%^"+
        "%^ORANGE%^e%^CYAN%^, this floor length %^BOLD%^%^BLACK%^m%^RESET%^i%^BOLD%^rr"+
        "%^RESET%^o%^BOLD%^%^BLACK%^r %^RESET%^%^CYAN%^dominates the far wall. It is so "+
        "%^BOLD%^clear%^RESET%^%^CYAN%^, so %^BOLD%^flawless%^RESET%^%^CYAN%^, that it "+
        "appears as if the hallway continues on into some bizarre inverse world."+
        "%^RESET%^");
    set_exits(([
        "west" : ROOMS "hotel_room3",
        "east" : ROOMS "hotel_room4",
        "south" : ROOMS "hallway1",
        ]));
    set_door("ebony door", ROOMS "hotel_room3", "west", 0);
	set_door_description("ebony door","%^RESET%^%^CYAN%^Fashioned from %^BOLD%^%^BLACK%^"+
        "solid ebony%^RESET%^%^CYAN%^, this door is massive and sturdy in construction. "+
        "A %^YELLOW%^br%^RESET%^%^ORANGE%^a%^BOLD%^s%^RESET%^%^ORANGE%^s %^BOLD%^k"+
        "%^RESET%^%^ORANGE%^n%^BOLD%^ob %^RESET%^%^CYAN%^and %^YELLOW%^k%^RESET%^"+
        "%^ORANGE%^e%^BOLD%^yh%^RESET%^%^ORANGE%^o%^BOLD%^le %^RESET%^%^CYAN%^have been "+
        "inset to one side, and a %^YELLOW%^br%^RESET%^%^ORANGE%^a%^BOLD%^s%^RESET%^"+
        "%^ORANGE%^s %^BOLD%^pl%^RESET%^%^ORANGE%^a%^BOLD%^qu%^RESET%^%^ORANGE%^e "+
        "%^CYAN%^declares this to be room number three.%^RESET%^");
    set_door("oak door", ROOMS "hotel_room4", "east", 0);
	set_door_description("oak door","%^RESET%^%^CYAN%^Fashioned from %^ORANGE%^solid oak"+
        "%^CYAN%^, this door is massive and sturdy in construction. A %^YELLOW%^br"+
        "%^RESET%^%^ORANGE%^a%^BOLD%^s%^RESET%^%^ORANGE%^s %^BOLD%^k%^RESET%^%^ORANGE%^n"+
        "%^BOLD%^ob %^RESET%^%^CYAN%^and %^YELLOW%^k%^RESET%^%^ORANGE%^e%^BOLD%^yh"+
        "%^RESET%^%^ORANGE%^o%^BOLD%^le %^RESET%^%^CYAN%^have been inset to one side, "+
        "and a %^YELLOW%^br%^RESET%^%^ORANGE%^a%^BOLD%^s%^RESET%^%^ORANGE%^s %^BOLD%^pl"+
        "%^RESET%^%^ORANGE%^a%^BOLD%^qu%^RESET%^%^ORANGE%^e %^CYAN%^declares this to be "+
        "room number four.%^RESET%^");
}

