
#include <std.h>

inherit "/d/attaya/tower/spec/tower";


void create(){
      ::create();
	set_property("light",3);
	set_property("indoors",1);
   set_property("no teleport",1);
       set_short("Metal catwalk over rushing water");
        set_long("%^BLUE%^Metal catwalk over %^BOLD%^%^BLUE%^rush%^RESET%^%^BLUE%^i%^BOLD%^%^BLUE%^ng %^BLUE%^wat%^RESET%^%^BLUE%^e%^BOLD%^%^BLUE%^r%^RESET%^
%^BLUE%^You are walking along a metal mesh catwalk about a hundred feet over fast moving %^CYAN%^wa%^BOLD%^%^BLACK%^t%^BLACK%^e%^RESET%^%^CYAN%^r.%^BLUE%^ It makes you extremely nervous to look down because far beneath the thin meshwork of the catwalk, the entire surface is franticly moving southward in a rush. The main %^CYAN%^wall%^BLUE%^ to this chamber lies just to the east. An opening in the wall reveals a staircase leading up to the library. You long to find more secure ground.");
     set_listen("default", "Water roars around beneath you, rushing in fast currents.");
       set_exits(([
       "west" : "/d/attaya/tower/floor8",
       "staircase" : "/d/attaya/tower/link",
]));
       set_items(([
    "ceiling" : "It is about 30 feet above you and is made of wooden planks braced by metal poles.  Ropes attach to eyelets to hold up the catwalk.",
    "floor" : "You can see right through the metal mesh of the catwalk, but prefer not to.",
    "wall" : "It is a wall made of enormous granite blocks.",
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
