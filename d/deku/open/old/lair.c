#include <std.h>

inherit "/d/deku/inherits/vexia-lair.c";

void create() {
    ::create();
    set_short("Smilodon's Lair");
    set_long(
@KAYLA
This spacious cave seems rather small, partly because of the numerous gnawed upon and %^YELLOW%^yellowed bones %^RESET%^that totally cover the ground.  They have been completely licked clean and lay in broken bits, the marrow sucked from within.  The great cat that makes this her lair must be bored or hungry to have cleaned every scrap of edible matter from the bones.
KAYLA
    );
    set_exits(([ "north" : "/d/deku/open/cave_r5" ] ));
    set_items(([
       "bones" : "Some of the bones are human or humanoid and nothing of value."
    ] ));
}

void reset() {
  ::reset();
  if(!present("cat")) {
    new("/d/deku/monster/smilodon")->move(TO);
  }
}
