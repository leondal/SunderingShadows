#include <std.h>
#include "../valley.h"
inherit ROOM;

void create()
{
   ::create();
   set_travel(RUTTED_TRACK);
   set_terrain(NAT_CAVE);
   set_property("indoors",1);
   set_property("light",1);
   set_short("A cave");
   set_long(
   "Further back in the cave the light has waned and everything is rather dark and"+
   " gloomy. The cave floor is smoother here, as are the walls, but the ceiling is"+
   " much lower. Only a little bit of dirt has been tracked back here, it appears"+
   " as though the bear must prefer the entrance of the cave. Perhaps he got sick of"+
   " bumping his head on the ceiling, for there's barely room for a person of normal"+
   " height to stand, everyone else must stoop a little or whack their head against"+
   " the hard stone. The cave stops here, however, there's nothing to do but turn"+
   " around and go back."
   );
   set_smell("default",
   "There's a musty smell in the air."
   );
   set_listen("default",
   "There is no sound."
   );
   set_items( ([
   ({"wall","walls"}) : "The walls are made of smooth stone.",
   "ceiling" : "The ceiling slopes down here, and although it's smoother, it's still"+
   " made of stone and bumping your head would hurt. It's only about six feet high.",
   "floor" : "The floor has turned from bumpy to smooth and there isn't so much dirt"+
   " on the ground here.",
   ]) );
   set_exits( ([
   "south" : ROOMS+"cave1",
   ]) );
}
