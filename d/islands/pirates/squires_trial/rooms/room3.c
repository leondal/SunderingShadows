#include <std.h>
#include "../squires_trial.h"

inherit BASEROOM;

void create(){
  ::create();
  set_name("Squire's Trial Room 3");
  set_short("A carved tunnel");
  set_long( 
  
            "It is utterly " + 
            "%^BOLD%^%^BLACK%^dark%^RESET%^%^WHITE%^ here.  " +
            (string) TO->stonedesc() +
            "  The walls continue east and west.  " +
            "To the west however the floor stops suddenly, a jagged edge " +
            "into a deep pit.  The bottom is not visible.  Strangely, a " +
            "stone pathway about two feet wide spans the chasm from the " +
            "middle of the walkway, swallowed by the black ahead."
          );
          

  add_item(({"walkway","pathway","bridge","stone pathway"}),"The " +
          "stone bridge crosses the chasm, about two feet wide, and " +
          "although it appears it could hold some weight, it might be best" +
          " to cross quickly."
  );
  
  add_item(({"chasm","pit"}),"The deep, dark chasm extends down into pure" +
                      " blackness.  The walls on either side seem to slope " +
                      "so that climbing down would be nearly impossible."
  );
  
  set_search("chasm","As you approach to search, you dislodge a " +
            "rock, but can not hear it strike the bottom of the pit.");
          
  set_search("pit","As you approach to search, you dislodge a " +
            "rock, but can not hear it strike the bottom of the pit.");
          
  set_exits(([
            "east" : SQUIREROOMS+"room2",
            "west" : SQUIREROOMS+"room4"
  ]));
}          


