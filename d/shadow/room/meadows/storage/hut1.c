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
   set_short("A simple hut");
   set_long(
   "This is a quaint little wood hut that is obviously made for a rather"+
   " small person. You can see a bed in the northeastern corner that looks"+
   " about the right size for a child. There is a chest of clothing at"+
   " the foot of the bed, and a little table in the center of the room"+
   " with a couple of small chairs placed about it. There is a fireplace"+
   " along the east wall with a pot of fish stew slowly bubbling on it."+
   " You notice a fishing pole in one corner, and a couple of rather small"+
   " but intricately carved fish hooks and other small nicknacks."
   );
   set_smell("default","You can smell the fish stew.");
   set_listen("default","The wind blows through the reeds outside.");
   set_items(([
   "bed" : "The bed in the northeastern corner appears to be about the right"+
   " size for a child. It is filled with pillows and blankets and does"+
   " look rather comfortable.",
   "chest" : "There is a wooden chest at the foot of the bed that appears"+
   " to be filled with clothing. The top has been intricately engraved"+
   " in a beautiful pattern of intertwined leaves and flowers.",
   "table" : "There's a small table in the middle of the room that looks"+
   " as though it serves as a miniature workshop and dining table all in"+
   " one. A couple chairs have been placed around it.",
   "chairs" : "Some simple wooden chairs have been placed around the table"+
   " in the middle of the room.",
   "fireplace" : "There is a stone fireplace along the east wall with a"+
   " pot of stew slowly bubbling on it.",
   ({"pot","stew","pot of stew"}) : "The pot on the fireplace contains"+
   " fish stew that has been mixed with herbs and some other vegetables,"+
   " it smells delicious.",
   "floor" : "The floor of the hut is rather dusty, although it appears"+
   " someone has made an effort to keep it somewhat clean.",
   ({"pole","fishing pole"}) : "There is a fishing pole leaning against"+
   " one corner with a hook dangling from it.",
   ]));
   set_exits(([
   "west" : ROOMS+"pond",
   ]));
   set_post_exit_functions(({"west"}),({"GoThroughDoor"}));
}

void reset()
{
   ::reset();
   if(!present("meriago")) {
      new(MONS+"meriago")->move(TO);
   }
}

int GoThroughDoor()
{
   if(TP->query_size() > 2) {
      tell_object(TP,"You're relieved to stand up right once more!");
   }
   return 1;
}
