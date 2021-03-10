#include <std.h>
#include "../keep.h"
inherit ROOM;

int searched;
void create() 
{
    ::create();
    set_name("a forgotten chamber");
    set_short("%^BOLD%^%^BLACK%^A chamber of shadows%^RESET%^");
    set_terrain(RUINS);
    set_property("light", 1);
    set_travel(DECAYED_FLOOR);
    set_property("no sticks", 1);
    set_property("indoors", 1);
    set_property("no teleport", 1);
    set_long("%^BOLD%^%^BLACK%^The chamber in which you now stand "+
    "bares no resemblance to the one you were just in.  This place is "+
    "obviously of no mortal creation.  It is the very essence of shadow and "+
    "darkness.  The darkness here is stifling and you're almost "+
    "blinded by the shadows that linger here without end.  You believe "+
    "this place to be almost a circle, as the walls are mostly "+
    "indistinguishable, it it hard to tell with any degree of certainty.  "+
    "To your horror and to make matters worse, you notice the floor of this place, "+
    "though it too looks like it has been forged by darkness and "+
    "shadow also, is littered with what are obviously %^BOLD%^%^WHITE%^"+
    "human skeletons%^RESET%^%^BOLD%^%^BLACK%^.  "+
    "An innumerable amount of these %^BOLD%^%^WHITE%^skeletons%^RESET%^"+
    "%^BOLD%^%^BLACK%^ litter the place, "+
    "as if this chamber itself is a graveyard, the final resting "+
    "place of thousands of people.  A %^BLUE%^gaping hole%^RESET%^"+
    "%^BOLD%^%^BLACK%^, as if it was "+
    "ripped out, paves the wave for you to head back into "+
    "the forgotten burial chamber.%^RESET%^");
			  
    set_smell("default","\nA strong odor of decay assaults you.");
    set_listen("default","%^BOLD%^You hear disembodied whispers all "+
    "around you.");
    set_items(([
        ({"walls", "wall", "ceiling"}) : "%^BOLD%^%^BLACK%^"+
        "The walls and ceiling of this place are very hard to discern "+
        "but from what you can manage they appear to be made from the "+
        "very essence of shadows and darkness.  They almost appear "+
        "to continually move and just observing them makes you slightly "+
        "nauseous.%^RESET%^", 
        ({"floor", "skeletons", "remains", "human skeletons"}) : 
        "%^BOLD%^%^BLACK%^The floor here, though it bares a resemblance "+
        "to the walls and ceiling, is littered with an innumerable "+
        "amount of human %^BOLD%^%^WHITE%^skeletons%^RESET%^%^BOLD%^%^BLACK%^"+
        " that literally are piled atop of one another.  You imagine "+
        "this chamber to be the final resting place of "+
        "thousands of people.%^RESET%^", 
        ({"hole", "gaping hole"}) : "%^BLUE%^This massive hole looks like it "+
        "has been ripped out of the north wall.  Though you also notice that there "+
        "is an almost invisible barrier around it.  The barrier appears made of the "+
        "same shadowy essence and it shifts continually without end.%^RESET%^"
    ])); 
    set_exits((["north" : KEEPR+"burial_chamber_1"]));
    if(!present("map keeper", TO)) 
    {
        new(KEEPM+"map_keeper")->move(TO);
    }
}

void reset()
{
    ::reset();
    if(!present("map keeper", TO)) 
    {
        new(KEEPM+"map_keeper")->move(TO);
    }
}