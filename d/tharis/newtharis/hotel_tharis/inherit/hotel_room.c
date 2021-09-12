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
    set_name("Hotel Room");
    set_short("%^MAGENTA%^H%^BOLD%^%^BLACK%^ote%^RESET%^%^MAGENTA%^l R%^BOLD%^%^BLACK%^oo%^RESET%^%^MAGENTA%^m%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^An inviting, spacious four poster bed dominates the room. A nightstand within reach of the bed displays a small s%^RESET%^i%^BOLD%^l%^RESET%^v%^BOLD%^%^BLACK%^er b%^RESET%^e%^BOLD%^l%^BLACK%^l. One corner of the room hosts a tall %^RESET%^wardrobe %^BOLD%^%^BLACK%^and %^RESET%^chest %^BOLD%^%^BLACK%^of drawers for the use by hotel guests. A simple f%^RESET%^i%^BOLD%^%^BLACK%^r%^WHITE%^e%^BLACK%^pl%^RESET%^a%^BOLD%^%^BLACK%^c%^WHITE%^e %^BLACK%^lurks to the side of the room with an ornate ir%^RESET%^o%^BOLD%^%^BLACK%^n scr%^RESET%^ee%^BOLD%^%^BLACK%^n banking the %^RED%^f%^RESET%^%^RED%^l%^ORANGE%^a%^BOLD%^m%^RESET%^%^RED%^e%^BOLD%^s%^BLACK%^, and a thick %^RESET%^%^MAGENTA%^rug %^BOLD%^%^BLACK%^has been placed in front of it, greedily absorbing the %^RESET%^%^RED%^w%^BOLD%^a%^RESET%^%^RED%^rmth%^BOLD%^%^BLACK%^. The st%^RESET%^o%^BOLD%^%^BLACK%^n%^WHITE%^e %^BLACK%^w%^RESET%^a%^BOLD%^%^BLACK%^lls have been adorned with a few tasteful %^RED%^p%^ORANGE%^ai%^GREEN%^n%^BLUE%^t%^RESET%^%^MAGENTA%^i%^BOLD%^n%^RED%^g%^RESET%^%^ORANGE%^s %^BOLD%^%^BLACK%^to complete the decor.%^RESET%^ \n");
    set_smell("default","The air carries a mix of white tea and vanilla, with a hint of cedar.");
    set_listen("default","It is peacefully quiet here.");
    set_items(([
        "bed" : "%^RESET%^Worked from %^BOLD%^%^BLACK%^solid ebony%^RESET%^, this king size bed has four posts rising up to support a %^BOLD%^%^BLACK%^silken canopy%^RESET%^. A pile of fluffed %^BOLD%^d%^RESET%^%^ORANGE%^o%^WHITE%^w%^BOLD%^n%^RESET%^-filled %^MAGENTA%^pillows %^WHITE%^rests against the %^BOLD%^%^BLACK%^solid headboard%^RESET%^, and a thick %^MAGENTA%^comforter %^WHITE%^has been lain across the comfortable mattress.%^RESET%^",
        ({"fireplace", "screen"}) : "%^RESET%^The %^BOLD%^%^BLACK%^f%^RESET%^i%^BOLD%^%^BLACK%^r%^WHITE%^e%^BLACK%^pl%^RESET%^a%^BOLD%^%^BLACK%^c%^WHITE%^e %^RESET%^has been built into the %^BOLD%^%^BLACK%^st%^RESET%^o%^BOLD%^%^BLACK%^n%^WHITE%^e %^BLACK%^w%^RESET%^a%^BOLD%^l%^BLACK%^l%^RESET%^, jutting out in a shallow mantle. A tri-fold %^BOLD%^%^BLACK%^iron screen %^RESET%^has been placed in front, and beyond it you can see that it isn't a normal %^ORANGE%^wood %^WHITE%^fire that %^RED%^w%^BOLD%^a%^RESET%^%^RED%^rms %^WHITE%^the room. Within the hearth, tiny %^RED%^f%^BOLD%^i%^RESET%^%^ORANGE%^r%^BOLD%^%^RED%^e e%^RESET%^%^RED%^l%^BOLD%^e%^RESET%^%^RED%^m%^BOLD%^e%^RESET%^%^RED%^nt%^ORANGE%^a%^RED%^l %^WHITE%^has been bound in a circle %^BOLD%^of %^RESET%^%^CYAN%^a%^BOLD%^r%^RESET%^c%^BOLD%^%^BLACK%^a%^CYAN%^n%^RESET%^%^CYAN%^e r%^BOLD%^u%^RESET%^n%^BOLD%^%^CYAN%^e%^RESET%^%^CYAN%^s%^WHITE%^, compelled to %^RED%^h%^ORANGE%^e%^BOLD%^%^RED%^a%^RESET%^%^RED%^t %^WHITE%^the room for the pleasure of hotel guests%^BOLD%^.%^RESET%^",
        "paintings" : "These paintings depict tasteful %^GREEN%^l%^ORANGE%^a%^CYAN%^n%^GREEN%^ds%^BOLD%^%^CYAN%^c%^ORANGE%^a%^RESET%^%^GREEN%^p%^BOLD%^e%^RESET%^%^GREEN%^s%^WHITE%^, nondescript and %^CYAN%^s%^BOLD%^oo%^RESET%^%^CYAN%^th%^BOLD%^i%^RESET%^%^CYAN%^ng %^WHITE%^in %^CYAN%^color %^WHITE%^and %^BOLD%^tone%^RESET%^.",
        ({"wardrobe", "chest", "drawers"}) : "%^RESET%^This large %^BOLD%^%^BLACK%^wardrobe %^RESET%^is well-crafted, opening and closing silently on %^ORANGE%^oiled %^WHITE%^hinges. Next to it, a large %^BOLD%^%^BLACK%^chest %^RESET%^of drawers is waiting to be filled by the next guest. Both have been crafted from l%^BOLD%^%^BLACK%^u%^WHITE%^s%^RESET%^t%^BOLD%^%^BLACK%^r%^WHITE%^o%^RESET%^u%^BOLD%^%^BLACK%^s eb%^RESET%^o%^BOLD%^%^BLACK%^ny%^RESET%^, %^RESET%^and have the same decorative %^BOLD%^%^BLACK%^sc%^RESET%^r%^BOLD%^o%^BLACK%^llw%^RESET%^o%^BOLD%^%^BLACK%^rk %^RESET%^carved into their frames.%^RESET%^",
        ({"nightstand", "bell"}) : "%^RESET%^A singular %^BOLD%^%^BLACK%^nightstand %^RESET%^lurks at the side of the bed. The top has a %^BOLD%^lace doily %^RESET%^beneath a small %^BOLD%^%^BLACK%^s%^RESET%^i%^BOLD%^l%^RESET%^v%^BOLD%^%^BLACK%^er b%^RESET%^e%^BOLD%^l%^BLACK%^l%^RESET%^. You should be able to ring the %^BOLD%^%^BLACK%^b%^RESET%^e%^BOLD%^l%^BLACK%^l %^RESET%^for room service.%^RESET%^",
        ({"wall", "walls"}) : "%^BOLD%^%^BLACK%^Large slabs of %^RESET%^polished %^BOLD%^%^BLACK%^m%^RESET%^a%^BOLD%^r%^BLACK%^bl%^WHITE%^e %^BLACK%^shot through with v%^RESET%^e%^BOLD%^i%^BLACK%^ns of %^WHITE%^wh%^RESET%^i%^BOLD%^te %^BLACK%^comprise these walls.%^RESET%^",
        "floor" : "%^RESET%^Solid %^BOLD%^%^BLACK%^ebony floorboards %^RESET%^lay beneath your feet in a %^BOLD%^%^BLACK%^h%^RESET%^e%^BOLD%^r%^RESET%^r%^BOLD%^%^BLACK%^i%^RESET%^n%^BOLD%^g%^RESET%^b%^BOLD%^%^BLACK%^o%^RESET%^n%^BOLD%^e %^RESET%^pattern, the %^BOLD%^%^BLACK%^black wood p%^RESET%^o%^BOLD%^%^BLACK%^l%^WHITE%^i%^BLACK%^sh%^RESET%^e%^BOLD%^%^BLACK%^d %^RESET%^to a %^BOLD%^reflective %^BLACK%^sh%^RESET%^e%^BOLD%^e%^BLACK%^n%^RESET%^.",
        ]));
}

