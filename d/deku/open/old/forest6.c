#include <std.h>

inherit "/d/deku/open/forest42i";

void create() {
    ::create();
    set_long(
@KAYLA
%^ORANGE%^You are at a twisted and confusing intersection.  To the north 
the path continues into darkness.  To the east and west it goes 
deeper into the forest.  To the south the path moves through the 
forest toward the sea.  The trees and underbrush within the forest 
are all tinted with a blackish color.  All around you fog blankets 
the forest like a dark gray cloak and you are getting a bad feeling 
about the forest.
KAYLA
    );
    set_exits(([
      "north" : "/d/deku/open/forest7",
      "west" : "/d/deku/open/forest61",
      "east" : "/d/deku/open/clear2",
      "south" : "/d/deku/open/forest5"
    ] ));
    set_pre_exit_functions(({"west"}),({"go_west"}));
    set_pre_exit_functions(({"east"}),({"go_east"}));
    set_items(([
    ] ));
}

int go_east() {
  int n;
  n = random(10);
  if(!present("bandit")) {
    if (n > 8) {
      write("You are surprised by bandits!");
      say(TPQCN+" is surprised by bandits!");
      new("/d/deku/monster/bandit")->move(TO);
      new("/d/deku/monster/bandit")->move(TO);
      return 0;
    }
  }
  return 1;
}

int go_west() {
  int n;
  n = random(10);
  if(!present("bandit")) {
    if (n > 8) {
      write("You are surprised by bandits!");
      say(TPQCN+" is surprised by bandits!");
      new("/d/deku/monster/bandit")->move(TO);
      new("/d/deku/monster/bandit")->move(TO);
      return 0;
    }
  }
  return 1;
}
