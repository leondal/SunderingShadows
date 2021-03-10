#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",1);
    set_short("Inside the Tower of Hawk");
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_long(
@KAYLA
%^YELLOW%^Inside the Tower of Hawk%^RESET%^
This large room is roughly 90' square with a large alcove set in 
the middle of each wall.  The floor is of highly polished marble
and the 20' high ceiling is of similar material.  The chamber
is dominated by a spiral, stone staircase leading to the level
above.  Light enters the room through the windows in the alcoves.
KAYLA
    );
     set_smell("default","Dust and ale permeate the walls of this tower.");
    set_exits(([
       "up" : "/d/deku/keep/tower4",
       "down" : "/d/deku/keep/tower2"
    ] ));
    set_pre_exit_functions(({"up"}),({"go_up"}));
    set_items(([
    ] ));
}

void reset() {
  ::reset();
  if(!present("ingmar")) {
    new("/d/deku/keep/monster/ingmar")->move(this_object());
  }
}

int go_up() {
  if(present("ingmar")) {
    write("%^MAGENTA%^Ingmar says:%^RESET%^ You cannot bother the master when he is in his study.");
    write("             You must first defeat me before entering there.");
    return 0;
  }
  return 1;
}

void init() {
  ::init();
  add_action("peer","peer");
}

int peer(string str) {
  if(str == "up" || str == "down" || str == "d" || str == "u") {
    write("Something, perhaps magic, prevents you from peering there.");
    return 1;
  } else {
    return 1;
  }
}
