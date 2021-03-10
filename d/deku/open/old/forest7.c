#include <std.h>

inherit "/d/deku/open/forest42i";

void create() {
    ::create();
    set_exits(([
       "north" : "/d/deku/open/forest8",
       "south" : "/d/deku/open/forest6"
    ] ));
    set_pre_exit_functions(({"south"}),({"GoThroughDoor"}));
    set_pre_exit_functions(({"north"}),({"GoThroughDoor"}));
    set_items(([
    ] ));
}

int GoThroughDoor() {
  int n;
  n = random(10);
  if(!present("bandit")) {
    if( n > 8) {
      write("You are surprised by bandits!");
      say(TPQCN+" is surprised by bandits!");
      new("/d/deku/monster/bandit")->move(TO);
      new("/d/deku/monster/bandit")->move(TO);
      return 0;
    }
  }
  return 1;
}