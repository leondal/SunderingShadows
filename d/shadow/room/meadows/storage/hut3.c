#include <std.h>
#include "../meadow.h"
inherit ROOM;

void create()
{
   ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
   set_property("light",3);
   set_property("indoors",1);
   set_short("A cluttered hut");
   set_long(
   "The hut is rather cluttered with all sorts of clothing, fabrics,"+
   " dress patterns, scissors, dyes, and measuring tools. There are"+
   " hangers, chests, and closets full of clothing here. There is a small"+
   " couch on the west side of the room with a stool near it. You can"+
   " make out a small bed and tiny table in the back of the room behind"+
   " many clothes hangers. There are bits of fabric all over the floor,"+
   " and you can see spots where dye has spilled and stained the wood."+
   " Beneath all the clutter the room seems clean enough at least."
   );
   set_smell("default","A light cinnamon fragrance hangs in the air.");
   if(query_night() == 1) {
      set_listen("default","The crickets are noisy outside.");
   }
   else {
      set_listen("default","The birds are singing merrily outside.");
   }
   set_items(([
   "floor" : "The floor is covered with bits and pieces of fabric that"+
   " have been snipped off of clothing. You can see places where dye has"+
   " been spilled and stained the wood. Despite all the clutter, there"+
   " doesn't seem to be much dirt or dust.",
   ({"small bed","bed"}) : "You can barely see a bed in the very back of"+
   " the room there are so many clothes hangers in between. It looks to be"+
   " about five feet long and is covered in a beautiful patch-work quilt.",
   ({"quilt","patch-work quilt"}) : "The quilt covering the bed is really"+
   " breath taking. Smaller squares with intricate patterns have been"+
   " sewn together to make the entire piece. Most of the smaller scenes"+
   " are of individual things, such as flowers and plants, some houses,"+
   " halflings, and their burrows, but it comes together to make an entire"+
   " world of halfling life and culture and is really very remarkable.",
   ({"table","tiny table"}) : "There is a tiny table in the back of the"+
   " room next to the bed, it has one small chair seated there and a half"+
   " finished meal. The rest of the table is covered in bolts of fabric"+
   " and pin cushions.",
   ({"fabric","bolts","bolts of fabric"}) : "Bolts of fabric are all over"+
   " the room in a rainbow of colors.",
   "couch" : "There is a small couch on the west side of the room, it might"+
   " be able to fit two slender people or one large person comfortably."+
   " Draped over the back of the couch are many articles of clothing.",
   "stool" : "There is a stool near the couch on the west side for"+
   " customers to sit while they are being measured for certain items,"+
   " or perhaps for the tailor to stand on to reach some of her customers!",
   "closets" : "There are a few standing wooden closets tucked into the"+
   " corners of the room, all of them are quite filled with clothing.",
   "chests" : "There are several wooden chests about the room that are"+
   " filled with fabric or clothing.",
   ({"clothes hangers","hangers"}) : "Several large standing wooden hangers"+
   " have been setup about the room from which you can hang clothing. All"+
   " of them are full.",
   "clothing" : "Clothing of various sizes, styles, cuts, and colors is"+
   " scattered all over the room.",
   "scissors" : "There are a couple pairs of scissors scattered about the"+
   " room.",
   ({"dye","dyes"}) : "There are jars and sometimes large barrels of dyes"+
   " of all different colors and shades scattered about the room.",
   ({"patterns","dress patterns"}) : "A few dress patterns can be found"+
   " here and there, some with design changes marked on them.",
   ({"tools","measuring tools"}) : "There are several sets of measuring"+
   " tools about the room, sized for all types of people.",
   ]));
   set_exits(([
   "north" : ROOMS+"meadow6",
   ]));
   set_post_exit_functions(({"north"}),({"GoThroughDoor"}));
}

void reset()
{
   ::reset();
   if(!present("seamstress")) {
      new(MONS+"farith")->move(TO);
   }
}

int GoThroughDoor()
{
   if(TP->query_size() > 2) {
      tell_object(TP,"You're relieved to stand up right once more!");
   }
   return 1;
}
