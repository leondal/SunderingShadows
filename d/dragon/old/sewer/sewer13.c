#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    room::create();
    set_property("light",0);
    set_property("indoors",1);
    set_short("Sanctuary Sewers");
    set_long("%^RED%^%^BOLD%^
These are the disgusting sewers under the city of Sanctuary.  They are
filled with many strange fobjects.  The tunnel branches here, it contines
to the east, south and west.  The dark walls are covered with disgusting
slime mold from the many decades of sewage that remain here.
    ");
    set_exits(([
       "east" : "/d/dragon/sewer/sewer12",
        "south" : "/d/dragon/sewer/sewer21",
       "west" : "/d/dragon/sewer/sewer14"
    ] ));
  set_pre_exit_functions(({"south"}),({"go_exit"}));
  set_pre_exit_functions(({"west"}),({"go_exit"}));
    set_items(([
       "sewers":"The disgusting tunnels of waste under Sanctuary."
    ] ));
}

int go_exit() {
  if((TP->query_stats("dexterity")) < random(20)) {
    write("You slip upon something under the sewage, and start sliding down.");
    if(!this_player()->move("/d/dragon/sewer/fall1"))
      environment(this_player())->start_slide();
    return 0;
  }
  return 1;
}

void reset() {
  if(!present("gorger")) {
    new("/d/dragon/mon/gorger")->move(this_object());
  }
}
