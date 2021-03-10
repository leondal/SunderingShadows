#include <std.h>
#include "../squires_trial.h"

inherit BASEROOM;

void create(){
  if(!random(3)){
    set_repop(50);
    set_monsters( ({SQUIREMOBS+"minielemental"}), ({random(2) + 2}) );
  }
  ::create();
  set_name("Squire's Trial Room 13");
  set_short("A carved tunnel");
  set_long( 
  
            "It is utterly " + 
            "%^BOLD%^%^BLACK%^dark%^RESET%^%^WHITE%^ here.  " +
            (string) TO->stonedesc() +
            "  The hallway extends to the east and northwest\n" +
            "%^BOLD%^%^WHITE%^" +
            "To the northwest is a shattered mass of metal.  It appears a " +
            "gate stood here, but something wrenched it out of " +
            "the walls, reducing it to scrap!"
            
          );
          
  add_item(({"metal","gate"}),"%^BOLD%^%^WHITE%^This metal is twisted and " +
                    "smashed, discarded next to the wall.%^RESET%^%^WHITE%^");
          
  set_exits(([
            "east" : SQUIREROOMS+"room14",
            "northwest" : SQUIREROOMS+"room12"
  ]));
}          


