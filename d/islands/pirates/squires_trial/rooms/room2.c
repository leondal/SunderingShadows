#include <std.h>
#include "../squires_trial.h"

inherit BASEROOM;

void create(){
  ::create();
  set_name("Squire's Trial Room 2");
  set_short("A carved tunnel");
  set_long( 
  
            "You are in a narrow hallway which leads out of the octagonal " + 
            "chamber toward complete " +
            "%^BOLD%^%^BLACK%^darkness%^RESET%^%^WHITE%^.  " +
            (string) TO->stonedesc() +
            "  The hallway extends to the west and southeast."
          );
  set_property("light",2);
  set_exits(([
            "southeast" : SQUIREROOMS+"room1",
            "west" : SQUIREROOMS+"room3"
  ]));
}          


