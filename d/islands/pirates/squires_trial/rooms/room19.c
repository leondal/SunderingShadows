#include <std.h>
#include "../squires_trial.h"

inherit CHASMBASEROOM;

void create(){
  ::create();
  set_name("Squire's Trial Room 19");
  set_short("A carved tunnel");
  set_long( 
  
            "%^RESET%^%^BLUE%^" + 
            "The rock has changed here.  It is a brittle, sharp and " +
            "broken corridor.  A small stream flows through, probably " +
            "the reason for the vast crevasse.  Broken chips of stone " +
            "have collected over centuries and form a solid, but somewhat " +
            "crunchy bed.  This stone path leads to the north, and the " +
            "west wall looks sturdy enough to climb."
          );
          
  set_exits(([
            "north" : SQUIREROOMS+"room20"
  ]));
  set_climb_exits(([
            "climb":({"room18",15,50,100})
  ]));
}          


