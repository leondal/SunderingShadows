#include <std.h>
#include "../squires_trial.h"

inherit BASEROOM;

int spawnelemental;
void create(){
  ::create();
  set_name("Squire's Trial Room 17");
  set_short("A circular chamber");
  set_property("light",4);
  set_long(
            (string) TO->stonedesc() +
            "  This chamber is almost a perfect circle, with the exception of" +
            " the area where the hallway enters to the east.  About seven or" +
            " eight feet from the floor, all the way around the room is a " +
            "protrusion which forms a ledge.  Atop the ledge, a ring of " +
            "%^BOLD%^%^YELLOW%^da%^RED%^n%^YELLOW%^ci%^RED%^ng " +
            "f%^YELLOW%^la%^RED%^me%^YELLOW%^s%^RESET%^%^WHITE%^" +
            " cast the whole room in a flickering glow.  Apart from the " +
            "lighting, the area seems plain, as if the focus of attention " +
            "should not be the room itself."
  );
  
  add_item(({"flame","flames"}),"The flames dance continually " +
            "around the entire ledge, providing well distributed lighting.");
  
  spawnelemental = 0;        
  set_exits(([
            "east" : SQUIREROOMS+"room16"
  ]));
}          

void reset(){
  ::reset();
  if(!present("animated armor"))
		new(SQUIREMOBS+"livingarmor")->move(TO);
}

int set_spawn_elemental(){
  spawnelemental = 1;
  return 1;
}

int get_spawn_elemental(){
  return spawnelemental;
}

int reset_spawn_elemental(){
  spawnelemental = 0;
  return 1;
}
