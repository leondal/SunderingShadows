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
  set_short("Fall Island");
  set_long("You are standing on the dock of Fall island.");
  set_smell("default","You smell the salty air of the ocean.");
  set_listen("default","The waves pound against the shore, coating you in a fine mist of seaspray.");
}
