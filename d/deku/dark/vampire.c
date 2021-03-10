#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_terrain(BUILT_CAVE);
    set_travel(DIRT_ROAD);
    set_property("light",-1);
    set_property("indoors",1);
    set_short("Tomb of Natas");
    set_long(
@KAYLA
The tunnel breaks into the corner of an old hall, obviously constructed
with care in some distant age.  A wide center aisle stretches to the
limits of sight.  A thin, undisturbed coat of dust covers the floor.
Rats have passed over the dust on the floor throughout the cavern, but
none of the tracks approach the tomb, which is supported by an iron base.
KAYLA
    );
    set_exits(([
       "west" : "/d/deku/dark/mobat"
    ] ));
    set_items(([
    ] ));
}

void reset() {
  ::reset();
  if(!present("vampire") && !random(2)) {
    new("/d/deku/monster/vampire")->move(TO);
  }
}
