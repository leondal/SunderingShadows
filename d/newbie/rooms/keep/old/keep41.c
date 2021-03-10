#include <std.h>
#include "keep.h"
inherit ROOM;

void create()
{
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",1);
   set_short("A secret passage");
   set_long(
   "You are standing at the dead end of a secret passage. There is a stool set up"+
   " near the western wall. It appears as though someone used to sit there and wait,"+
   " but for what? Staring at a wall doesn't seem too entertaining. There must be"+
   " some purpose to the passage, however, you just have to find it."
   );
   set_smell("default","The passage is filled with dust.");
   set_listen("default","Everything is fairly quiet.");
   set_items(([
   "floor" : "The floor has a rug laid out across it and is covered in dust.",
   "rug" : "The rug appears faded and rather worn, it was probably placed here to"+
   " keep footsteps from echoing and giving the secret passage away. It extends"+
   " to the and east.",
   "walls" : "The walls are made of unremarkable stone blocks and appear"+
   " quite sturdy. The western wall appears a little less dusty than the other two.",
   "stool" : "There is a wooden stool set up near the western wall, in a perfect"+
   " position for someone to sit and stare at the center of the wall. But why?",
   ({"west wall","western wall","wall"}) : "The western wall appears sturdy enough,"+
   " and a bit less dusty than the other walls for some reason. Upon closer inspection"+
   " you find a small crack in the center of the wall that appears to have been"+
   " carefully chisled out.",
   "crack" : "The crack is in the center of the west wall and has been carefully"+
   " chisled by someone. It goes all the way through the wall to view the hallway"+
   " on the other side. It is more narrow at the far end, widening on this side"+
   " of the wall. It is probably undetectable from the other side of the wall, but"+
   " it would allow you to %^BOLD%^view%^RESET%^ the other side of the hallway if"+
   " you were so inclined.",
   ]));
   set_exits(([
   "east" : ROOMS+"keep40",
   ]));
}

void init()
{
   ::init();
   add_action("view","view");
}

void view(string str)
{
   object *stuff;
   int i;
   stuff = all_living(find_object_or_load(ROOMS+"keep12"));
   tell_object(TP,"%^BOLD%^%^BLUE%^You feel like a spy as you peer through the crack.");
   tell_room(ETP,""+TPQCN+" looks through a crack "+TP->query_subjective()+" found"+
   " in the west wall.",TP);
   tell_object(TP,"Hallway of a Ruined Keep\n");
   for(i=0;i<sizeof(stuff);i++) {
      if(!stuff[i]->query_invis())
         tell_object(TP,stuff[i]->query_short());
   }
   return 1;
}
