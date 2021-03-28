// Chernobog (1/11/21)
// Tonovi Hotel

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
    set_short("%^YELLOW%^H%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^e"+
        "%^BOLD%^l R%^BLACK%^o%^RESET%^%^ORANGE%^o%^BOLD%^m%^RESET%^");
    set_long("%^RESET%^The large %^ORANGE%^four poster bed %^WHITE%^dominates the room, "+
        "the centerpiece and a welcome sight. A %^ORANGE%^nightstand %^WHITE%^within "+
        "reach of the bed displays a small %^BOLD%^%^BLACK%^s%^RESET%^i%^BOLD%^lv"+
        "%^RESET%^e%^BOLD%^%^BLACK%^r %^RESET%^b%^BOLD%^e%^RESET%^l%^BOLD%^%^BLACK%^l"+
        "%^RESET%^. One corner of the room hosts a tall %^ORANGE%^wardrobe %^WHITE%^and "+
        "%^ORANGE%^chest %^WHITE%^of drawers for the use of the hotel's guests, ample "+
        "room for most stays. A simple %^RED%^f%^BOLD%^i%^ORANGE%^r%^RED%^e%^RESET%^"+
        "%^RED%^p%^BOLD%^l%^ORANGE%^a%^RED%^c%^RESET%^%^RED%^e %^WHITE%^lurks to the "+
        "side of the room with an ornate %^BOLD%^%^BLACK%^iron screen %^RESET%^banking "+
        "the flames, and %^BOLD%^%^RED%^th%^MAGENTA%^i%^RED%^ck ru%^MAGENTA%^g%^RED%^s "+
        "%^RESET%^have been placed nearby, greedily absorbing the warmth. The %^BOLD%^"+
        "%^BLACK%^st%^WHITE%^o%^BLACK%^ne wal%^WHITE%^l%^BLACK%^s %^RESET%^have been "+
        "adorned with a few tasteful %^GREEN%^pa%^BOLD%^in%^CYAN%^t%^WHITE%^i%^CYAN%^n"+
        "%^RESET%^%^CYAN%^gs %^WHITE%^to complete the decor.%^RESET%^\n");
    set_smell("default","The air carries a mix of white tea and vanilla, with a hint of cedar.");
    set_listen("default","It is peacefully quiet here.");
    set_items(([
        "bed" : "%^RESET%^%^CYAN%^Worked from %^ORANGE%^solid oak%^CYAN%^, this king "+
            "size bed has four posts rising up to support a %^MAGENTA%^s%^BOLD%^i"+
            "%^WHITE%^l%^MAGENTA%^k%^RESET%^%^MAGENTA%^e%^BOLD%^n %^RESET%^%^MAGENTA%^"+
            "c%^BOLD%^a%^RESET%^%^MAGENTA%^n%^BOLD%^o%^WHITE%^p%^MAGENTA%^y%^RESET%^"+
            "%^CYAN%^. A pile of fluffed down %^MAGENTA%^p%^BOLD%^i%^RESET%^"+
            "%^MAGENTA%^l%^BOLD%^lo%^RESET%^%^MAGENTA%^w%^BOLD%^s %^RESET%^%^CYAN%^"+
            "rests against a solid headboard, and a %^MAGENTA%^th%^RED%^i%^MAGENTA%^ck "+
            "c%^RED%^o%^MAGENTA%^mf%^RED%^o%^MAGENTA%^rt%^RED%^e%^MAGENTA%^r %^CYAN%^"+
            "has been lain across the thick mattress.%^RESET%^",
        ({"fireplace", "screen"}) : "%^RESET%^%^CYAN%^The %^RED%^f%^BOLD%^i%^ORANGE%^r"+
            "%^RED%^e%^RESET%^%^RED%^p%^BOLD%^l%^ORANGE%^a%^RED%^c%^RESET%^%^RED%^e "+
            "%^CYAN%^has been built into the %^BOLD%^%^BLACK%^st%^RESET%^o%^BOLD%^"+
            "%^BLACK%^ne wa%^RESET%^l%^BOLD%^%^BLACK%^l%^RESET%^%^CYAN%^, jutting out "+
            "in a shallow mantle. An tri-fold %^BOLD%^%^BLACK%^iron screen %^RESET%^"+
            "%^CYAN%^has been placed in front, and beyond it you can see that it "+
            "isn't a normal wood fire that warms the room. A tiny %^BOLD%^%^RED%^f"+
            "%^ORANGE%^i%^WHITE%^r%^RED%^e e%^ORANGE%^l%^WHITE%^e%^ORANGE%^m%^RED%^e"+
            "%^ORANGE%^n%^WHITE%^t%^ORANGE%^a%^RED%^l %^RESET%^%^CYAN%^has been bound "+
            "within an %^BOLD%^o%^GREEN%^r%^CYAN%^n%^GREEN%^a%^CYAN%^t%^GREEN%^e "+
            "%^CYAN%^c%^GREEN%^i%^CYAN%^r%^GREEN%^c%^CYAN%^l%^GREEN%^e %^RESET%^"+
            "%^CYAN%^in the hearth, compelled to heat the room for the pleasure of "+
            "the hotel guests.%^RESET%^",
        "paintings" : "%^RESET%^%^CYAN%^Paintings have been placed on the %^BOLD%^"+
            "%^BLACK%^walls %^RESET%^%^CYAN%^to fill the empty spaces. They are all "+
            "tasteful %^GREEN%^la%^BOLD%^nd%^CYAN%^s%^WHITE%^c%^CYAN%^a%^RESET%^"+
            "%^GREEN%^pes%^CYAN%^, nondescript and soothing in color and tone."+
            "%^RESET%^",
        ({"wardrobe", "chest", "drawers"}) : "%^RESET%^%^CYAN%^The wardrobe has been "+
            "crafted carefully, opening and closing silently on %^ORANGE%^o%^BOLD%^i"+
            "%^WHITE%^l%^ORANGE%^e%^RESET%^%^ORANGE%^d %^CYAN%^hinges. Next to it, a "+
            "large chest of drawers is waiting to be filled by the next guest. Both "+
            "have been crafted from warm %^ORANGE%^m%^RED%^a%^ORANGE%^hog%^RED%^a"+
            "%^ORANGE%^ny%^CYAN%^, and have a similar scrollwork carved into their "+
            "frame.%^RESET%^",
        ({"nightstand", "bell"}) : "%^RESET%^%^CYAN%^A singular %^ORANGE%^nightstand "+
            "%^CYAN%^lurks at the side of the bed. The top has a %^BOLD%^%^WHITE%^l"+
            "%^RESET%^a%^BOLD%^c%^RESET%^e %^BOLD%^d%^RESET%^o%^BOLD%^i%^RESET%^l"+
            "%^BOLD%^y %^RESET%^%^CYAN%^beneath a small %^BOLD%^%^BLACK%^s%^RESET%^i"+
            "%^BOLD%^lv%^RESET%^e%^BOLD%^%^BLACK%^r %^RESET%^b%^BOLD%^e%^RESET%^l"+
            "%^BOLD%^%^BLACK%^l%^RESET%^%^CYAN%^. You should be able to %^BOLD%^ring the bell "+
            "%^RESET%^%^CYAN%^for room service.%^RESET%^",
        ({"wall", "walls"}) : "%^RESET%^%^CYAN%^Uneven %^BOLD%^%^BLACK%^stones "+
            "%^RESET%^%^CYAN%^of %^BOLD%^%^BLACK%^black %^RESET%^%^CYAN%^and %^WHITE%^"+
            "d%^BOLD%^%^BLACK%^a%^RESET%^rk %^BOLD%^%^BLACK%^gr%^RESET%^e%^BOLD%^"+
            "%^BLACK%^y %^RESET%^%^CYAN%^comprise these walls. The black stone is a "+
            "common element of Tonovi construction, mined from the north.%^RESET%^",
        "floor" : "%^RESET%^%^CYAN%^Solid %^ORANGE%^m%^RED%^a%^ORANGE%^h%^RED%^o"+
            "%^ORANGE%^g%^RED%^a%^ORANGE%^ny %^CYAN%^floorboards lay beneath your feet"+
            ", the %^ORANGE%^r%^RED%^e%^ORANGE%^dd%^RED%^i%^ORANGE%^sh %^CYAN%^hue of "+
            "the wood polished to an impressive %^BOLD%^%^BLACK%^sh%^RESET%^ee%^BOLD%^n"+
            "%^RESET%^%^CYAN%^.%^RESET%^",
        ]));
}

