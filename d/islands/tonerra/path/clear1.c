#include <std.h>
#include "/d/islands/tonerra/areadefs.h"
inherit I_JUNGLE;

void create(){
  ::create();
  set_short("A clearing in the jungle");
  set_long(
@VETRI
%^GREEN%^You are in a small clearing in the middle of the 
jungle. Trees surround you on all sides. Small plants
grow around you, the occasional animal tracks are present.
There is a path to the south leading back into the jungle.
VETRI
  );
  set_indoors(0);
  set_light(2);
  set_listen("default","You hear movement in the jungle and wonder if it is the wind.");
  set_exits(([
    "south":PATH+"path43",
  ]));
}
