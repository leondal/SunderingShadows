
#include <std.h>

inherit "/d/attaya/tower/spec/tower";


void create(){
      ::create();
	set_property("light",3);
	set_property("indoors",1);
   set_property("no teleport",1);
       set_short("End of the passage");
        set_long("%^BLUE%^End of the passage
%^BLUE%^This is a large room that opens out into the vast chamber to the east. Beyond partial dividers to the north and south, the room continues and is endcapped by strange %^CYAN%^da%^BOLD%^%^BLACK%^r%^RESET%^%^CYAN%^k %^BOLD%^%^BLACK%^w%^RESET%^%^CYAN%^a%^BOLD%^%^BLACK%^l%^RESET%^%^CYAN%^l%^BOLD%^%^BLACK%^s%^BLACK%^.%^RESET%^%^BLUE%^ There is no railing at this center portion to protect you from falling into the %^CYAN%^wa%^BOLD%^%^BLACK%^t%^RESET%^%^CYAN%^e%^BOLD%^%^BLACK%^r%^BLACK%^y%^RESET%^%^BLUE%^ depths to the east. It may be wise not to stand too close.
");
     set_listen("default", "Water roars around beneath you, rushing in fast currents.");
       set_exits(([
       "north" : "/d/attaya/tower/floor18",
       "south" : "/d/attaya/tower/floor19",
       "east" : "/d/attaya/tower/floor14",
]));
       set_items(([
    "ceiling" : "Blue-gray tiles make up the ceiling.",
    "floor" : "Blue-gray tiles make up the floor.",
    "walls" : "Molded plaster rises half way up the brick walls.",
     "water" : "The dark waters are about 100 feet beneath you and rush in powerful currents into black holes.",
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
 write("%^BOLD%^You almost lose your balance!  You purposely fall backwards and remain on the platform.",TP);
  say((string)this_player()->query_cap_name()+" gets too close to the edge and nearly falls to "+this_player()->query_possessive()+" doom.\n");
    return 1;
}
    return 0;
}
