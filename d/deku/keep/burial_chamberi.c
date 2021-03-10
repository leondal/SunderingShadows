#include <std.h>
#include "keep.h"
inherit ROOM;

int searched;

void create() 
{
    ::create();
    set_name("a forgotten chamber");
    set_short("%^BOLD%^%^RED%^A dirt chamber%^RESET%^");
    set_terrain(RUINS);
    set_property("light", 1);
    set_travel(DECAYED_FLOOR);
    set_property("indoors", 1);

    set_long("%^BOLD%^%^RED%^This massive chamber is an almost perfect "+
    "square, with it %^RESET%^%^YELLOW%^walls%^BOLD%^%^RED%^, "+
    "%^RESET%^%^YELLOW%^floor%^BOLD%^%^RED%^, and %^RESET%^%^YELLOW%^ "+
    "ceiling%^BOLD%^%^RED%^ nothing more than %^RESET%^%^YELLOW%^packed dirt"+
    "%^BOLD%^%^RED%^.  "+
    "It is quite amazing that it has survived without any apparent "+
    "support, though it has fallen into decay now and seems "+
    "like it could come tumbling down around you at any point.  "+
    "It is obvious, without much thought, that this chamber has "+
    "been left abandoned for many years, perhaps centuries.  "+
    "There are %^BOLD%^%^BLACK%^sarcophaguses%^RESET%^%^BOLD%^%^RED%^"+
    ", made from great %^BOLD%^%^BLACK%^ebony stone%^RESET%^%^BOLD%^"+
    "%^RED%^, that have "+
    "been literally ripped apart by something, scattered about the "+
    "room.  This suggests that at some point this may have served as "+
    "a burial chamber, though when or for whom is beyond your knowledge and "+
    "has been perhaps lost forever in history.  It is also quite "+
    "obvious that something or someone removed any valuables from the "+
    "resting place of whatever might have been buried down here and "+
    "this pillage does not look recent.%^RESET%^");
			  
    set_smell("default","\nA stout musty smell mixes with the slight smell of "+
    "stagnant water here.");
    set_listen("default","%^BOLD%^You hear disembodied whispers all "+
    "around you.");
	
    set_items(([
        ({"floor", "walls", "wall", "ceiling", "dirt", "packed dirt"}) : "%^YELLOW%^"+
        "The floor, walls, and ceiling are all made up of simply "+
        "packed dirt.  Though this chamber has survived without "+
        "any apparent support, its age suggests that it might "+
        "not hold up much longer.  You are unsure of how safe this "+
        "place is.%^RESET%^", 
        ({"sarcophagus", "sarcophaguses", "tombs", "coffins", "coffin",     
        "ebony stone"}) : "%^BOLD%^%^BLACK%^"+
        "These one proud monuments to the dead are scattered about, pillaged and "+
        "broken.  It is apparent that they were once very beautiful and "+
        "crafted with a careful and skilled hand, however, they now lay "+
        "faded and shattered, nothing more than broken stone.%^RESET%^"
    ])); 
		
}

