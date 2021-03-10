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
You are at a twisted and confusing intersection within the Kobold
forest.  The creatures who dwell within the forest must not be 
accustomed to strangers, for they hide with the shadows.  All 
around you, fog blankets the forest like a flowing dark gray cloak.
To the south you can see through the fog that the path twists in
a boggled fashion.  To the west lies the ongoing path, and to the 
far east lies an intersection.
KAYLA
    );
     set_listen("default","Peculiar, the forest is deadly quiet.");
    set_exits(([
       "west" : "/d/deku/new/new8",
        "south" : "/d/deku/new/new9",
       "east" : "/d/deku/new/new6"
    ] ));
    set_pre_exit_functions(({"west"}),({"go_west"}));
    set_pre_exit_functions(({"south"}),({"go_south"}));
    set_items(([
       "trees" : "The large trees to waver in the blowing breeze."
    ] ));
}

int go_west() {
  int n;
  n = random(10);
  if ( n > 8) {
    if(!present("kobold")) {
    write("A Kobold patrol surprises you.");
    say("A Kobold patrol jumps in front of "+this_player()->query_cap_name()+".");
    new("/d/deku/monster/kobold")->move(this_object());
    new("/d/deku/monster/kobold")->move(this_object());
    }
    return 0;
  }
  return 1;
}

int go_south() {
  int n;
  n = random(10);
  if (n > 8) {
    if(!present("goblin")) {
      write("A Goblin patrol surprises you.");
      say("A Goblin patrol jumps in front of you.");
      new("/d/deku/monster/goblin")->move(this_object());
      new("/d/deku/monster/goblin")->move(this_object());
    }
    return 0;
  }
  return 1;
}
