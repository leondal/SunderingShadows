#include <std.h>

inherit "/d/deku/inherits/vexia-lair.c";

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",0);
    set_short("Vexia's air shaft");
    set_long(
@GRAYHAWK
This room is dusty, but the air here is fresher than in other areas of 
the caves.  Dim sunlight from the world above filters down through a 
1 ft. wide shaft in the ceiling.
GRAYHAWK
    );
    set_smell("default", "The fresh air is a welcome break from the odors "
      "in the rest of the cave.");
    set_exits(([ "west" : "/d/deku/open/well"  ] ));
    set_items(([
       "shaft" : "The shaft is used to keep a slight current of air moving through the caves."
    ] ));
}

void reset() {
 ::reset();
  if(!present("air") && !random(2)) {
    new("/d/deku/monster/air")->move(TO);
    return 1;
  }
}
