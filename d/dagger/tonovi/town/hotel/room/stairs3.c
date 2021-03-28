// Chernobog (1/5/21)
// Tonovi Hotel

#include <std.h>
#include "../defs.h"
inherit INH+"stairs";

void create(){
    ::create();
    set_long(::query_long()+" This landing is brought short by a %^ORANGE%^large oak "+
        "door%^RESET%^, standing solid and imposing.\n");
    set_exits(([
        "north" : ROOMS "drawing_room",
        "down" : ROOMS "stairs2",
        ]));
    set_door("oak door", ROOMS "drawing_room", "north", 0);
	set_door_description("oak door","%^RESET%^%^CYAN%^Fashioned from %^ORANGE%^solid oak"+
        "%^CYAN%^, this door is massive and sturdy in construction. A %^YELLOW%^br"+
        "%^RESET%^%^ORANGE%^a%^BOLD%^s%^RESET%^%^ORANGE%^s %^BOLD%^k%^RESET%^%^ORANGE%^n"+
        "%^BOLD%^ob %^RESET%^%^CYAN%^and %^YELLOW%^k%^RESET%^%^ORANGE%^e%^BOLD%^yh"+
        "%^RESET%^%^ORANGE%^o%^BOLD%^le %^RESET%^%^CYAN%^have been inset to one side, "+
        "and a %^YELLOW%^br%^RESET%^%^ORANGE%^a%^BOLD%^s%^RESET%^%^ORANGE%^s %^BOLD%^pl"+
        "%^RESET%^%^ORANGE%^a%^BOLD%^qu%^RESET%^%^ORANGE%^e %^CYAN%^declares this to be "+
        "the %^YELLOW%^D%^RESET%^%^ORANGE%^u%^BOLD%^%^BLACK%^c%^RESET%^%^ORANGE%^a"+
        "%^BOLD%^l S%^RESET%^%^ORANGE%^u%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^t%^BOLD%^e"+
        "%^RESET%^%^CYAN%^.%^RESET%^");
}

