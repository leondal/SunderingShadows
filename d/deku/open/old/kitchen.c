#include <std.h>

inherit "/d/deku/inherits/vexia-lair";

void create() {
    ::create();
    set_property("light",1);
    set_short("Vexia's Kitchen");
    set_long( "Light but also smoke in this room come from a crude fire pit in "
       "the northwest corner of the chamber.  Orcs are poking around the room's "
       "three, bulky tables which hold pieces of bloody meat, knives, and "
       "long cleavers.");
    set_smell("default","You gag from the nauseating smell of rancid meat.");
    set_exits(([
       "north" : "/d/deku/open/cave_r7",
       "south" : "/d/deku/open/cave_r6"
    ] ));
    set_pre_exit_functions(({"north"}),({"go_north"}));
    set_items(([
       "table" : "Covered in blood stains and carving marks, this worn table "
         "has seen better days.  Cleavers and knives hang from hooks on the "
         "edge of the table for easy reach.",
       ({"knives", "cleavers"}) : "Used to cut and prepare the meat for "
         "cooking, they don't look to have any real value otherwise.",
       "meat" : "The meat appears to have come from some large beast.  It "
         "is very greasy and looks like it has been left out for days.  The "
         "smell from it is nauseating.",  
       ({"pit", "fire"}) : "This crude fire pit serves to cook the meat.  "
         "Some of the meat is skewered and roasting on a large iron "
         "spit which has been propped over the smokey wood and flames."
    ] ));
}

void reset() {
  ::reset();
  if(!present("orcguard")) {
    new("/d/deku/monster/orc")->move(TO);
    new("/d/deku/monster/orc")->move(TO);
    new("/d/deku/monster/orc")->move(TO);
    return 1;
  }
}

int go_north() {
  if (present("orcguard")) {
    write("The orc blocks your way northward.");
    return 0;
  }
  return 1;
}
