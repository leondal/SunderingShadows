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
   set_short("An overgrown path");
   set_long(
   "You are on an overgrown dirt path that doesn't appear to get much use."+
   " There is a slight incline to the northeast, and you can see that the"+
   " path continues to a larger structure of some sort, but it is hard to"+
   " tell what from here. The path begins to rise again towards the north,"+
   " but is still level to the west."
   );
   set_smell("default","You smell the fresh air of the open land.");
   set_listen("default","You hear the sound of the wind rushing across the open land.");
   set_items(([
   ({"structure","large structure"}) : "From this distance you can't make"+
   " out much more than a vague rectangular shape to the far northeast.",
   ({"path","overgrown path"}) : "The path is simply dirt, although you can"+
   " see a few cracked cobbles every now and then. It is overgrown with"+
   " vines and weeds and probably doesn't get much use at all anymore.",
   ]));
   set_exits(([
   "north" : ROAD"path7",
   "west" : ROAD"path5",
   ]));
}
