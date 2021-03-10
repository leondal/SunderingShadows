//store
#include <std.h>
#include "elf.h"
inherit VAULT;


void create(){
    ::create();
set_property( "light", 2);
    set_property( "indoors", 1);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_name("Store");
    set_short("Store");
    set_long(
"%^GREEN%^This large room becomes a cozy elve%^BOLD%^%^MAGENTA%^n%^RESET%^%^GREEN%^ store%^MAGENTA%^.%^GREEN%^  It is a large room with a "+
"fairly low roof%^MAGENTA%^.%^GREEN%^ The ceiling has several thick %^ORANGE%^limbs%^GREEN%^ that criss-cross above "+
"one's head and down the corners of the walls adding stability and "+
"atmosphere%^MAGENTA%^.%^GREEN%^  Shades cover over the windows with leaves similar to %^BOLD%^weeping "+
"willows%^RESET%^%^MAGENTA%^.%^GREEN%^  The floor is covered in a large%^MAGENTA%^,%^GREEN%^ woven %^BOLD%^green rug%^RESET%^%^MAGENTA%^.%^GREEN%^  The walls are "+
"made of %^RESET%^stone%^GREEN%^ with %^ORANGE%^tree limbs%^GREEN%^ supporting the corners%^MAGENTA%^.%^GREEN%^  To the south there "+
"is a %^ORANGE%^fi%^YELLOW%^re%^RESET%^%^ORANGE%^pla%^YELLOW%^ce%^RESET%^%^GREEN%^ built into the wall%^MAGENTA%^.%^GREEN%^  Potted plants don the room%^MAGENTA%^.%^GREEN%^ They are "+
"lying on floor%^MAGENTA%^,%^GREEN%^ sitting on the tables%^MAGENTA%^,%^GREEN%^ and hanging from the ceiling%^MAGENTA%^.%^GREEN%^  "+
"Several greenish couches%^MAGENTA%^,%^GREEN%^ tables and chairs are scattered "+
"about%^MAGENTA%^.%^GREEN%^  The furniture seems all painstakingly made%^MAGENTA%^.%^GREEN%^  Several soft purple "+
"%^BOLD%^%^MAGENTA%^lights%^RESET%^%^GREEN%^ float about softly next to the walls and elegantly%^MAGENTA%^,%^GREEN%^ obviously created "+
"by elven %^BOLD%^%^MAGENTA%^magic%^MAGENTA%^. %^RESET%^");

	set_items(([
      (({"limbs"})) :
        "Tree limbs grow through the room.",
      (({"windows","leaves","weaping willows"})) : "The windows are covered with weaping willow leaves.",
      (({"walls","stone"})) : "The room is made of stone as a base.  The rest is decoration. ",
	  (({"couch","couches","chairs"})) : "Several green cloth couches and chairs are here. ",
	  (({"lights","purple lights"})) : "Floating balls of purple lights cast a glow in this room. ",
	   ]));

   
      set_exits(([ "south" : ROOMS"hall1",
        "east" : ROOMS"hall7",	  ]));

   set_listen("default","It smells fresh here.");
   set_smell("default",
   "Sounds of shopping can be heard.");
}
void reset(){
::reset();
if(!present("shanta")) new(MON"shanta")->move(TO);
}
