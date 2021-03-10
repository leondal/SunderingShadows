//Octothorpe (1/20/12)
//Shadow, Shadow Way 4

#include <std.h>
#include "../defs.h"
inherit INH+"shadway";

void create(){
    ::create();
    set_long(::query_long()+"The %^BOLD%^%^BLACK%^Shadow Bridge "+
        "%^RESET%^crosses over the %^BOLD%^%^BLUE%^Sarcosta River "+
        "%^RESET%^to the east. A large %^BOLD%^%^BLACK%^inn %^RESET%^ "+
        "and courtyard lies to the north through an archway, while a grand "+
        "theater is to the south.\n");
    add_item(({"inn"}),"A large building built from %^BOLD%^%^BLACK%^"+
        "light gray stones %^RESET%^stands here, a sign tacked on its "+
        "side proudly proclaiming it to be the %^BOLD%^%^CYAN%^Three "+
        "Coins Inn%^RESET%^, and it features the image of three "+
        "%^YELLOW%^i%^WHITE%^nt%^ORANGE%^e%^RESET%^%^ORANGE%^r%^BOLD%^l"+
        "%^WHITE%^oc%^ORANGE%^k%^RESET%^%^ORANGE%^i%^BOLD%^n%^WHITE%^g "+
        "r%^ORANGE%^i%^RESET%^%^ORANGE%^n%^BOLD%^g%^WHITE%^s%^RESET%^: "+
        "the emblem of Shadow City. %^BOLD%^%^GREEN%^I%^RESET%^%^GREEN%^"+
        "v%^BOLD%^y %^RESET%^creeps along the pale stones, and some "+
        "hanging baskets of %^BOLD%^%^GREEN%^f%^RESET%^%^GREEN%^l"+
        "%^MAGENTA%^o%^ORANGE%^w%^MAGENTA%^e%^GREEN%^r%^BOLD%^s %^RESET%^"+
        "add a touch of color and charm. An %^BOLD%^archway %^RESET%^"+
        "leads into the courtyard of the inn, while a <staircase>, nearly "+
        "hidden behind a stone wall, climbs up the side of the building "+
        "and appears to lead directly to the balcony of the second "+
        "floor.%^RESET%^");
	add_item(({"theater"}),"%^BOLD%^%^BLACK%^Directly to the south "+
        "is a marvelous building "+
        "built from stone. An engraved plaque announces it to be "+
        "%^RESET%^The Three Coins "+ 
        "Theater%^BOLD%^%^BLACK%^. Some %^GREEN%^ivy%^BLACK%^ "+ 
        "edges its way over the gray stones.");
    set_exits(([
        "west" : ROOMS"shadway5",
        "east" : ROOMS"shadway3",
        "north" : ROOMS"3coinscourt",
        "south" : ROOMS"theater",
        "staircase" : ROOMS"3coinsbalcony"
    ]));
    set_invis_exits(({"staircase"}));
}

void reset()
{
    ::reset();
    if(!present("guard"))
        new("/d/shadow/city/mon/city_guard")->move(TO);
    if(!present("guard 2"))
        new("/d/shadow/city/mon/city_guard")->move(TO);
    if(!present("guard 3"))
        new("/d/shadow/city/mon/city_guard")->move(TO);          
}

