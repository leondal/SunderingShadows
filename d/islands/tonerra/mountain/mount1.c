#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

// Ankheg traps are bugged. Just disabling the mountain inherit, and replacing with ROOM.
// inherit "/d/islands/tonerra/mountain.c";
inherit ROOM;

void create(){
//   ::create();
   set_short("Side of the volcano");
   set_long(
@DESC
%^CYAN%^You are at the base of a large volcano. There are
few plants in the area, although the volcano has been dormant
long enough to allow some small bushes to grow. The slope is
steep, but there seems to be a well-worn path. You can see a
large building about halfway up the side of the mountain.
DESC
   );
   set_light(2);
   set_indoors(0);
   set_listen("default","The slight breeze stirs the small plants.");
   set_smell("default","The land has a charred smell about it.");
   set_exits(([
      "down":PATH+"path85",
      "up":MOUNTAIN+"mount2"
   ]));
}
