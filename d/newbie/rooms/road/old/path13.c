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
   "A large keep stands directly in front of you. It is in bad shape, you"+
   " can tell that some sections have collapsed, and there are vines growing"+
   " up the sides of the walls. Before you is the entrance which stands wide"+
   " open with the doors laying on the floor on the inside. The muddy path"+
   " you're on continues to the south."
   );
   set_smell("default","You smell the muddy path and mildew of the keep.");
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
   "north" : "/d/newbie/rooms/keep/keep1",
   "south" : ROAD"path12",
   ]));
}
