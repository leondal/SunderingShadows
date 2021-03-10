//gate inside
#include <std.h>
#include "elf.h"
inherit CVAULT;


void create(){
    ::create();
    set_terrain(ICE);
    set_travel(SLICK_FLOOR);
    set_property("light",3);
    set_climate("arctic");
    set_name("inside gate");
    set_short("inside gate");
    set_long(
"%^GREEN%^The %^BOLD%^gates%^RESET%^%^GREEN%^ open to a beautiful "+
"%^BOLD%^meadow%^RESET%^%^GREEN%^%^BOLD%^%^RESET%^%^CYAN%^,%^RESET%^%^GREEN%^ which somehow seems to fend off the pervading coldness of the "+
"mountain%^BOLD%^%^RESET%^%^CYAN%^.%^RESET%^%^GREEN%^ From here%^BOLD%^%^RESET%^%^CYAN%^,%^RESET%^%^GREEN%^ the %^BOLD%^gates%^RESET%^%^GREEN%^ are truly magnificant%^BOLD%^%^RESET%^%^CYAN%^.%^RESET%^%^GREEN%^ Dazzling light "+
"dances across their silver and gold surface%^BOLD%^%^RESET%^%^CYAN%^,%^RESET%^%^GREEN%^ reflecting beautifully off the "+
"ice%^BOLD%^%^RESET%^%^CYAN%^.%^RESET%^%^GREEN%^  Unlike the bitterly cold world outside the gates%^BOLD%^%^RESET%^%^CYAN%^,%^RESET%^%^GREEN%^ the meadow itself is "+
"pleasantly cool%^BOLD%^%^RESET%^%^CYAN%^,%^RESET%^%^GREEN%^ and covered in a light mist%^BOLD%^%^RESET%^%^CYAN%^.%^RESET%^%^GREEN%^  Off in the "+
"distance%^BOLD%^%^RESET%^%^CYAN%^,%^RESET%^%^GREEN%^ a %^BOLD%^grove%^RESET%^%^GREEN%^ of tall trees casts a shadow across the meadow%^BOLD%^%^RESET%^%^CYAN%^.%^RESET%^%^GREEN%^"+
"\n");
	set_items(([
      (({"meadow"})) :
        "The meadow is really quite "+
"lovely and unexpected at this altitude. Tall grasses sway lightly in the "+
"breeze, and the edges are trimmed with colorful, wild flowers. A light mist "+
"covers the ground, giving the entire area a slightly mystical feeling..",
      (({"gates"})) : "They are large and elegant.",
      (({"wall","walls"})) : "The walls are white "+
	  "They have cloud-like etchings drawn into them.",
	  
	  (({"grove"})) : "The trees are ancient, "
"towering high into the sky. As you stare into the shaded cover of the "
"grove, you can't help but feel as if something is staring back at you.",
	   ]));
   set_exits(([ "south" : ROOMS"gate",
    "north" : ROOMS"grove9",   ]));
   set_listen("default","There is a peaceful quiet.");
   set_smell("default",
   "It smells of fresh plants here.");
   set_door("gate",ROOMS"gate","south",0);
   set_locked("gate",1);
   set_door_description("gate","The gate is made of"+
	  " polished iron.  Silver and gold patterns cover it.  "+
	  "white walls connect to the gate leading off into the mist.");
}
void reset(){
object guard;
int i;
::reset();
if(!present("Ashta'Rathai guard")){
 for (i = 0; i < 1+random(4); i++){
    guard =new(MON"guard2");
    guard->move(TO);
    guard ->set_speed(0);
   }
 for (i = 0; i < 1+random(4); i++)  {
    guard = new(MON"guard");
    guard->move(TO);
    guard->set_speed(0);
  }
 }
}
