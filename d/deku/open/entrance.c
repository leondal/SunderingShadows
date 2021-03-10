//Added random drow or skeleton (people camp here to log on just to get 
//scrolls from Jarrow and then quit without even leaving tower)  
//Also added "no sticks" Styx 7/19/01

#include <std.h>

inherit ROOM;

void create() {
    room::create();
    set_property("light",2);
    set_property("indoors",1);
    set_property("no sticks",1);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_short("Jarrow's Tower");
    set_long(
@KAYLA
Beyond the iron-bound oak door is an unlit, 20' long corridor with 
another oaken door set into the far wall.  Neatly burned into the surface
of the door is a peculiar sigil shaped vaguely like a "J".  In the
ceiling above the door are several small murder holes.
KAYLA
    );
    set_exits(([
       "out" : "/d/deku/forest/dforest27-8",
       "north" : "/d/deku/open/pawn"
    ] ));
    set_items(([
       "door" : "The door is made of sturdy iron-bound oak.",
       "sigil" : "This sigil on the northern door is Jarrow's insignia."
    ] ));
}

void reset() {
  ::reset();
  if(!random(5) && !present("drow") && !present("skeleton"))
  switch(random(3)) {
  case 0:  new("/d/deku/monster/skeleton.c")->move(TO);
           break;
  case 1:  new("/d/deku/monster/skeleton.c")->move(TO);
           break;
  case 2:  new("/d/deku/monster/elf.c")->move(TO);
           break;
  }
}
