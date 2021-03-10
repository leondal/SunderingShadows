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
   set_short("Path to the Keep");
   set_long(
   "A large keep looms ahead of you to the north. It is in bad shape, you"+
   " can tell that some sections have collapsed, and there are vines growing"+
   " up the sides of the walls. The path you are on has gotten some use, but"+
   " is not in good shape. It is mostly muddy and there are numerous small"+
   " footprints in the muck. Just south of here the path intersects with"+
   " a trail that's in better shape."
   );
   set_smell("default","You smell the mud of the path.");
   set_listen("default","You hear the sound of the wind whistling through"+
   " the cracks in the walls.");
   set_items(([
   ({"structure","large structure"}) : "The structure is obviously that of"+
   " a large keep, but you can tell that entire sections have collapsed and"+
   " there are weeds and vines growing up along the walls.",
   "path" : "The path you are on is fairly narrow and rather muddy. It has"+
   " gotten some recent use, although clearly hasn't been maintained. There"+
   " are numerous small footprints in the muck, as well as a much larger one"+
   " every now and then.",
   ]));
   set_exits(([
   "north" : ROAD"path13",
   "southwest" : ROAD"path11",
   ]));
}
