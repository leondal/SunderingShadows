#include <std.h>
inherit ROOM;

int is_virtual() { return 1; }
int is_water() { return 1; }
int is_dockentrance() { return 1; }

void create() {
  set_indoors(1);
  ::create();
  set_light(2);
  set_short("You are in the Desert");
  set_property("no teleport",1);
  set_long(
@OLI
        You are on a the Saakrune Sea.
The coast of the continent known as Atoyatl Tepexitl is to the east.
There is something interesting in the water here.
OLI
  );
  set_exits(([
    "north":"/d/shadow/virtual/49,50.sea",
    "south":"/d/shadow/virtual/51,50.sea",
    "west":"/d/shadow/virtual/50,49.sea",
    "dock":"/d/shadow/virtual/sea/spring.dock"
  ]));
  set_smell("default","You can smell the salty sea air blowing from the west.");
  set_listen("default","You can hear the crashing waves to the east.");
}
