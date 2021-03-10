//added a step of moving the stone after searching - 
//skipping the search will skip a chance for the ring
//made the ROP random, not always just there for the first person after reboot, etc.
//put one randomly on the bandit leader also

#include <std.h>
#include "/d/deku/inherits/deku.h"
inherit "/d/deku/inherits/hauntings_inh.c";

int searched;
int moved;


void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",1);
    set_terrain(WOOD_BUILDING);
    set_travel(DECAYED_FLOOR);
    set_short("Haunted House");
    set_long(
@KAYLA
Two stuffed armchairs stand near the fireplace of this room.  The
covers of both have been torn or cut and the stuffing has been
pulled out, however, the wooden frames are still intact.  The 
pieces of a broken table lie on the floor near the north wall.
KAYLA
    );
  set_smell("default","The smell of rot and decay is all around.");
  set_exits(([
    "west" : HH_ROOMS+"hall2"
  ] ));
  set_items(([
   "fireplace" : "It shows no sign of recent use for fires, and is too narrow to climb.",
   "stone":"The stone in the fireplace seems loose.  Perhaps you can move it."
  ] ));
		set_search("default","The fireplace draws your attention.");
		set_search("fireplace",(:this_object(),"fireplace_search":));
		searched = 0;
  moved = 0;
  hauntings();
}

void init() {
  ::init();
  add_action("move_stone","move");
}

int search (string str) {
  if(present("skeleton guard")) {
    write("The skeleton forbids you to look anywhere!");
    return 1;
  }
  if(searched) {
    write("You notice a stone that looks like it's recently fallen loose.");
    return 1;
  }
  write("You search the fireplace and notice a loose stone inside.\n");
  searched = 1;
  if(!present("shadow") && !random(2)) {
    write("Also within you awaken a couple of %^BOLD%^%^BLACK%^shadows.%^RESET%^");
    say(TPQCN+" awakens a couple of %^BOLD%^%^BLACK%^shadows%^RESET%^.");
    new("/d/deku/monster/shadow")->move(TO);
    new("/d/deku/monster/shadow")->move(TO);
  }
  return 1;
}

int move_stone (string str) {
  if(!str) {
    write("Move what?");
    return 1;
  }
  if(present("skeleton guard")) {
    write("The skeleton forbids you to get closer to the fireplace!");
    return 1;
  }
  if(str != "stone") {
    write("You try to move the "+str+" and find nothing.");
    return 1;
  }
  if(present("shadow")) {
    write("The shadows won't let you get close enough to the stone.");
    return 1;
  } 
  if(moved) {
    write("It looks like someone has searched and moved the stone recently.");
    return 1;
  }
  if(!searched) {
    write("Did you bother to search the fireplace first?");
    moved = 1;
    return 1;
  }
  write("The stone shifts easily to reveal a hidden cache.");
  moved = 1;
  if(!random(3) && searched) {
    write("You manage to loosen the stone and out drops a ring of Protection.");
    say(TPQCN+" searches the fireplace and finds a ring from within.");
    new("/d/deku/armours/ring_p")->move(TO);
    write("More %^BOLD%^%^BLACK%^shadows%^RESET%^ come from within the fireplace!");
    say(TPQCN+" awakens even more %^BOLD%^%^BLACK%^shadows%^RESET%^.");
    new("/d/deku/monster/shadow")->move(TO);
    new("/d/deku/monster/shadow")->move(TO);
    if(!random(2)) new("/d/deku/monster/shadow")->move(TO);
    return 1;
  } else {
    write("The cache seems to be empty this time.");
  }
  return 1;
}


void reset() {
  ::reset();
  if(!present("skeleton")) {
    new("/d/deku/monster/skeleton")->move(TO);
    new("/d/deku/monster/skeleton")->move(TO);
  }
  if(!random(3)) moved = 0;
  if(!random(2)) searched = 0;
}
