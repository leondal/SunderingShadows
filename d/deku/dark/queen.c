#include <std.h>

object ob;

inherit ROOM;

void create() {
    ::create();
    set_property("light",0);
    set_property("indoors",1);
    set_terrain(BUILT_CAVE);
    set_travel(DIRT_ROAD);
    set_short("Queen's Chamber");
    set_long(
@KAYLA
The north side of this circular chamber is dominated by a large
chair sitting atop a dais.  Two large jewels are set at the ends
of each armrest: a ruby to the west side and an emerald to the east.
Each of these gems is the size of a man's fist.  The chair itself
is made from fine hardwood and elaborately decorated with silver
filigree.  The rest of the chamber is bare except for six unlit
oil lamps fixed to the walls.
KAYLA
    );
    set_exits(([
       "south" : "/d/deku/dark/elite"
    ] ));
    set_items(([
   "ruby" : "This ruby looks like it can be worth a lot.",
   "emerald" : "This emerald looks like it can be worth a lot."
    ] ));
}
  
void reset() {
  ::reset();
  if(!present("queen") && !random(2))
    new("/d/deku/monster/queen")->move(TO);
  if(!present("guard")){
    new("/d/deku/monster/elf")->move(TO);
    new("/d/deku/monster/elf")->move(TO);
  }
}

