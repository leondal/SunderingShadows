// Chernobog (9/6/21)
// Tharis Hotel

#include <std.h>
#include "../defs.h"
inherit VAULT;

void create(){
    ::create();
    set_terrain(WOOD_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_property("indoors", 1);
    set_name("Hotel Hallway");
    set_short("%^MAGENTA%^H%^BOLD%^%^BLACK%^ote%^RESET%^%^MAGENTA%^l H%^BOLD%^%^BLACK%^allwa%^RESET%^%^MAGENTA%^y%^WHITE%^");
    set_long("%^BOLD%^%^BLACK%^The hallway stretches north and south, with a pair of d%^RESET%^%^ORANGE%^oo%^BOLD%^%^BLACK%^rs on either side. A %^RESET%^%^MAGENTA%^violet runner %^BOLD%^%^BLACK%^spans the length of the hallway, protecting the %^RESET%^l%^BOLD%^%^BLACK%^u%^WHITE%^s%^RESET%^t%^BOLD%^%^BLACK%^r%^WHITE%^o%^RESET%^u%^BOLD%^%^BLACK%^s eb%^RESET%^o%^BOLD%^%^BLACK%^ny fl%^RESET%^o%^BOLD%^o%^BLACK%^rs. Small s%^RESET%^i%^BOLD%^l%^RESET%^v%^BOLD%^%^BLACK%^er pl%^RESET%^a%^BOLD%^%^BLACK%^q%^RESET%^u%^BOLD%^e%^BLACK%^s on each door display the room number in a f%^RESET%^l%^BOLD%^o%^RESET%^w%^BOLD%^%^BLACK%^ing sc%^RESET%^r%^BOLD%^i%^RESET%^p%^BOLD%^%^BLACK%^t, c%^RESET%^o%^BOLD%^%^BLACK%^ntr%^RESET%^a%^BOLD%^%^BLACK%^st%^RESET%^i%^BOLD%^%^BLACK%^ng pleasantly against the eb%^RESET%^o%^BOLD%^%^BLACK%^ny and %^RESET%^%^ORANGE%^oak %^BOLD%^%^BLACK%^doors that stand opposite each other.%^RESET%^");
    set_smell("default","The air carries a mix of white tea and vanilla, with a hint of cedar.");
    set_listen("default","It is very quiet here.");
    set_items(([
        ({"wall", "walls"}) : "%^BOLD%^%^BLACK%^Large slabs of %^RESET%^polished %^BOLD%^%^BLACK%^m%^RESET%^a%^BOLD%^r%^BLACK%^bl%^WHITE%^e %^BLACK%^shot through with v%^RESET%^e%^BOLD%^i%^BLACK%^ns of %^WHITE%^wh%^RESET%^i%^BOLD%^te %^BLACK%^comprise these walls.%^RESET%^",
        "floor" : "%^RESET%^Solid %^BOLD%^%^BLACK%^ebony floorboards %^RESET%^lay beneath your feet in a %^BOLD%^%^BLACK%^h%^RESET%^e%^BOLD%^r%^RESET%^r%^BOLD%^%^BLACK%^i%^RESET%^n%^BOLD%^g%^RESET%^b%^BOLD%^%^BLACK%^o%^RESET%^n%^BOLD%^e %^RESET%^pattern, the %^BOLD%^%^BLACK%^black wood p%^RESET%^o%^BOLD%^%^BLACK%^l%^WHITE%^i%^BLACK%^sh%^RESET%^e%^BOLD%^%^BLACK%^d %^RESET%^to a %^BOLD%^reflective %^BLACK%^sh%^RESET%^e%^BOLD%^e%^BLACK%^n%^RESET%^.",
        ({"runner", "carpet"}) : "%^MAGENTA%^Deep %^WHITE%^and %^MAGENTA%^dark violet%^WHITE%^, this thick %^MAGENTA%^runner %^WHITE%^spans the entire length of the hallway. ",
        ]));
}

