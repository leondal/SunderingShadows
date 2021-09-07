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
    set_name("Grand Staircase");
    set_short("%^MAGENTA%^G%^BOLD%^%^BLACK%^ran%^RESET%^%^MAGENTA%^d S%^BOLD%^%^BLACK%^taircas%^RESET%^%^MAGENTA%^e%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^Gently s%^RESET%^p%^BOLD%^i%^BLACK%^r%^RESET%^a%^BOLD%^l%^BLACK%^i%^RESET%^n%^BOLD%^g %^BLACK%^counter-clockwise as it climbs between floors, the grand staircase is impressive in scope. Each step is fully a man's length in width and half as deep, fashioned from that same %^RESET%^l%^BOLD%^%^BLACK%^u%^WHITE%^s%^RESET%^t%^BOLD%^%^BLACK%^r%^WHITE%^o%^RESET%^u%^BOLD%^%^BLACK%^s eb%^RESET%^o%^BOLD%^%^BLACK%^ny as the fl%^RESET%^o%^BOLD%^o%^BLACK%^rs. A %^RESET%^%^MAGENTA%^dark violet %^BOLD%^%^BLACK%^runner lines the staircase, easily muffling any footsteps%^RESET%^. %^BOLD%^%^BLACK%^The %^WHITE%^polished %^BLACK%^ebony banisters are connected to the staircase by intricate ir%^RESET%^o%^BOLD%^%^BLACK%^nw%^RESET%^o%^BOLD%^%^BLACK%^rk spindles.");
    set_smell("default","The air carries a mix of white tea and vanilla, with a hint of cedar.");
    set_listen("default","You hear the gentle susurrus of patrons coming and going.");
    set_items(([
        ({"wall", "walls"}) : "%^BOLD%^%^BLACK%^Large slabs of %^RESET%^polished %^BOLD%^%^BLACK%^m%^RESET%^a%^BOLD%^r%^BLACK%^bl%^WHITE%^e %^BLACK%^shot through with veins of %^WHITE%^wh%^RESET%^i%^BOLD%^te %^BLACK%^comprise these walls.%^RESET%^",
        ({"stairs", "staircase"}) : "The %^BOLD%^%^BLACK%^stairs %^RESET%^are broad and expansive, and any footsteps are %^BOLD%^%^BLACK%^silenced %^RESET%^thanks to the thick %^MAGENTA%^violet runner%^WHITE%^.",
        "bannisters" : "%^RESET%^Soft and smooth to the touch, the %^BOLD%^%^BLACK%^banister %^RESET%^is made from lustrous ebony. Intricate %^BOLD%^%^BLACK%^iron spindles %^RESET%^support the railing, with an occasional artistic %^BOLD%^%^BLACK%^s%^RESET%^w%^BOLD%^i%^RESET%^r%^BOLD%^%^BLACK%^l %^RESET%^present in the %^BOLD%^%^BLACK%^ir%^RESET%^o%^BOLD%^%^BLACK%^nw%^RESET%^o%^BOLD%^%^BLACK%^rk l%^RESET%^a%^BOLD%^%^BLACK%^tt%^RESET%^i%^BOLD%^%^BLACK%^c%^RESET%^e.",
        ]));
}

