#include <std.h>
#include <objects.h>

inherit DOCK;

int is_virtual() { return 1; }
int is_water() { return 1; }
int is_dock() { return 1; }

void create() {
  ::create();
  set_property("light",3);
   set_property("no teleport",1);
  set_property("indoors",0);
  set_terrain(BARREN);
  set_travel(DECAYED_FLOOR);
    set_short("Tropical Docks");
  set_long(
      "You are standing on an ancient run down pier that seems to serve as the docks for this strange tropical island.  From here, you can see the cliffs rising above the island to the north, and the cliffs falling into the ocean to the south, but its the vast jungle before you that amazes you."
  );
  set_smell("default","You smell the salt of the ocean.");
    set_listen("default", "You can hear strange crashing noises coming from the jungle on the island.");
  set_exits(([
      "southwest" : "/d/islands/dinosaur/rooms/jung1",
  ] ));
}
