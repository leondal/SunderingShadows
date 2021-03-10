#include <std.h>
#include <daemons.h>

#include "area_stuff.h"
#include "door_stuff.h"

#include "/d/common/common.h"

inherit BASEMENT;

int searched;
void place_basement_mobs()
{
    if(base_name(TO) != BR) 
    { 
        switch(random(11)) 
        {
            case 0..6:
                break;
            case 7..10:
                set_monsters(({HHMON+"bandit"}), ({1 + random(3)}));
                break;      			
        }
        set_repop(40);
    }
}


void create() 
{
    place_basement_mobs();
    ::create();
    set_name("A room within the poorly constructed basement");
    set_short("%^RESET%^%^ORANGE%^A room within the poorly constructed basement%^RESET%^");

    set_long("%^RESET%^%^ORANGE%^The room that you find yourself in is "+
    "small and in an advanced stage of %^BOLD%^%^RED%^decay%^RESET%^%^ORANGE%^. "+
    "The walls, floor, and ceiling have been constructed from a "+
    "thick %^BOLD%^%^BLACK%^dark "+
    "%^RESET%^%^ORANGE%^wood that has been inscribed with innumerable "+
    "%^BOLD%^%^CYAN%^runes%^RESET%^%^ORANGE%^. The %^BOLD%^%^CYAN%^runes"+
    "%^RESET%^%^ORANGE%^ have faded immensely with the passage of time but "+
    "they still give off a brilliant %^BOLD%^%^WHITE%^glow%^RESET%^%^ORANGE%^, "+
    "which manages to serve as a meager light source. The %^BOLD%^%^BLACK%^dark"+
    "%^RESET%^%^ORANGE%^ wood has not aged well, much of it is rotted, and "+
    "what seems solid is cracking apart. The entire room looks like it was "+
    "thrown together rather rapidly with the %^BOLD%^%^CYAN%^runes%^RESET%^%^ORANGE%^ "+
    "as a possible exception. Bare %^BOLD%^%^MAGENTA%^earth%^RESET%^%^ORANGE%^ is "+
    "visible in spots on the floor. Moisture hangs in the air, offering a "+
    "dankness to the room and contributing to the ongoing %^BOLD%^"+
    "%^RED%^decay%^RESET%^%^ORANGE%^.%^RESET%^");
	
    set_smell("default","\nThe smell of earth tained by a hint of magic hangs heavily here.");
    
    set_listen("default","Sounds of wood snapping can be heard all around you.");			
			
    set_items(([
        ({"walls", "ceiling", "floor", "earth", "decay", "wood", 
        "dark wood"}) : "%^BOLD%^%^MAGENTA%^The ceiling, walls, and floor "+
        "of this room has been constructed from a dark wood that is in an "+
        "advanced state of decay. Much of it has rotted and what "+
        "looks solid is cracked apart. The entire room looks as if it "+
        "were thrown together rather rapidly, with the possible exception "+
        "of the runes which cover the wood. There are even visible "+
        "patches of earth on the floor of the room, where the wood has "+
        "deteriorated away.%^RESET%^",
		
        ({"runes", "rune", "light source", "glow" }) : "%^BOLD%^%^CYAN%^The "+
        "bizarre runes that cover the wood of this room are innumerable. "+
        "There are perhaps thousands, if not more, of them, and even though "+
        "they have faded immensely with the passage of time they still offer "+
        "a brilliant glow, which serves as a meager light source. You are "+
        "sure that they still contain at least a portion of their original "+
        "power, though you are not sure what their purpose might be.%^RESET%^",

    ]));
	
    set_property("light",1);
    set_property("indoors",1);
    set_property("no teleport", 1);
    set_terrain(WOOD_BUILDING);
    set_travel(DECAYED_FLOOR);
    set_search("default", "You notice no obvious place for anything "+
    "to be concealed.");
    searched = random(5);   
    TO->check_adjustment();
}


void reset()
{
    place_basement_mobs();
    ::reset();	
    searched = random(5);
   
}