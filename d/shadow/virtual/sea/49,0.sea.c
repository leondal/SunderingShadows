// sea description for Rilynath dock
#include <std.h>
inherit ROOM;


int is_virtual() { return 1; }
int is_water() { return 1; }
int is_dockentrance() { return 1; }
void create() {
set_indoors(1);

    ::create();

    set_light(2);

    set_short("Saakrune Sea");

   set_property("no teleport",1);
set_long(
@TSERA
     %^BOLD%^%^WHITE%^You are on the Saakrune Sea.%^RESET%^
      There is a large dock here.

TSERA
   );
 set_exits(([
                "north":"/d/shadow/virtual/48,0.sea",
                "south":"/d/shadow/virtual/50,0.sea",
                "east":"/d/shadow/virtual/49,1.sea",
        "dock":"/d/shadow/virtual/sea/rilynath.dock",
                ]));
        set_smell("default","You can smell the scent of fresh forest blowing from the west.");
        set_listen("default","You can hear the crashing waves to the east.");
}
