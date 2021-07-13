// Chernobog (1/5/21)
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
    set_name("Grand Staircase");
    set_short("%^YELLOW%^G%^RESET%^%^ORANGE%^r%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^n"+
        "%^BOLD%^d S%^RESET%^%^ORANGE%^t%^BOLD%^%^BLACK%^airca%^RESET%^%^ORANGE%^s"+
        "%^BOLD%^e%^RESET%^");
    set_long("%^RESET%^Gently spiraling counter-clockwise as it climbs between floors, "+
        "the %^YELLOW%^g%^RESET%^%^ORANGE%^r%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^n"+
        "%^BOLD%^d s%^RESET%^%^ORANGE%^t%^BOLD%^%^BLACK%^airca%^RESET%^%^ORANGE%^s"+
        "%^BOLD%^e %^RESET%^is impressive in scope. Each step is fully a man's length "+
        "in width and half as deep, fashioned from that same %^ORANGE%^r%^RED%^i"+
        "%^ORANGE%^ch rud%^RED%^d%^ORANGE%^y m%^RED%^a%^ORANGE%^hog%^RED%^a%^ORANGE%^ny "+
        "%^WHITE%^as the floors. A %^BOLD%^%^RED%^d%^RESET%^%^RED%^a%^BOLD%^rk r%^RESET%^"+
        "%^RED%^e%^BOLD%^d r%^RESET%^%^RED%^u%^BOLD%^nn%^RESET%^%^RED%^e%^BOLD%^r "+
        "%^RESET%^lines the staircase, easily muffling any footsteps. The bannisters are "+
        "worn from use but %^BOLD%^%^BLACK%^pol%^RESET%^ish%^BOLD%^ed %^RESET%^and well-"+
        "maintained, connected to the staircase by intricate %^BOLD%^%^BLACK%^ironwork "+
        "spindles%^RESET%^.");
    set_smell("default","The air carries a mix of white tea and vanilla, with a hint of cedar.");
    set_listen("default","You hear the gentle susurrus of patrons coming and going.");
    set_items(([
        ({"wall", "walls"}) : "%^RESET%^%^CYAN%^Uneven %^BOLD%^%^BLACK%^stones "+
            "%^RESET%^%^CYAN%^of %^BOLD%^%^BLACK%^black %^RESET%^%^CYAN%^and %^WHITE%^"+
            "d%^BOLD%^%^BLACK%^a%^RESET%^rk %^BOLD%^%^BLACK%^gr%^RESET%^e%^BOLD%^"+
            "%^BLACK%^y %^RESET%^%^CYAN%^comprise these walls. The black stone is a "+
            "common element of Tonovi construction, mined from the north.%^RESET%^",
        ({"stairs", "staircase"}) : "%^RESET%^%^CYAN%^The stairs are broad and expansive"+
            ", and any footsteps are %^BOLD%^%^BLACK%^silenced %^RESET%^%^CYAN%^thanks "+
            "to the %^BOLD%^%^RED%^th%^RESET%^%^RED%^i%^BOLD%^ck r%^RESET%^%^RED%^e"+
            "%^BOLD%^d r%^RESET%^%^RED%^u%^BOLD%^nn%^RESET%^%^RED%^e%^BOLD%^r%^RESET%^"+
            "%^CYAN%^.%^RESET%^",
        "bannisters" : "%^RESET%^%^CYAN%^Soft and smooth to the touch, the bannister "+
            "is %^ORANGE%^aged %^CYAN%^and %^ORANGE%^worn %^CYAN%^from use. Intricate "+
            "iron spindles support the railing, with an ocassional artistic swirl "+
            "present in the %^BOLD%^%^BLACK%^ir%^RESET%^o%^BOLD%^%^BLACK%^nw%^RESET%^"+
            "o%^BOLD%^%^BLACK%^rk l%^RESET%^a%^BOLD%^%^BLACK%^tt%^RESET%^i%^BOLD%^"+
            "%^BLACK%^ce%^RESET%^%^CYAN%^.%^RESET%^",
        ]));
}

