#include <std.h>

inherit "/std/pier";

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",0);
    set_terrain(SHORE);
    set_travel(GAME_TRACK);
    set_short("Shadowlord Forest");
    set_long(
@KAYLA
You are along the river's edge.  There is a path here that leads
towards the north.  The river rushes past you at a very rapid
pace.  This looks like a good place to fish, because there is a 
pool of fairly clear, still water here and you can see fish 
swimming in and out of it.
KAYLA
    );
     set_listen("default","You hear the river rushing past.");
     set_smell("default","The water smells fresh and reasonably clean.");
    set_exits(([
       "up" : "/d/deku/open/pass1",
       "swim": "/d/deku/open/river2.c"
    ] ));
    set_invis_exits(({"swim"}));
    set_pre_exit_functions(({"up"}),({"go_up"}));
    set_items(([
      ({"river", "water", "pool"}): "The bottom of the pool looks sandy and "
        "the water calm enough to perhaps swim.",
    ] ));
    set_max_fishing(5);
    set_chance(12);
    set_max_catch(23);
    set_fish((["catfish":5, "mackeral":7, "salmon":10]));
}

int go_up() {
  write("You start taking the long journey upward.\n");
  return 1;
}
