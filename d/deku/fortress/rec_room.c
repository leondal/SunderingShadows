#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",1);
    set_terrain(STONE_BUILDING);
    set_travel(RUBBLE);
    set_short("Reception Room");
    set_long(
@KAYLA
%^YELLOW%^Reception Room%^RESET%^
This room has the appearance of former luxury now fallen into decay.
The carpet is slashed and spotted.  Many fine pieces of furniture
are stewn across the dirty floor.  Some fancy chairs have been
splintered, apparently so their legs can be used as firewood.
KAYLA
    );
     set_smell("default","A faint smell of death and decay.");
    set_exits(([
       "south" : "/d/deku/fortress/hallW2"
    ] ));
    set_items(([
    ] ));
}

void reset() {
  ::reset();
  if(!present("giant")) {
    new("/d/deku/fortress/monster/hill")->move(TO);
  }
}
