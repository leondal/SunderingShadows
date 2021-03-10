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
  set_short("Beach on Tonerra");
  set_long(
@DESC
%^ORANGE%^You are standing on the dock on the island of 
Tonerra.  The island appears to be covered with a dense 
jungle and you wonder what could be in there.  A mountain 
rises above the jungle toward the center of the island.
A wooden pier here provides access to boats at sea and 
provides them a place to dock.
DESC
  );
  set_smell("default","You smell the salt of the ocean.");
  set_listen("default","The waves pound against the dock coating you in a fine mist of seaspray.");
  set_exits(([
    "east":"/d/islands/tonerra/beach/beach27.c"
  ] ));
}
