#include <std.h>
#include "../squires_trial.h"

inherit BASEROOM;

void create(){
  if(!random(3)){
    set_repop(50);
    set_monsters( ({SQUIREMOBS+"minielemental"}), ({random(2) + 2}) );
  }
  ::create();
  set_name("Squire's Trial Room 7");
  set_short("A carved tunnel");
  set_long( 
  
            "It is utterly " + 
            "%^BOLD%^%^BLACK%^dark%^RESET%^%^WHITE%^ here.  " +
            //(:TO, "stonedesc":) +
            (string) TO->stonedesc() +
            "  The hallway extends to the east and southwest."
            
          );
          
  set_exits(([
            "east" : SQUIREROOMS+"room6",
            "southwest" : SQUIREROOMS+"room8"
  ]));
}          


