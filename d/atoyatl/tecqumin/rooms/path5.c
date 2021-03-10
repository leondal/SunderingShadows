#include <std.h>
#include <move.h>
#include "../tecqumin.h"

inherit PATH_BASE;


void create() {
  ::create(); 
  set_exits(([ "north" : ROOMS + "path4", "south": ROOMS + "path6"]));
  set_items( ([ ({"statue", "statues", "debris"}) : "The statues have tumbled across"
    +" the pathway, and block any progress to the north. They are covered in%^GREEN%^"
    +" moss%^RESET%^ and %^ORANGE%^lichen%^RESET%^ on them, and have clearly been the"
    +" way they are for a long time." ]) );
}

