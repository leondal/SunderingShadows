#include <std.h>
#include "../squires_trial.h"

inherit BASEROOM;

void create(){
  if(!random(3)){
    set_repop(50);
    set_monsters( ({SQUIREMOBS+"minielemental"}), ({random(2) + 2}) );
  }
  ::create();
  set_name("Squire's Trial Room 18");
  set_short("A carved tunnel");
  set_long( 
            "It is utterly " + 
            "%^BOLD%^%^BLACK%^dark%^RESET%^%^WHITE%^ here.  " +
            (string) TO->stonedesc() +
            "  The hallway extends to the southwest.  The wall to the east " +
            "is broken here, opening into the side of a chasm."
          );
          
  set_search("default","The broken wall leads into a chasm.  It looks " +
             "like you could climb down if you wished.");
  
  set_search("wall","The broken wall leads into a chasm.  It looks " +
             "like you could climb down if you wished.");
          
  add_item(
        ({"wall","hole","chasm"}),"The hole in the wall here seems to be " +
                "natural, caused by a natural weakness in the stone.  A " +
                "chasm opens up behind the hole.");
          
  set_exits(([
            "southwest" : SQUIREROOMS+"room15"
  ]));
  set_climb_exits(([
            "descend":({SQUIREROOMS+"room19",15,50,100})
  ]));
}          


