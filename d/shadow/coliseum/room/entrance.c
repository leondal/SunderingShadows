// Chernobog (3/6/21)
// Shadow Coliseum

#include <std.h>
#include "../defs.h"
inherit ROOM;

void create(){
    ::create();
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_property("indoors", 0);
    set_name("Shadow Coliseum");
    set_short("%^BOLD%^E%^ORANGE%^ntra%^RESET%^%^ORANGE%^nce %^BOLD%^t%^RESET%^%^ORANGE%^o %^BOLD%^th%^RESET%^%^ORANGE%^e %^BOLD%^%^WHITE%^C%^ORANGE%^olis%^RESET%^%^ORANGE%^eum%^WHITE%^");
    set_long("%^RESET%^%^ORANGE%^This plaza rests before the twin entrances to the %^BOLD%^%^WHITE%^S%^CYAN%^had%^RESET%^%^CYAN%^ow %^BOLD%^%^WHITE%^C%^CYAN%^olis%^RESET%^%^CYAN%^eum%^ORANGE%^. Checkered %^BOLD%^%^BLACK%^black %^RESET%^%^ORANGE%^and %^BOLD%^%^WHITE%^white %^BLACK%^fl%^RESET%^a%^BOLD%^gs%^RESET%^t%^BOLD%^%^BLACK%^on%^RESET%^e%^BOLD%^s %^RESET%^%^ORANGE%^mark out the grounds at the feet of the great %^BOLD%^Guardians of the Gladiators%^RESET%^%^ORANGE%^, creating a place for citizens to gather before gaining entrance. These twin statues lurk at the northern and eastern edges of the plaza, extending from the coliseum to the northeast and standing guard over the two archways leading into the massive building. Several %^BOLD%^%^WHITE%^s%^RESET%^t%^BOLD%^on%^RESET%^e %^BOLD%^be%^RESET%^n%^BOLD%^ch%^RESET%^e%^BOLD%^s %^RESET%^%^ORANGE%^have been scattered along the periphery, with a few open spaces left for mobile merchants to set up shop during events.%^RESET%^\n");
    set_smell("default","The stink of large crowds and stale sweat seems to permeate the plaza.");
    set_listen("default","The plaza is quiet at the moment.");
    set_items(([
        ({"archway","archways"}) : "%^BOLD%^%^BLACK%^Nestled between the feet of the towering %^RESET%^%^ORANGE%^s%^BOLD%^an%^RESET%^%^ORANGE%^d%^BOLD%^sto%^RESET%^%^ORANGE%^n%^BOLD%^e s%^RESET%^%^ORANGE%^t%^BOLD%^at%^RESET%^%^ORANGE%^u%^BOLD%^es%^BLACK%^, two archways lead deeper into the coliseum complex. A series of bricks line the arch, with a larger keystone capping the top of the curved entryway. Sconced %^RED%^t%^ORANGE%^o%^RED%^r%^RESET%^%^RED%^c%^BOLD%^h%^ORANGE%^e%^RED%^s %^BLACK%^flank each entrance, illuminating the area and shedding light onto the plaza.%^RESET%^",
        "benches" : "%^BOLD%^%^BLACK%^These benches are simple in design, with a long flat slab of marble balanced on two blocky supports. They are smooth and beveled, though designed more for appearance than for any sort of comfort. The marble is a %^RESET%^smokey gray %^BOLD%^%^BLACK%^with black spidery veins, contrasting nicely with the %^WHITE%^fl%^RESET%^a%^BOLD%^%^BLACK%^gs%^RESET%^t%^BOLD%^on%^RESET%^e%^BOLD%^%^BLACK%^s of the plaza.%^RESET%^",
        ({"flagstones","plaza"}) : "%^BOLD%^%^BLACK%^The plaza has been picked out with large flagstones of alternating %^RESET%^b%^BOLD%^%^BLACK%^lac%^RESET%^k %^BOLD%^%^BLACK%^and %^RESET%^w%^BOLD%^hit%^RESET%^e m%^BOLD%^a%^RESET%^r%^BOLD%^%^BLACK%^b%^RESET%^l%^BOLD%^e%^BLACK%^, giving the impression of a standing on a giant chess board.%^RESET%^",
        ({"guardians","statues"}) : "%^BOLD%^%^BLACK%^These twins stand several stories high, jutting out from the body of the coliseum to the north and east of the plaza. Carved from massive %^RESET%^%^ORANGE%^s%^BOLD%^an%^RESET%^%^ORANGE%^d%^BOLD%^sto%^RESET%^%^ORANGE%^n%^BOLD%^e b%^RESET%^%^ORANGE%^l%^BOLD%^ock%^RESET%^%^ORANGE%^s%^BOLD%^%^BLACK%^, they are depicted as perfect beings with smoothly muscled forms, and short kilt-like cloths wrapped about their waists. Their hands are cupped forward and held aloft in offering, and they gaze forward over the plaza with a %^WHITE%^n%^RESET%^o%^BOLD%^ble %^BLACK%^bearing. A minute %^RESET%^%^ORANGE%^statue %^BOLD%^%^BLACK%^of a %^RESET%^%^ORANGE%^man %^BOLD%^%^BLACK%^rests in each set of hands, garbed in g%^RESET%^l%^BOLD%^a%^RESET%^d%^BOLD%^%^BLACK%^i%^RESET%^a%^BOLD%^t%^RESET%^o%^BOLD%^%^BLACK%^r%^RESET%^i%^BOLD%^a%^RESET%^l %^BOLD%^%^BLACK%^fare and raising a w%^RESET%^e%^BOLD%^ap%^RESET%^o%^BOLD%^%^BLACK%^n in challenge to his twin across the plaza. An arched entrance into the coliseum has been placed between the legs at the base of each %^ORANGE%^c%^RESET%^%^ORANGE%^o%^BOLD%^lo%^RESET%^%^ORANGE%^s%^BOLD%^su%^RESET%^%^ORANGE%^s%^BOLD%^%^BLACK%^.%^RESET%^",
        ]));
    set_exits(([
        "southwest" : ROOMS"thoroughfare",
        "north" : ROOMS"concourse2",
        "east" : ROOMS"concourse1",
        ]));
}

