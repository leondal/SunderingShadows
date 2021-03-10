#include <std.h>

inherit "/d/deku/inherits/vexia-lair.c";

void create() {
    ::create();
    set_property("light",1);
    set_short("Ogre's Playroom");
    set_long(
@KAYLA
A large, ten-foot long table occupies most of this foul smelling den, its dented and splintered surface testifying to the brutality of the play these ogres engage in.  The room is lighted by a dozen burning torches that fill the room with a thick, sooty gray smoke making you almost gag from the lack of fresh air.
KAYLA
    );
    set_listen("default", ( :(TO,"ogre_noise"): ));
    set_smell("default","The rank smell from the filthy ogres mixes with the "
      "sooty gray smoke making it difficult to breathe.");

    set_exits(([
       "north" : "/d/deku/open/den",
       "south" : "/d/deku/open/cave_r5",
       "west" : "/d/deku/open/cave_r6"
    ] ));
    set_pre_exit_functions(({"north"}),({"go_north"}));
    set_pre_exit_functions(({"west"}),({"go_west"}));
    set_items(([
      "table":"The 10 ft. long table is crudely made from wooden slats and logs.", 

    ] ));
}

void reset() {
  ::reset();
  if(!present("ogre")) {
    new("/d/deku/monster/ogre1")->move(TO);
    new("/d/deku/monster/ogre1")->move(TO);
    return 1;
  }
}

void ogre_noise(string str) {
   if(present("ogre 2")) 
      return("The noise from the ogres fighting echoes off the walls.");
   if(present("ogre"))
     return("The ogre is making a lot of noise smashing things "
       "on the battered table.");
   return("You hear more commotion to the north.");
}


int go_north() {
   object obj;
   if(present("ogre guard")) {
    write("The ogre stands in your way.");
    write("%^MAGENTA%^The ogre says:%^RESET%^  You cannot pass!");
    say("%^MAGENTA%^The ogre says%^RESET%^:  You cannot pass!");
    return 0;
  }
   else {
    write("You move northward.");
    say(TPQCN+" moves northward.");
    return 1;
   }
}
int go_west(object obj) {
   if(present("ogre guard")) {
    write("The ogre stands in your way.");
    write("%^MAGENTA%^The ogre says:%^RESET%^  You cannot pass!");
      say("%^MAGENTA%^The ogre says%^RESET%^:  You cannot pass!");
    return 0;
  }
   else {
      write("You move westward.");
    say(TPQCN+" moves westward.");
    return 1;
   }
}
