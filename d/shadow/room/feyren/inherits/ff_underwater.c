#include <std.h>
#include "area_stuff.h"
inherit WATER;

int searched;

void create() 
{
    if(base_name(TO) != FFUT) 
    { 
        switch(random(11)) 
        {
            case 0..6:
                break;
            case 7..10:
                set_monsters(({FFMON+"amp_boa"}), ({1 + random(2)}));
                break;      			
        }
        set_repop(45);
    }
    ::create();
    set_property("no teleport", 1);
    set_name("A flooded tunnel");
    set_short("%^BOLD%^%^GREEN%^A flooded tunnel%^RESET%^");
    set_terrain(DEEP_WATER);
    set_travel(FRESH_BLAZE);

    set_long("%^BOLD%^%^GREEN%^The flooded tunnel around you is "+
    "quite wide and deep as if it was "+
    "once used to move large objects. You cannot determine with "+
    "any certainty what makes up the %^BOLD%^%^RED%^"+
    "structure%^BOLD%^%^GREEN%^ of this tunnel "+
    "but for whatever reason it has not yet collapsed. "+
    "The %^BOLD%^%^BLUE%^water%^BOLD%^%^GREEN%^"+
    " is very cold, making movement "+
    "almost unbearable. %^BOLD%^%^RED%^Bloated corpses%^BOLD%^%^GREEN%^"+
    " of %^BOLD%^%^RED%^spiders%^BOLD%^%^GREEN%^, clumps "+
    "of %^BOLD%^%^RED%^dead roots%^BOLD%^%^GREEN%^"+
    ", and %^RESET%^%^MAGENTA%^thick mud%^BOLD%^%^GREEN%^"+
    " make the %^BOLD%^%^BLUE%^water%^BOLD%^%^GREEN%^ murky, further "+
    "complicating movement. The %^BOLD%^%^BLACK%^darkness%^BOLD%^"+
    "%^GREEN%^ here is "+
    "almost palpable and for a moment you wonder about "+
    "what creatures, if any, might call this tunnel "+
    "home.%^RESET%^");
	 
    set_smell("default","The stench of stagnant water is almost overwhelming.");
    set_listen("default","%^BOLD%^You hear only your own movement through "+
    "the water.");

    set_items(([
    ({"structure", "tunnel"}) : "%^BOLD%^%^RED%^The structure "+
    "of this tunnel is difficult to discern. It looks almost "+
    "as if it has been carved from the very rock that was "+
    "naturally in the ground here. The original purpose of "+
    "this tunnel has been lost, however, as the flood water "+
    "keeps all but the very brave away.%^RESET%^",
    ({"water", "murky water"}) : "%^BOLD%^%^BLUE%^The murky "+
    "water all around you is ice cold and difficult "+
    "to swim through. The bloated corpses, clumps of "+
    "dead roots, and thick mud make it that much "+
    "more difficult.%^RESET%^",
    ({"bloated corpses", "spiders", "corpses"}) : "%^BOLD%^%^RED%^There "+
    "are multitudes of these corpses floating in the water "+
    "down here. It is difficult to swim past them without "+
    "first having to move them out of your way.%^RESET%^",
    ({"roots", "dead roots", "clumps"}) : "%^BOLD%^%^RED%^"+
    "There are far too many clumps of roots to possible "+
    "count floating in the water here. How they got here "+
    "remains somewhat of a mystery but it is feasible that "+
    "they once broke through the ceiling of this tunnel.%^RESET%^",
    ({"mud", "thick mud"}) : "%^MAGENTA%^This thick mud "+
    "hangs in clumps throughout the water and from the "+
    "amount of it you assume that it must be constantly "+
    "coming into the tunnel. Perhaps through the "+
    "openings in the ceiling from where the roots "+
    "once entered.%^RESET%^",
    "darkness" : "%^BOLD%^%^BLACK%^The darkness here "+
    "is an almost tangible thing. It is so thick and "+
    "permenant that it only adds to the difficulty "+
    "in swimming here.%^RESET%^",
    ] ));
}

