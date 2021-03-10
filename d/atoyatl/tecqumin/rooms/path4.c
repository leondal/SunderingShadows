#include <std.h>
#include <move.h>
#include "../tecqumin.h"

inherit PATH_BASE;


void create() {
  ::create(); 
  set_exits(([ "south" : ROOMS + "path5"]));
  set_items( ([ ({"statue", "statues", "debris"}) : "The statues have tumbled across"
    +" the pathway, and block any progress to the north. They are covered in%^GREEN%^"
    +" moss%^RESET%^ and %^ORANGE%^lichen%^RESET%^ on them, and have clearly been the"
    +" way they are for a long time." ]) );
}

long_desc(){
  string desc;
  desc =  ::long_desc();
  desc += "To the north, the path is blocked by the debris of a number of"
   +" large ornamental statues which have clearly been toppled at some"
   +" time in the past.";
  return desc;
}