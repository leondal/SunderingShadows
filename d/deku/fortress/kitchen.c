#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",1);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_short("Kitchen and Pantry");
    set_long(
@KAYLA
Two large ovens on the east wall dominate this chamber.  Shelf
areas in the north and south portions are covered by all manner
of kitchen things.  Many birds and large slabs of salted meat
hang from hooks throughout.  
KAYLA
    );
     set_smell("default","The smell of curing meat is strong.");
    set_exits(([
       "west" : "/d/deku/fortress/hall_din",
       "north" : "/d/deku/fortress/storage"
    ] ));
    set_items(([
       "shelfs" : "They are covered with pots, pans, jars, grain, and floor bins and utensils."
    ] ));
}

void reset() {
  ::reset();
  if(!present("servant")) {
    new("/d/deku/fortress/monster/servant")->move(TO);
    new("/d/deku/fortress/monster/servant")->move(TO);
  }
}
