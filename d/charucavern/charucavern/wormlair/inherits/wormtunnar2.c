#include <std.h>
#include "area_stuff.h"
#include <daemons.h>
#include <move.h>
#include </d/common/common.h>

inherit WFALL;

void create() 
{
    ::create();
    set_name("A passageway through earth and stone");
    set_short("%^RESET%^%^ORANGE%^A passageway through earth and %^BOLD%^%^WHITE%^stone%^RESET%^");

    set_long("%^RESET%^%^ORANGE%^You find yourself in a passageway composed of "+
    "%^BOLD%^earth%^RESET%^%^ORANGE%^ and %^BOLD%^%^WHITE%^stone%^RESET%^%^ORANGE%^. It quickly "+
    "reminds you of something that was created by some type of animal, such as a mole. However, it is "+
    "large enough for several humans to pass through side by side without getting in the way of "+
    "one another. It has "+
    "been burrowed out, as if something crawled through here, devouring all in its path. "+
    "There are several rock %^BOLD%^%^MAGENTA%^ledges%^RESET%^%^ORANGE%^ jutting out "+
    "at odd angles. They vary in size but some of them are very "+
    "big enough to stand on. You realize that "+
    "whatever animal created this place had no issue chewing through the stone to create them. You are also "+
    "grateful for them, as they give you "+
    "something to stand on, less you fall into the %^BOLD%^%^BLACK%^darkness%^RESET%^%^ORANGE%^ below you. "+
    "%^RESET%^");

    set_smell("default","\nAn odor that reminds you of unwashed filth assaults your senses.");
    set_listen("default","The sound of earth rumbling fills the air.");			
	
    set_items(([
    
       ({"earth", "stone", "passageway"}) : "%^RESET%^%^ORANGE%^You easily realize that "+
       "this passageway is the byproduct of some large animal. It reminds you of what a "+
       "mole might create, except much larger. You cannot help but to wander what "+
       "happened to the animal that created this passageway. It is composed "+
       "entirely of earth and stone with ledges jutting out at odd angles.%^RESET%^",
       
       ({"ledges", "ledge"}) : "%^BOLD%^%^MAGENTA%^These ledges are jutting out chaotically "+
       "at odd angles. They vary in size but some of them are large enough to stand on.%^RESET%^",
       
       ({"darkness"}) : "%^BOLD%^%^BLACK%^Darkness surrounds you in here, it is your "+
       "constant companion. It seems to grow even deeper below you, but perhaps that is "+
       "only your imagination or fear of what might dwell beneath.%^RESET%^",
       
    ]));

    
    set_search("default", "%^RESET%^%^ORANGE%^You notice nothing that could possible "+
    "conceal anything.%^RESET%^");

    set_property("light",-2);
    set_property("indoors",1);

    set_terrain(NAT_CAVE);
    set_travel(SLICK_FLOOR);  
    
    if(!query_grab_onto()) set_grab_onto("of one of the ledges");
    if(!query_land_on()) set_land_on("hard stone floor");    
}

void reset()
{
	::reset();
}
