#include <std.h>
inherit WATER;
 
void create() {
  ::create();
  set_properties( ([ "light" : 2, "indoors" : 1, "no teleport" : 1 ]) );
  set_terrain(DEEP_WATER);
  set_travel(FRESH_BLAZE);
  set_short("%^ORANGE%^River under the bridge.");
  set_long("%^ORANGE%^You have landed in the river below the bridge.  You  "
    "just dropped a total of over 50 ft. and the fall carries you well under "
    "water.  The water rushes by at a rapid pace and is obviously quite deep.  "
    "Somehow you did survive the fall but you're being carried away by the "
    "current.  Perhaps you can make it to the bank if you swim.");
  set_exits((["swim":"/d/deku/open/bank1"]));
  set_listen("default","All sounds are from the rushing water all around.");
  set_invis_exits(({"swim"}));
  set_pre_exit_functions(({"swim"}),({"go_swim"}));
}

int go_swim() {
    write("Your lungs ache as you struggle to the surface and swim for the shore.\n");
  return 1;
}
