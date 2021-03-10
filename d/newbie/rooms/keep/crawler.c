#include <std.h>
#include "../inherit/keep.h"
inherit INH+"keephall2";

int SEARCHED;

void create()
{
   set_monsters(({MONS+"crawler"}),({1}));
   ::create();
   set_repop(60);
   set_name("Buried room in a ruined keep");
   set_short("%^RESET%^%^CYAN%^Buried room in a ruined keep%^RESET%^");
   set_long(((:TO,"my_long":)));
   set_smell("default","There is an unpleasant smell coming from somewhere.");
   set_items(([
     ({"walls","holes","cracks","roof"}) : "%^BLUE%^The stone walls and roof "
"that make up the keep are in poor shape here.  The walls are still holding up "
"in places, but the roof has fallen in entirely.  The wind whistles in from "
"above and through cracks in the stone masonry, and moisture creeps in from "
"beyond.  %^GREEN%^Moss %^BLUE%^has grown over some sections, making footing "
"dangerous.  %^ORANGE%^Rubble %^BLUE%^is strewn all around, completely burying "
"the hallway further to the south, and limiting progress back into the "
"remaining keep to the north.%^RESET%^",
     "lair" : ((:TO,"lair_desc":)),
     "moss" : "%^GREEN%^Patches of moss have grown over the walls and floor.  "
"They are wet and slimy, making footing treacherous in some places.%^RESET%^",
     "rubble" : ((:TO,"rubble_desc":)),
   ]));
   set_exits(([
     "north" : ROOMS"keep20",
   ]));
   find_object_or_load(ROOMS"keep20");
   set_search("default","%^ORANGE%^The %^YELLOW%^rubble %^RESET%^%^ORANGE%^"
"stands out as an obvious problem.  Also, while the %^RED%^lair %^ORANGE%^"
"absolutely reeks, it is big enough to hide just about anything.%^RESET%^");
   set_search("lair",(:TO,"search_em":));
   TO->collapse_exit("north",50);
   return;
}

string rubble_desc() {
   if(member_array("north",TO->query_exits()) == -1) 
     return("%^ORANGE%^The roof has completely fallen in, leaving a great "
"pile of rubble that has buried anything further south, and makes it difficult "
"to progress northwards.  You could try to %^YELLOW%^dig north%^RESET%^"
"%^ORANGE%^ to create a way through.%^RESET%^");
   return("%^ORANGE%^The roof has completely fallen in, leaving a great "
"pile of rubble that has buried anything further south, and makes it difficult "
"to progress northwards.  Fortunately someone has cleared a way through "
"it.%^RESET%^");
}

string my_long() {
   if(member_array("north",TO->query_exits()) == -1)
     return("%^RESET%^%^CYAN%^Buried room in a ruined keep%^RESET%^\n"
"This is the end of the hallway, as the %^BLUE%^roof %^RESET%^has entirely "
"caved in past this point, and anything beyond seems to be irretrievably "
"buried.  Fallen stones have piled up here, and it appears that some creature "
"has made a rough %^RED%^lair %^RESET%^here.  The %^BLUE%^walls %^RESET%^are "
"badly damaged, letting in the wind and the damp.  The trail of "
"%^ORANGE%^rubble %^RESET%^extends all around you and into the hallway, where "
"it limits any progress north.");
   return("%^RESET%^%^CYAN%^Buried room in a ruined keep%^RESET%^\n"
"This is the end of the hallway, as the %^BLUE%^roof %^RESET%^has entirely "
"caved in past this point, and anything beyond seems to be irretrievably "
"buried.  Fallen stones have piled up here, and it appears that some creature "
"has made a rough %^RED%^lair %^RESET%^here.  The %^BLUE%^walls %^RESET%^are "
"badly damaged, letting in the wind and the damp.  The trail of "
"%^ORANGE%^rubble %^RESET%^extends all around you and into the hallway, where "
"it limits any progress north.\n");
}

string lair_desc() {
   if(SEARCHED) return("%^RED%^Some creature seems to be lairing among the "
"rubble, judging by the rough nest-like mound lying off to the side.  The "
"nest smells rotten, and it looks as though someone has recently searched "
"through it.%^RESET%^");
   return("%^RED%^Some creature seems to be lairing among the rubble, "
"judging by the rough nest-like mound lying off to the side.  The nest "
"smells rotten, but you could probably %^YELLOW%^search %^RESET%^%^RED%^it "
"to see if it was hiding anything good.%^RESET%^");
}

void reset() 
{
   ::reset();
   SEARCHED = 0;
   return;
}

int search_em() {
   if(present("crawler")) {
     tell_object(TP,"There is a creature in the way!");
     return 1;
   }
   if(SEARCHED) {
     tell_object(TP,"%^RED%^It looks as though someone has already searched "
"through the lair, and taken anything of interest.%^RESET%^");
     tell_room(ETP,"%^RED%^"+TPQCN+" searches around but doesn't find "
"anything.%^RESET%^",TP);
     return 1;
   }
   tell_object(TP,"%^RED%^You rummage through the makeshift lair.  Mostly "
"it seems nothing but rubbish, but you do find a very interesting "
"%^ORANGE%^stave%^RED%^.%^RESET%^");
   tell_room(ETP,"%^RED%^"+TPQCN+" searches around in the makeshift lair, "
"and seems to find something.%^RESET%^",TP);
   new(OBJ2"staffstave")->move(TO);
   SEARCHED = 1;
   return 1;
}
