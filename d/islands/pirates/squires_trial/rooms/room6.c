#include <std.h>
#include "../squires_trial.h"

inherit BASEROOM;

void create(){
  if(!random(3)){
    set_repop(50);
    set_monsters( ({SQUIREMOBS+"minielemental"}), ({random(2) + 2}) );
  }
  ::create();
  set_name("Squire's Trial Room 6");
  set_short("A carved tunnel");
  set_long( 
  
            "It is utterly " + 
            "%^BOLD%^%^BLACK%^dark%^RESET%^%^WHITE%^ here.  " +
            (string) TO->stonedesc() +
            "  The hallway extends to the west and southeast." +
            "  There is some %^RESET%^%^RED%^damage %^RESET%^%^WHITE%^to " +
            "the walls here."
            
          );
          
  add_item(({"scratch","damage"}),(:TO, "stonedamage":));
  set_search("damage",(:TO, "scratchsearch":));
  set_search("scratches",(:TO, "scratchsearch":));
          
  set_exits(([
            "southeast" : SQUIREROOMS+"room5",
            "west" : SQUIREROOMS+"room7"
  ]));
}          


