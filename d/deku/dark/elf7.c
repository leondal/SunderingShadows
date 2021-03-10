#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",0);
    set_property("indoors",1);
    set_property("no sticks",1);
    set_terrain(BUILT_TUNNEL);
    set_travel(DIRT_ROAD);
    set_short("Gateway to the Abyss");
    set_long(
@KAYLA
You have entered the core of darkness, the gateway to the Abyss,
where nightmarish figures gather.  Expect the unexpected, for death
is all around.  The room was once finely furnished, but dust and
decay now dominates the room.
KAYLA
    );
    set_listen("default","These rooms are deathly silent.");
    set_smell("default", "The vile smell of rot penetrates your mortal soul.");
    set_exits(([
       "west" : "/d/deku/dark/room5",
       "east" : "/d/deku/dark/elf8"
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
