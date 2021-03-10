#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",0);
    set_property("indoors",1);
    set_property("no sticks",1);
    set_terrain(BUILT_CAVE);
    set_travel(DIRT_ROAD);
    set_short("Human Ambassador Office");
    set_long(
@KAYLA
The walls of this room are lined with heads of great and savage beasts.
The heads of gorgons, hell hounds, lions, owlbears and perytons line
the side walls.  Alone on the end wall gleams the sinister head of a
black dragon.  The earthen floor is cold, sending a chill up through
your boots.
KAYLA
    );
     set_smell("default","The air of this dark chamber smells moldy.");
    set_exits(([
       "south" : "/d/deku/dark/group"
    ] ));
    set_items(([
    ] ));
}

void reset() {
  ::reset();
  if(!present("human")) {
    new("/d/deku/monster/human")->move(TO);
  }
}
