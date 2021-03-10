#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    room::create();
    set_property("light",0);
    set_property("indoors",1);
    set_short("Sanctuary's Storage");
    set_long("%^BOLD%^%^BLUE%^
The gigantic building is a wasteland of bones and broken wood.  Dozens
of barrels and crates are stacked at the far end of the building.
Wrecked barrels, broken crates, thousands of bones, rusted weapons,
and other large pieces of trash are heaped in stark drifts.
    ");
    set_exits(([
       "east" : "/d/dragon/town/roadS1"
    ] ));
    set_items(([
    ] ));
  set_smell("default","The reek of death and decay is overwhelming within this room.");
}

void reset() {
  ::reset();
  if(!present("barrel")) {
    new("/d/dragon/obj/misc/barrel")->move(this_object());
  }
}
