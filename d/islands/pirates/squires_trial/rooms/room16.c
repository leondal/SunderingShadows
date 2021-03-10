#include <std.h>
#include "../squires_trial.h"

inherit BASEROOM;

void create(){
  if(!random(3)){
    set_repop(50);
    set_monsters( ({SQUIREMOBS+"minielemental"}), ({random(2) + 2}) );
  }
  ::create();
  set_name("Squire's Trial Room 16");
  set_short("A carved tunnel");
  set_long( 
            "It is utterly " + 
            "%^BOLD%^%^BLACK%^dark%^RESET%^%^WHITE%^ to the southeast.  " +
            (string) TO->stonedesc() +
            "  Some light filters in from the room to the west, " +
            "it seems as if the tunnel leads into a chamber of some sort." +
            "  The hallway extends to the east and west." 
            
          );
  set_property("light",2);
  set_exits(([
            "west" : SQUIREROOMS+"room17",
            "southeast" : SQUIREROOMS+"room15"
  ]));
}          


