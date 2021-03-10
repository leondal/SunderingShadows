
#include <std.h>

inherit "/d/attaya/tower/spec/tower";


void create(){
      ::create();
      set_travel(LEDGE);
	set_property("light",3);
	set_property("indoors",1);
   set_property("no teleport",1);
       set_short("Metal catwalk over rushing water");
        set_long("%^BLUE%^Metal catwalk over %^BOLD%^%^BLUE%^r%^RESET%^%^BLUE%^u%^BOLD%^%^BLUE%^s%^RESET%^%^BLUE%^h%^BLUE%^i%^BOLD%^%^BLUE%^n%^RESET%^%^BLUE%^g %^BLUE%^w%^BLUE%^a%^BOLD%^%^BLUE%^te%^RESET%^%^BLUE%^r
%^BLUE%^You are walking along a %^BOLD%^%^BLACK%^m%^RESET%^%^CYAN%^et%^BOLD%^%^BLACK%^a%^RESET%^%^CYAN%^l %^CYAN%^mesh %^BOLD%^%^BLACK%^c%^RESET%^%^CYAN%^a%^BOLD%^%^BLACK%^t%^RESET%^%^CYAN%^wal%^BOLD%^%^BLACK%^k%^RESET%^%^BLUE%^ about a hundred feet over %^BOLD%^%^BLUE%^f%^RESET%^%^BLUE%^a%^BOLD%^%^BLUE%^st %^BLUE%^mov%^BOLD%^%^BLUE%^i%^RESET%^%^BLUE%^ng %^BOLD%^%^BLUE%^w%^RESET%^%^BLUE%^a%^BOLD%^%^BLUE%^ter.%^RESET%^%^BLUE%^ It makes you extremely nervous to look %^CYAN%^d%^BOLD%^%^BLACK%^o%^RESET%^%^CYAN%^wn%^BLUE%^ because far beneath the thin meshwork of the catwalk, the entire surface is franticly moving southward in a rush. A large room is built into the wall to the west and opens out into this chamber! There are wooden planks that have been nailed to the catwalk that lead across to open doors to the north and south. You long to find more secure ground.");
     set_listen("default", "Water roars around beneath you, rushing in fast currents.");
       set_exits(([
       "north" : "/d/attaya/tower/floor15",
       "south" : "/d/attaya/tower/floor16",
       "west" : "/d/attaya/tower/floor17",
       "east" : "/d/attaya/tower/floor11",
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
