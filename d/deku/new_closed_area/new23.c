#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    room::create();
   set_terrain(MEADOWLANDS);
   set_travel(FOOT_PATH);
    set_property("light",1);
    set_property("indoors",0);
    set_short("Kobold Forest");
    set_long(
@KAYLA
You stumble upon a clearing within the dense Kobold Forest. All
around you, fog blankets the forest like a flowing dark cloak.
There is a large firepit in the center of the clearing.  The path
ends here, but there is a side passage towards the west.
KAYLA
    );
      set_listen("default","Peculiar, the forest is deadly quiet.");
    set_exits(([
       "west" : "/d/deku/new/new24",
       "north" : "/d/deku/new/new22"
    ] ));
    set_items(([
       "firepit" : "The firepit is still warm as if someone or something has been here."
    ] ));
}

void init() {
  ::init();
  do_random_encounters(({"/d/deku/monster/goblin"}),90,6);
}

void reset() {
  ::reset();
  if(!present("goblin")) {
    new("/d/deku/monster/goblin")->move(this_object());
    new("/d/deku/monster/goblin")->move(this_object());
  }
  if(!present("captain")) {
    new("/d/deku/monster/goblin_cap")->move(this_object());
  }
}
