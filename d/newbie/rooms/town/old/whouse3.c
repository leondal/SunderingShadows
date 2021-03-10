//whouse3.c - Caeleb's estate in Newbietown

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
        set_short("%^GREEN%^A spacious and well-built home");
        set_long(
@STYX
This is a very spacious and well-built home.  Thick stone walls block out the sounds from outside and help keep the temperature moderate while various rugs decorate and insulate the floors.  You can see most of the rooms from here through open doors.  Each room has a fireplace for heating and oil lamps hang from the walls or sit on tables for light.  The master bedroom is down a short hall to the left from the entrance and a smaller one is just across from it.  The dining room is directly ahead and you can see the kitchen just beyond it.  A parlor for relaxing and entertaining guests is to the right from the entrance.  Obviously the home of an ex- adventurer, there are sketches and paintings of some interesting looking places in most of the rooms as well as trophies of exploits around.      
STYX
        );
        set_smell("default","The house smells of mortar and scented oil from the lamps.");
        set_listen("default","Little disturbs the quiet here.");
        set_items(([
        ({"walls","wall","stone"}) : "The stones for the walls have been carefully placed and mortar seals the spaces between them.",
        "bedroom" : "The bedrooms look spacious and have real wooden doors on them.  They are open at the moment, allowing you to see the neatly made beds and nice furniture.  The master bedroom has a sketch of another island.  The sketch shows a desert wasteland covering the western part, but there seems to be a city near the center and a forest east of it.  There is a list in the lower corner, perhaps of Caeleb's conquests, and includes things like titan, earth drake, earth elementals, trolls, hydra, beholders.",
        "kitchen" : "You can see heavy cast iron pots and pans hanging from a rack in the kitchen over the cabinets and sink.  A stove for cooking has wood piled beside it.  A sketch here shows a feast set up in a tower but it seems a little grizzly.  Jotted in the corner is 'Muileann, take a friend but don't stay for dinner.'",
        "parlor" : "The parlor has a cozy couch covered with a sturdy fabric that has a %^GREEN%^forest scene%^RESET%^ on each cushion.  A large oval woven rug covers the center of the room.  A painting here shows an island with tough warrior-type women standing on a cliff looking down over a swamp.  A note in the corner reads 'Dallyh - 22,13 - tough women!'.",
        "dining room" : "The dining room has a massive oak table with ten chairs around it.  The chairs at each end have arms and look very comfortable. A series of caverns is depicted in a painting here opening up to an island with pirates.  It is labeled 'No friends of mine but great seafood - 0,55'" ,
        ({"floor", "rugs"}) : "The floor is nicely polished wood.  The wood is inlaid in interesting patterns in some of the rooms or mostly covered with fur hides or woven rugs in others.  One rug is woven with a scene of a %^BOLD%^%^GREEN%^huge emerald dragon %^RESET%^chasing a large group of well-equipped and tough-looking adventurers from an island.",
        ({"lamps","lamp","oil lamps"}) : "Oil lamps hang from decorative wrought iron holders and give off a pleasant scent as they burn.",
        ]));
        set_exits(([
        "east" : MAINTOWN"wrstreet4",
        ]));
        set_door("green door","/d/newbie/rooms/town/wrstreet4","east",0);
}