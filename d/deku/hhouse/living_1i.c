#include <std.h>
#include "/d/deku/inherits/deku.h"

inherit "/d/deku/inherits/hauntings_inh.c";

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_terrain(WOOD_BUILDING);
    set_travel(DECAYED_FLOOR);
    set_name("Haunted House");
    set_short("%^CYAN%^Haunted House%^RESET%^");
    set_long(
@KAYLA
This room is empty like most of the rest within the house.  The
only matter of interest is the quantity of fallen plaster on the
floor.  A broken window in the north wall opens onto a small paved
patio which is now cracked and over-run with weeds.  The interior 
of this room is just as run down as the rest.
KAYLA
    );
    set_smell("default","The smell of decay is all around.");
    set_listen("default","The floors creak and other eerie sounds abound.");
    set_exits(([ "east" : HH_ROOMS+"hall1i"  ] ));
    set_items(([
    ] ));
    hauntings();
}

void reset() {
   ::reset();
   if(!random(2))
   if(!present("skeleton") && !present("ghost")) { 
     switch(random(5)) {
       case 0:  new("/d/deku/monster/gghost")->move(TO);
       case 1:  new("/d/deku/monster/skeleton")->move(TO); 
       case 2:  new("/d/deku/monster/gghost")->move(TO);         break;  
       case 3:  new("/d/deku/monster/gghost")->move(TO);
       case 4:  new("/d/deku/monster/shadow")->move(TO);         break;
    }
  }
}

