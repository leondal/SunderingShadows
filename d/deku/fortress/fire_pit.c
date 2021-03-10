#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",5);
    set_property("indoors",1);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_short("Fire Pit");
    set_long(
@KAYLA
%^YELLOW%^Fire Pit%^RESET%^
This room is dominated in the middle by a 10' X 10' fire pit.  Over the
pit is an iron grid.  Every few seconds, you hear a distant explosion,
apparently coming from below.  The explosions are followed by flames
that flick up from the pit, sometimes rising above and through the
iron-grid.
KAYLA
    );
    set_exits(([
       //"down":"/d/deku/fortress/shit",
       "west":"/d/deku/fortress/hallN2"
    ] ));
    set_invis_exits(({"down"}));
    set_pre_exit_functions(({"down"}),({"go_down"}));
    set_smell("default","You smell the hair burning from your skin.");
    set_items(([
       "pit" : "This pit is about 4' deep, maybe somehow you can climb down to investigate."
    ] ));
}

int go_down() {
  write("What!  Climb down the fire pit when there are flames within?");
  return 0;
}

void reset() {
  ::reset();
  if(!present("giant")) {
    new("/d/deku/fortress/monster/fire")->move(TO);
  }
}
