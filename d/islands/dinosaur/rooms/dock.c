#include <std.h>

inherit DOCK;

int is_virtual() { return 1; }
int is_water() { return 1; }
int is_dock() { return 1; }

void create(){
    ::create();
   set_terrain(SHORE);
   set_travel(DIRT_ROAD);
    set_indoors(1);
    set_light(2);
    set_short("Tropical Docks");
    set_long(
      "You are standing on an ancient run down pier that seems to serve as the docks for this strange tropical island.  From here, you can see the cliffs rising above the island to the north, and the cliffs falling into the ocean to the south, but its the vast jungle before you that amazes you."
    );
    set_exits( ([
      "west" : "/d/islands/dinosaur/rooms/jung1.c",
    ]) );
    set_listen("default", "You can hear strange noises in the jungle.");

}
