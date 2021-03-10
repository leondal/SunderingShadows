//whouse4.c - Breilia's estate in Newbietown

#include <std.h>
#include "../../newbie.h"
inherit INH"townmove.c";

void create() {
        ::create();
        set_property("indoors",1);
        set_property("light",2);
        set_property("no sticks",1);
        set_terrain(STONE_BUILDING);
        set_travel(PAVED_ROAD);
        set_short("%^CYAN%^A spacious and well-built home%^RESET%^");
 		set_long(
@STYX
This is a very spacious and well-built home.  Thick stone walls block out the sounds from outside and help keep the temperature moderate while various rugs decorate and insulate the floors.  You can see most of the rooms from here through open doors.  Each room has a fireplace for heating and oil lamps hang from the walls or sit on tables for light.  The master bedroom is down a short hall to the left from the entrance and a smaller one is just across from it.  The dining room is directly ahead and you can see the kitchen just beyond it.  A parlor for relaxing and entertaining guests is to the right from the entrance.  A study is just beyond the parlor.  Much of the decorating is in shades of %^CYAN%^cyan%^RESET%^.        
STYX
        );
        set_smell("default","The house smells much like an alchemy shop.");
        set_listen("default","Little disturbs the quiet here.");
        set_items(([
        ({"walls","wall","stone"}) : "The stones for the walls have been carefully placed and mortar seals the spaces between them.",
        "bedroom" : "The bedrooms look spacious and have real wooden doors on them.  They are open at the moment, allowing you to see the neatly made beds and nice furniture.",
        "kitchen" : "You can see heavy cast iron pots and pans hanging from a rack in the kitchen over the cabinets and sink.  There seem to be more herbs and odd things than normal cooking ingredients here though.  A stove for cooking has wood piled beside it.",
        "parlor" : "The parlor has a cozy couch with nice thick cushions covered with a sturdy fabric woven into a %^CYAN%^plaid pattern%^RESET%^.  A large oval woven rug covers the center of the room.  Several chairs are grouped around the fireplace and a chess set sits on a table with a chair on each side.",
        "dining room" : "The dining room has an intricately carved %^MAGENTA%^mahogany table%^RESET%^ with ten matching chairs around it.  The chairs at each end have arms and look very comfortable.",
        ({"floor", "rugs"}) : "The floor is nicely polished wood.  The wood is inlaid in interesting patterns in some of the rooms or mostly covered with fur hides or woven rugs in others.  The rug in the entryway has %^CYAN%^Breilia%^RESET%^ woven into it.",
        ({"lamps","lamp","oil lamps"}) : "Oil lamps hang from decorative wrought iron holders and give off a pleasant scent as they burn.",
		"study" : "The study walls are lined with shelves holding jars of various ingredients and books on alchemy.  A picture on the wall shows a mage tower just south of a city.  A note in the corner says 'To Breilia, good luck with your new endeavors.  Wizbert and the others will miss you too so come visit us if you get to Shadow.'  It is signed 'Lavasha.'"
        ]));
        set_exits(([
        "south" : MAINTOWN"wrstreet4",
        ]));
        set_door("cyan door","/d/newbie/rooms/town/wrstreet4","south",0);
}