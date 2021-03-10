
#include <std.h>

inherit "/d/attaya/tower/spec/tower";


void create(){
      ::create();
      set_travel(LEDGE);
	set_property("light",3);
	set_property("indoors",1);
   set_property("no teleport",1);
       set_short("Metal catwalk over rushing water");
        set_long("
    You are walking along a metal mesh catwalk about a hundred feet over fast moving water.  It makes you extremely nervous to look down because far beneath the thin meshwork of the catwalk, the entire surface is moving southward in a rush.
    There are wooden planks that have been nailed to the catwalk that lead across to open doors to the north and south.  
    You long to find more secure ground.
");
     set_listen("default", "Water roars around beneath you, rushing in fast currents.");
       set_exits(([
       "north" : "/d/attaya/tower/floor9",
       "south" : "/d/attaya/tower/floor10",
       "west" : "/d/attaya/tower/floor11",
       "east" : "/d/attaya/tower/floor5",
]));
       set_items(([
    "ceiling" : "It is about 30 feet above you and is made of wooden planks braced by metal poles.  Ropes attach to eyelets to hold up the catwalk.",
    "floor" : "You can see right through the metal mesh of the catwalk, but prefer not to.",
     "water" : "The dark waters are about 100 feet beneath you and rush in powerful currents into black holes.",
    "down" : "The metal mesh is directly beneath you, you could get a better look at the water if you looked over the edge",
     "catwalk" : "The iron mesh catwalk stretches from the west wall to the east wall.  It is connected by heavy grade rope to large eyelets in the ceiling.  100 feet beneath you is watery chaos.",
    "intruder" : "You are not sure if your mind is playing tricks on you.",
]));
	
}
void init() {
  ::init();
   add_action("look", "look");
}
int look(string str) {
  if(str=="over the edge") {
 write("%^BOLD%^You almost lose your balance!  You cling to a nearby rope.",TP);
  say((string)this_player()->query_cap_name()+" gets too close to the edge and clings to a rope to avoid falling to "+this_player()->query_possessive()+" doom.\n");
    return 1;
}
    return 0;
}
