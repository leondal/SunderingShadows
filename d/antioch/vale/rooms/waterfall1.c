// added terrian 1/12/10 hades
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
   "%^CYAN%^You are standing at the entrance of a cave that travels deeper"+
   " into the cliff. To the east is a crashing %^BOLD%^waterfall%^RESET%^%^CYAN%^ that partially"+
   " conceals this opening, with a foot wide path of %^ORANGE%^stone%^CYAN%^ on the"+
   " north side of the cave that leads out to %^BOLD%^Moonstone Vale%^RESET%^%^CYAN%^. The"+
   " walls of the cave are all very smooth and slick, dripping %^BOLD%^%^BLUE%^water"+
   " %^RESET%^%^CYAN%^in places. To the west there is a slight incline as the cave"+
   " moves higher away from the waters.\n"
   );
   set_listen("default",
   "The roar of the waterfall echoes through the cave.");
   set_smell("default","The air is crisp and cool.");
   set_items(([
   ({"path","stone path","stone"}) : "%^ORANGE%^There is a path of smooth and"+
   " slick stone just over a foot wide that hugs the north wall of"+
   " this cave, leading out into Moonstone Vale.",
   ({"walls","ceiling"}) : "%^ORANGE%^The walls and ceiling are very smooth and"+
   " are covered in beads of water, some of which drip down from the"+
   " ceiling onto the floor.",
   "floor" : "%^BOLD%^The floor angles down towards the waters of the lake,"+
   " allowing the dripping water from the ceiling and walls to pour"+
   " into it. To the west it rises up further, getting dryer.",
   "waterfall" : "%^BOLD%^%^CYAN%^The waterfall crashes down to the east, concealing"+
   " this cave.",
   ]));
   set_exits(([
   "out" : ROOMS+"shore17",
   "west" : ROOMS+"waterfall2",
   ]));
}
