#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_terrain(STONE_BUILDING);
    set_travel(RUBBLE);
    set_short("Eastern Hallway");
    set_long(
@KAYLA
%^YELLOW%^Eastern Hallway%^RESET%^
The walls of this hallway are dirty and bare, and the floor is
covered with mud.  Several broken chairs and a small table,
only two of its four legs intact, are the only furniture.  A 
pair of double doors in the north wall and a single iron door 
in the east wall are all closed.
KAYLA
    );
    set_exits(([
       "north" : "/d/deku/fortress/hall_din",
       "west" : "/d/deku/fortress/main_hall",
       "east" : "/d/deku/fortress/gallery"
    ] ));
    set_pre_exit_functions(({"east"}),({"go_east"}));
    set_listen("default","You hear disconcerting scuffling sounds in surrounding rooms.");
    set_items(([
       "north door" : "The double doors looks as if they have been hacked.",
	"east door" : "This iron door is about 2 inches thick.  You wonder why!"
    ] ));
}

void reset() {
  ::reset();
  if(!present("fortress guard")) {
    new("/d/deku/fortress/monster/guard")->move(TO);
    new("/d/deku/fortress/monster/guard")->move(TO);
  }
}

int go_east() {
  if(present("fortress guard")) {
    tell_room(environment(this_player()), "The guard blocks the doorway to the east!");
    return 0;
  }
  return 1;
}
