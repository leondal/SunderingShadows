#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",0);
    set_property("indoors",1);
    set_property("no sticks",1);
    set_terrain(BUILT_CAVE);
    set_travel(DIRT_ROAD);
    set_short("Passageway to the Abyss");
    set_long(
@KAYLA
%^YELLOW%^Passageway to the Abyss%^RESET%^
This large cavern is filled with rot and dust.  Bunk beds line the
curve of the rear wall, most of them broken and buckled.  The
footlockers contain only some rusty weapons.  Under the drifts of
dust, the floor is mottled with stains of blood and putrefaction.
KAYLA
    );
    set_exits(([
       "east" : "/d/deku/dark/droom9"
    ] ));
    set_items(([
      "footlockers":"These rotten wooden chests only contain some rusty weapons."
    ] ));
}

void reset() {
  ::reset();
  if(!random(3) && !present("elf")) {
    new("/d/deku/monster/elf")->move(TO);
    new("/d/deku/monster/elf")->move(TO);
    switch(random(5)) {
      case 0:  new("/d/deku/monster/captain")->move(TO);
      case 1..3:  new("/d/deku/monster/elf")->move(TO);
      break;
      case 4:  new("/d/deku/monster/elite")->move(TO);
    }
  }
}
