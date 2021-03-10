#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    room::create();
   set_terrain(LIGHT_FOREST);
   set_travel(DIRT_ROAD);
    set_property("light",1);
    set_property("indoors",0);
   set_short("Kobold Forest");
    set_long(
@KAYLA
You are within the realm of Kobold Caverns.  The forest seems to endlessly
extend to the west and far to the east is the entrance gate to the Kobold 
Caverns.  Through the trees northwest you see a strange looking cabin.
The light also seems to become dimmer as you journey westward.
KAYLA
    );
    set_listen("default","You hear birds singing within the trees.");
    set_exits(([
       "west" : "/d/deku/new/new4",
       "east" : "/d/deku/new/new002"
    ] ));
    set_pre_exit_functions(({"west"}),({"go_west"}));
    set_items(([
    ] ));
}

int go_west() {
  int n;
  n = random(10);
  if (n > 8) {
    write("A goblin surprises you from the side.");
    say("A goblin jumps from the bushes, and attacks "+this_player()->query_cap_name()+".");
    new("/d/deku/monster/goblin")->move(this_object());
    return 0;
  }
  if(present("sgoblin")) {
    write("The goblin stands in your path!");
    return 0;
  }
  return 1;
}
