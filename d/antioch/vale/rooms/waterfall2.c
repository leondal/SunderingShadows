#include <std.h>
#include "../vale.h"
inherit ROOM;

void create()
{
   ::create();
   set_terrain(NAT_CAVE);
   set_travel(RUTTED_TRACK);
   set_property("indoors",1);
   set_property("light",0);
   set_property("no sticks",1);
   set_short("Behind the Waterfall");
   set_long(
   "%^CYAN%^You are west of the cave entrance, it is slightly dryer here but"+
   " for some reason it is getting a bit %^RED%^hotter%^CYAN%^. To the east the floor"+
   " inclines down to be just above the level of the lake. To the"+
   " southwest there is less of an incline going up.\n"
   );
   set_listen("default",
   "The roar of the waterfall echoes through the cave.");
   set_smell("default","The air is a bit hot and sticky.");
   set_items(([
   ({"walls","ceiling"}) : "%^ORANGE%^The walls and ceiling are very smooth and"+
   " are dry here.",
   "floor" : "%^BOLD%^To the east the floor angles down towards the waters of"+
   " the lake, to the southwest there is less of an upward incline,"+
   " although it is still apparent. The floor is fairly dry here.",
   "waterfall" : "%^BOLD%^%^CYAN%^The waterfall crashes down to the east, concealing"+
   " this cave.",
   ]));
   set_exits(([
   "east" : ROOMS+"waterfall1",
   "southwest" : ROOMS+"waterfall3",
   ]));
}
