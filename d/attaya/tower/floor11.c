
#include <std.h>

inherit "/d/attaya/tower/spec/tower";


void create(){
      ::create();
      set_travel(LEDGE);
	set_property("light",3);
	set_property("indoors",1);
   set_property("no teleport",1);
       set_short("Metal catwalk over rushing water");
        set_long("%^BLUE%^Metal catwalk over %^BLUE%^r%^BOLD%^%^BLUE%^ush%^RESET%^%^BLUE%^i%^BOLD%^%^BLUE%^ng %^BLUE%^w%^RESET%^%^BLUE%^a%^BOLD%^%^BLUE%^ter%^RESET%^
%^BLUE%^You are walking along a %^BOLD%^%^BLACK%^m%^RESET%^%^CYAN%^e%^BOLD%^%^BLACK%^t%^RESET%^%^CYAN%^a%^BOLD%^%^BLACK%^l%^RESET%^ %^CYAN%^m%^BOLD%^%^BLACK%^e%^RESET%^%^CYAN%^s%^BOLD%^%^BLACK%^h%^RESET%^ %^BOLD%^%^BLACK%^c%^BLACK%^a%^RESET%^%^CYAN%^twalk%^BLUE%^ about a hundred feet over %^BOLD%^%^BLUE%^fast %^BLUE%^mo%^RESET%^%^CYAN%^v%^BOLD%^%^BLUE%^ing %^RESET%^%^BLUE%^w%^BOLD%^%^BLUE%^ater.%^RESET%^%^BLUE%^ It makes you extremely nervous to look down because far beneath the thin meshwork of the catwalk, the entire surface is moving southward in a rush. You long to find more secure ground.");
     set_listen("default", "Water roars around beneath you, rushing in fast currents.");
       set_exits(([
       "west" : "/d/attaya/tower/floor14",
       "east" : "/d/attaya/tower/floor8",
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
