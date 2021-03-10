#include <std.h>

int open;
inherit "/d/deku/inherits/vexia-lair.c";

void create() {
    ::create();
    set_short("Vexia's Laboratory");
    set_long(
@KAYLA
You have entered a large room containing a 20 ft. long bench covered with all kinds of alchemist equipment.  Several beakers, some filled with multicolored powders but others empty, are surrounded by various parts of animals and gnarled limbs of nightmarish creatures.  Against the north wall is another workbench covered with similar objects, including several bottles of odd-colored liquids and the pickled innards of unknown creatures.
KAYLA
    );
    set_smell("default","Various pungent odors fill the air.");
    set_exits(([
       "west" : "/d/deku/open/guard"
    ] ));
    set_items(([
       "bottles":"You notice some of the bottles may have special liquids.",
       "innards" : "You recognize a cow's tongue, rabbit's ear, a faerie's wing, and collection of human eyes.",
       "workbench" : "The workbench has bottles scattered all over it.",
    ] ));
  open = 0;
}


void reset() {
  ::reset();
    if(!present("cora")) {
      new("/d/deku/monster/alch")->move(TO);
    }
    if(!present("ogre")) {
      new("/d/deku/monster/ogre2")->move(TO);
      new("/d/deku/monster/ogre2")->move(TO);
    }
  open = 0;
}

void init() {
  ::init();
  add_action("search","search");
}

int search(string str) {
   object bottle, bottle1, bottle2, obj;
  if(present("cora") || present("ogre zombie")) {
    write("The room's occupants aren't about to let you search!");
    return 1;
  }
  if(!str) {
    write("Search what?");
    return 1;
  }
  if(str != "bottles" && str != "workbench" && str != "bottle") {
    write("You cannot search those.");
    return 1;
  }
  if(open) {
    write("You believe that someone has beaten you to the treasure.");
    return 1;
  }
  write("You remove some bottles from the shelves.");
  tell_room(ETP, TPQCN+" removes some bottles from the shelves.", TP);
  bottle = new("/d/common/obj/potion/heal");
  bottle->move(TP);
  bottle1 = new("/d/common/obj/potion/poison");
  bottle1->move(TP);
  if(!random(2)) {
    "/d/common/daemon/randstuff_d.c"->find_stuff(TO, "component", random(10)+10);
    tell_room(ETP, "Something else falls from the shelves.");
  }
  open = 1;
  return 1;
}
