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
and the 20' high ceiling is of similar material.  Light enters
the room through the windows in the alcoves.  This light is 
reflected from every wall of the room as most of the area is
lined with hundreds of mirrors in every imaginable shape and
size, constructed of countless different materials.
KAYLA
    );
     set_smell("default","Dust and ale permeate the walls of this tower.");
    set_exits(([
       "down" : "/d/deku/keep/tower3"
    ] ));
    set_items(([
       "mirrors":"The highly polished looking glasses gleam in their frames\n"+
                 "of marble, rare woods, wrought iron, brass, silver, and\n"+
                 "even gold."
    ] ));
}

void reset() {
  ::reset();
  if(!present("lord")) {
    new("/d/deku/keep/monster/lord")->move(TO);
  }
}
