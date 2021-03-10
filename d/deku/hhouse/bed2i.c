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
    set_short("%^CYAN%^Haunted House Bedroom%^RESET%^");
    set_long(
@KAYLA
Once perhaps a fine guest bedroom, this is now decayed like the 
rest of the house.  Rubbish is scattered around.  There is some
evidence of rodent infestation and some webs hang torpid in the
corners of the room.  A four-poster bed, once a grand piece of
furniture, is against the wall opposite the fireplace.  Its
woodwork is worm-ridden and the curtains which once screened the
bed are torn and stained.
KAYLA
    );
    set_listen("default","The floors creak and you hear eerie moans.");
    set_smell("default","The smell of rot and decay is all around.");
    set_exits(([ "north" : HH_ROOMS+"hall8" ] ));
    set_items(([
       "bed" : "There is no bed linen, but the carcass of the bed is relatively intact."
    ] ));
    hauntings();
}

void reset() {
   ::reset();
   if(!random(2))
   if(!present("skeleton") && !present("ghost")) { 
     switch(random(10)) {
       case 0:  new("/d/deku/monster/skeleton")->move(TO);
       case 1:  new("/d/deku/monster/skeleton")->move(TO);
       case 2:  new("/d/deku/monster/skeleton")->move(TO);       break;
       case 3:  new("/d/deku/monster/gghost")->move(TO);
       case 4:  new("/d/deku/monster/skeleton")->move(TO);
       case 5:  new("/d/deku/monster/skeleton")->move(TO);
       case 6:  new("/d/deku/monster/gghost")->move(TO);         break;
       case 7:  new("/d/deku/monster/skeleton")->move(TO);
       case 8:  new("/d/deku/monster/shadow")->move(TO);
       case 9:  new("/d/deku/monster/gghost")->move(TO);         break;
    }
  }
}
