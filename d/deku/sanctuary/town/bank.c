#include <std.h>
#include "../dragon.h"

inherit BTOWN;

void create() {
   ::create();
   set_light(0);
   set_indoors(1);
   set_short("Ruined bank");
   set_long(
      "%^BOLD%^%^BLACK%^This was the only bank in the town of %^RED%^Sanctuary%^BLACK%^. It was one"+
      " of the many banks connected to the network. Now the structure has been near"+
      " destroyed as some horrible force as swept through the town."+  
      " There is a counter, or what remains of one, on the north wall."+
      " This building has been severly and completely ravaged."+
      " There is nothing left untouched here by whatever ruined this town."
   );
   set_items(([ 
      "bank" : "This is a huge hollowed out building.",
      "counter" : "A dead body hangs over the edge of the counter.",
      "body" : "This is the rotting corpse of what you guess to be the bank teller."
   ]));
   set_exits(([ 
      "west":TOWN+"roadSW2" 
   ]));
}
