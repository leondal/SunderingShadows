#include <std.h>
#include "../../newbie.h"
inherit "/d/newbie/rooms/inherit/keepmove.c";

void create()
{
   ::create();
   set_property("light",2);
   set_property("no teleport",1);
   set_terrain(SCRUB_LANDS);
   set_travel(FOOT_PATH);
   set_short("A quiet trail");
   set_long(
   "This is a quiet dirt trail that runs to the western distance. It stops"+
   " here and intersects with a path that runs northeast and southwest. The"+
   " trail is fairly dusty here, but the path to the northeast is rather"+
   " muddy. The path to the south travels down an incline, you can see it"+
   " continues further to the southwest to intersect with a larger trail"+
   " in the distance. That path is fairly overgrown with weeds and doesn't"+
   " seem to get much use."
   );
   set_smell("default","You smell the fresh air of the open land.");
   set_listen("default","You hear the sound of the wind rushing across the open land.");
   set_items(([

   ]));
   set_exits(([
//   "west" : ROAD"?",
   "northeast" : ROAD"path12",
   "south" : ROAD"path10",
   ]));
}
