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
    set_name("Hotel Hallway");
    set_short("%^YELLOW%^H%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^e"+
        "%^BOLD%^l H%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^llw%^RESET%^%^ORANGE%^a"+
        "%^BOLD%^y%^RESET%^");
    set_long("%^RESET%^The hallway stretches north and south, with a pair of doors on "+
        "either side. A %^BOLD%^%^RED%^r%^RESET%^%^RED%^e%^BOLD%^d r%^RESET%^%^RED%^u"+
        "%^BOLD%^nn%^RESET%^%^RED%^e%^BOLD%^r %^RESET%^lines the floor, displaying a "+
        "path over the warm %^ORANGE%^m%^RED%^a%^ORANGE%^hog%^RED%^a%^ORANGE%^ny "+
        "flo%^RED%^o%^ORANGE%^rs%^WHITE%^. Small %^ORANGE%^b%^BOLD%^r%^RESET%^"+
        "%^ORANGE%^a%^BOLD%^ss p%^RESET%^%^ORANGE%^l%^BOLD%^aq%^RESET%^%^ORANGE%^ue"+
        "%^BOLD%^s %^RESET%^on each door display their room number in a flowing "+
        "script, contrasting pleasantly against the %^BOLD%^%^BLACK%^eb%^RESET%^"+
        "%^ORANGE%^o%^BOLD%^%^BLACK%^ny %^RESET%^and %^ORANGE%^oak %^BOLD%^%^BLACK%^"+
        "do%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^rs %^RESET%^that stand opposite each "+
        "other.%^RESET%^");
    set_smell("default","The air carries a mix of white tea and vanilla, with a hint of cedar.");
    set_listen("default","It is very quiet here.");
    set_items(([
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
        ({"runner", "carpet"}) : "%^RESET%^%^RED%^De%^BOLD%^e%^RESET%^%^RED%^p "+
            "%^CYAN%^and %^RED%^d%^BOLD%^a%^RESET%^%^RED%^rk r%^BOLD%^e%^RESET%^%^RED"+
            "%^d%^CYAN%^, this thick carpet runs the length hallway. An "+
            "intricate %^YELLOW%^g%^WHITE%^o%^ORANGE%^ld%^RESET%^%^ORANGE%^e%^BOLD%^n "+
            "p%^WHITE%^a%^ORANGE%^t%^RESET%^%^ORANGE%^t%^BOLD%^e%^WHITE%^r%^ORANGE%^n "+
            "%^RESET%^%^CYAN%^has been set into the borders of the carpet, a woven "+
            "series of swirls and wave-like ripples.%^RESET%^",
        ]));
}

