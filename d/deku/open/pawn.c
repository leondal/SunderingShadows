//Added random drow or skeleton (people camp here to log on just to get 
//scrolls from Jarrow and then quit without even leaving tower)  
//Also added "no sticks" Styx 7/19/01

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",1);
    set_property("no sticks",1);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_short("Jarrow's Tower");
    set_long(
@KAYLA
Two padded couches face eath other in the middle of this 20' X 40'
rectangular room, and beween them sits an octagonal wooden table.  A
delicate glass globe suspended above the table glows brightly, 
illuminating the entire chamber.  A well-worn armchair with matching
footstool rests in one corner, nestled between a shapely wooden cloak
rack and brass pipe holder.
KAYLA
    );
    set_exits(([
       "south" : "/d/deku/open/entrance"
    ] ));
    set_pre_exit_functions(({"stair"}),({"go_stair"}));
    set_items(([
       "table" : "Atop the wooden table is a finely crafted wooden chess set.",
       "pipe holder" : "The pipe holder is an ash-filled urn secured to a brass tripod.",
       "chess set" : "Jarrow's chess set is carved from wood and is not particularly valuable."
    ] ));
}

void reset() {
   object ob, scroll, scroll2;
  ::reset();
  if(!random(3) && !present("jarrow")) {
   new("/d/deku/monster/jarrow")->move(TO);
  }
  if(!random(4) && !present("elf") && !present("skeleton"))
  switch(random(3)) {
  case 0:  new("/d/deku/monster/skeleton.c")->move(TO);
           break;
  case 1:  new("/d/deku/monster/elf.c")->move(TO);
           break;
  case 2:  new("/d/deku/monster/elite.c")->move(TO);
           break;
  }
}
