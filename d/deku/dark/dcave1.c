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
Unlike the rest of the caverns in this area, this one is almost bone dry.  %^BOLD%^%^BLACK%^Black%^RESET%^, wiry mold grows in large patches all over the floor,
walls, and ceiling of the cave.
KAYLA
    );
    set_exits(([
       "south" : "/d/deku/dark/droom5"
    ] ));
    set_items(([
    ] ));
}

void reset() {
  ::reset();
  if(!random(3) && !present("elf")) {
    new("/d/deku/monster/elf")->move(TO);
    switch(random(5)) {
      case 0:  new("/d/deku/monster/captain")->move(TO);
      case 1..3:  new("/d/deku/monster/elf")->move(TO);
      break;
      case 4:  new("/d/deku/monster/elite")->move(TO);
    }
  }
}
