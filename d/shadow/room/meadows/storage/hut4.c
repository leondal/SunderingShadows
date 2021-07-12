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
   set_short("A nice hut");
   set_long("The room is covered in hides of various colors, sizes, and varieties."+
   " Stretched out in the center of the floor is a %^YELLOW%^lion skin rug%^RESET%^"+
   " that is over seven feet long. Antelope skins have been hung on the"+
   " walls here, some of them dyed with interesting patterns. There is"+
   " a wooden table on the east side of the room with a single chair. In"+
   " the northeastern corner is a bed with a %^ORANGE%^cheetah hide%^RESET%^"+
   " covering it. Many other furs and skins are hung around the room, some"+
   " have been made into hats and things, while others are still drying."+
   " %^RED%^The room is a blood-splattered mess!%^RESET%^"
   );
   set_smell("default","The scent of cured hides is strong here.");
   if(query_night() == 1) {
      set_listen("default","The crickets are noisy outside.");
   }
   else {
      set_listen("default","The birds are singing merrily outside.");
   }
   set_items(([
   ({"rug","lion skin rug","lion rug"}) : "%^YELLOW%^The lion skin rug"+
   " is quite large, reaching over seven feet without counting the tail."+
   " It is obviously the hide of a male lion, since the mane is still"+
   " intact. The face seems to be glaring up at you from its place on the"+
   " floor, white teeth sharp and gleaming.%^RESET%^",
   "floor" : "The floor is slightly dusty with a large lion skin rug covering"+
   " the center.",
   "ceiling" : "A few animal hides have been hung from the ceiling for lack"+
   " of other space it seems.",
   "table" : "On the east side of the room is a wooden table with one"+
   " small chair. It appears the occupant of the hut is not overly fond"+
   " of visitors.",
   "chair" : "There is only one small wooden chair next to the table.",
   "bed" : "There is a small bed tucked into the northeast corner with a"+
   " cheetah hide covering it.",
   ({"hide","cheetah hide"}) : "%^ORANGE%^A large and beautiful cheetah"+
   " hide is covering the bed in the northeast corner.%^RESET%^",
   ({"wall","walls"}) : "Skins of various types, although most of them are"+
   " antelope, are hung from the walls.",
   ({"skins","antelope skins"}) : "Antelope skins are hung from the walls"+
   " here. They are stretched out to be fully displayed, some of them have"+
   " pretty spotted patterns, while others have been dyed with varying"+
   " colors and designs.",
   ({"furs","hats","hides"}) : "Around the room are many items made from"+
   " various furs, some of them are finished but other hides are still"+
   " in the process of drying.",
   ]));
   set_exits(([
   "south" : ROOMS+"meadow18",
   ]));
   set_post_exit_functions(({"south"}),({"GoThroughDoor"}));
}

void reset()
{
   ::reset();
   //if(!present("vendor")) {
      //new(MONS+"periodo")->move(TO);
   //}
}

int GoThroughDoor()
{
   if(TP->query_size() > 2) {
      tell_object(TP,"You're relieved to stand up right once more!");
   }
   return 1;
}
