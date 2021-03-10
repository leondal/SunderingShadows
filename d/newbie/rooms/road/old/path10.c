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
   " There is a large stone structure looming to the north, although it"+
   " appears to be in disrepair. The path intersects with another trail"+
   " just to the north. To the south the path continues, winding down to"+
   " the southeast you can see it intersects with another trail in the"+
   " distance."
   );
   set_smell("default","You smell the fresh air of the open land.");
   set_listen("default","You hear the sound of the wind rushing across the open land.");
   set_items(([
   ({"structure","large structure"}) : "The structure is a bit clearer now,"+
   " it is probably a castle or keep of some sort, made up of large stone"+
   " blocks. It looks as though it's not in very good shape.",
   ({"path","overgrown path"}) : "The path is simply dirt, although you can"+
   " see a few cracked cobbles every now and then. It is overgrown with"+
   " vines and weeds and probably doesn't get much use at all anymore.",
   ]));
   set_exits(([
   "north" : ROAD"path11",
   "southwest" : ROAD"path9",
   ]));
}
