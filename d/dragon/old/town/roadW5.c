#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    room::create();
    set_property("light",2);
    set_property("indoors",0);
    set_short("Town of Sanctuary");
    set_long("%^CYAN%^%^BOLD%^
This is the main street through the town of %^GREEN%^Sanctuary%^CYAN%^.  Buildings
seem to line the street toward the east, and west is the everlasting
denseness of the forest.  This place looks like something has ravaged
the land.  The street is bare except for the few strange people walking
from one building to another.  The gates are closed and appear to have
been rusted closed perhaps decades ago.
    ");
    set_exits(([
//        "exit" : "/d/dragon/forest/wforest01",
       "east" : "/d/dragon/town/roadW4"
    ] ));
    set_items(([
    ] ));
    set_pre_exit_functions(({"exit"}),({"GoThroughDoor"}));
}

void reset() {
  ::reset();
  if(!present("sfighter")) {
    new("/d/dragon/mon/guard")->move(this_object());
  }
  if(!present("smage")) {
    new("/d/dragon/mon/mage")->move(this_object());
  }
}

int GoThroughDoor() {
  write("The gates leading out of Sanctury are closed.");
  return 0;
}
