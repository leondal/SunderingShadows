#include <std.h>
#include "forest.h"
inherit ROOM;

void create()
{
   ::create();
   set_terrain(ROCKY);
   set_travel(DIRT_ROAD);
   set_property("light",2);
   set_property("indoors",0);
   set_short("A sharply inclined path");
   set_long(
   "%^BOLD%^You are walking along a sharply inclined path.%^RESET%^\n"+
   "The road runs northwest and southeast here, inclining sharply to the"+
   " northwest with a steep descent out of the foothills and into some"+
   " grassy plains to the southeast."
   );
   set_smell("default","You smell the fresh air.");
   set_listen("default","You can hear animals in the brush.");
   set_items(([
   "road" : "This is really just a glorified dirt path, but someone keeps"+
   " it in good shape. It is sharply inclined here, running up towards"+
   " the northwest and down towards the southeast.",
   ]));
   set_exits(([
   "southeast" : FORESTDIR+"road47",
   "northwest" : FORESTDIR+"road45",
   ]));
}
