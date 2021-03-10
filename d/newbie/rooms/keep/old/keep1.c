#include <std.h>
#include "keep.h"
inherit ROOM;

void create() {
   object ob;
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",1);
   set_short("Entrance of a Ruined Keep");
   set_long(
   "This is the entrance of an old and ruined keep. It is in pretty bad"+
   " shape. There is %^GREEN%^moss%^RESET%^ growing over most of the walls and parts of the"+
   " floor, bricks are missing from the stone walls, and the ceiling doesn't"+
   " look all that sturdy either. It appears that at one point there were"+
   " two large doors that could be used to secure the entrance, but they"+
   " have been shattered and their remains now lie on the ground before"+
   " you. What's left of them is mostly rotted away with %^BOLD%^fungi%^RESET%^ feeding off"+
   " of them, the metal brackets that reinforced it are very rusty and look"+
   " to have been charred in places. Passages extend to the west, east, and"+
   " north, with the trail leading up to the keep back to the south."
   );
   set_smell("default","The musty odor of the fungus tickles your nose.");
   set_listen("default","The scrabbling of tiny claws on stone echoes faintly.");
   set_items(([
   "doors" : "You imagine that at one point in time these doors were quite"+
   " impressive. They appear to have been made of bronzewood and would have"+
   " been very sturdy with the metal brackets reinforcing them. Now their"+
   " remains are on the floor before you, partially pushed off to the side"+
   " to clear the entrance way. They have been badly splintered and must"+
   " have been decaying here for a long time, for bronzewood is normally"+
   " very sturdy and resistant to decomposition. Several varieties of"+
   " mushroom shaped fungus are feeding off of the remains.",
   ({"brackets","metal brackets"}) : "These metal brackets are incredibly"+
   " rusted and charred black in some places. They used to reinforce the"+
   " doors, and it appears as though they might have been blasted open.",
   ({"fungus","fungi"}) : "%^BOLD%^The fungi feeding on the door are"+
	" quite large and range in color from a dull grey to white. Most have"+
   " large, mushroom-shaped tops and appear to be doing quite well. There"+
   " are a few smaller varieties that look like %^RESET%^%^ORANGE%^orange%^RESET%^%^BOLD%^"+
   " curls closer to the bottom. These doors have obviously been decaying"+
   " for quite some time.",
   ({"walls","stone walls"}) : "The stone walls that make up the keep are"+
   " in pretty bad shape. There are blocks missing in some places, others"+
   " are cracked, and %^GREEN%^moss%^RESET%^ is growing over large sections."+
   " They do nothing to stop the chill wind from reaching the inner part"+
   " of the keep now.",
   "floor" : "The floor is made of stone bricks and is quite dirty. Mud and"+
   " %^GREEN%^moss%^RESET%^ hide most of it and make it slipper to walk on.",
   "ceiling" : "The ceiling is made of carefully squared stone blocks that have"+
   " been fitted together and are supported by beams in some places. The"+
   " beams have started to decay in some parts, and you don't get the"+
   " feeling that it is all too secure. One big earthquake might bring it"+
   " crashing down on your head.",
   "moss" : "%^GREEN%^Moss grows along most of the walls and has reached"+
   " down to cover parts of the floor as well. It is green and looks rather"+
   " slimy, making footing treacherous in some places.",
   "mud" : "The mud almost totally covers the floor. It's probably a mixture"+
   " of the settled dust with the water that appears to have leaked in"+
   " from the ceiling that is in rather bad shape.",
   ]));
   set_exits(([
   "west" : ROOMS+"keep2",
   "east" : ROOMS+"keep7",
   "north" : ROOMS+"keep9",
   "south" : "/d/newbie/rooms/road/path13",
   ]));
   ob = new("/d/newbie/obj/misc/1sign.c");
   ob->set_file("/d/newbie/obj/misc/sign7.txt");
   ob->move(TO);
}
