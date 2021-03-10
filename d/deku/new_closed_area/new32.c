#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    room::create();
   set_terrain(HEAVY_FOREST);
   set_travel(FOOT_PATH);
    set_property("light",1);
    set_property("indoors",0);
    set_short("Kobold Forest");
    set_long(
@KAYLA
You are at a dead end somewhere in the dense part of the Kobold
Forest.  All around you, fog blankets the forest like a flowing
dark cloak.  The trees here seem to stare into your inner soul.
The only exit is toward the east.
KAYLA
    );
      set_listen("default","Peculiar, the forest is deadly quiet.");
    set_exits(([
       "west" : "/d/deku/new/new33",
       "east" : "/d/deku/new/new31"
    ] ));
    set_invis_exits(({"west"}));
    set_pre_exit_functions(({"west"}),({"go_west"}));
    set_items(([
    "trees":"You notice that toward the west, there is some spacing between the trees."
    ] ));
}

void reset() {
  ::reset();
  if(!present("wolf")) {
    new("/d/deku/monster/wolf")->move(this_object());
    new("/d/deku/monster/wolf")->move(this_object());
  }
}

int go_west() {
  if(present("wolf")) {
    write("The wolf stands in your way.");
    return 0;
  }
  write("You manage to squeeze through the large oaks.");
  write("It seems that you have entered a marshland.");
  return 1;
}
