#include <std.h>
#include "../squires_trial.h"

inherit BASEROOM;

void create(){
  if(!random(3)){
    set_repop(50);
    set_monsters( ({SQUIREMOBS+"minielemental"}), ({random(2) + 2}) );
  }
  ::create();
  set_name("Squire's Trial Room 9");
  set_short("A carved tunnel");
  set_long( 
  
            "It is utterly " + 
            "%^BOLD%^%^BLACK%^dark%^RESET%^%^WHITE%^ here.  " +
            (string) TO->stonedesc() +
            "  The walls turn to the west." +
            "  The hallway splits here, with paths to the west, south, and north." +
            "  There is some %^RESET%^%^RED%^damage %^RESET%^%^WHITE%^to the walls here."
          );
          
                  
  add_item(({"scratch","damage",}),(:TO, "stonedamage":));
  set_search("damage",(:TO, "scratchsearch":));
  set_search("scratches",(:TO, "scratchsearch":));
  set_exits(([
            "north" : SQUIREROOMS+"room8",
            "south" : SQUIREROOMS+"room12",
            "west" : SQUIREROOMS+"room10"
  ]));
}          


