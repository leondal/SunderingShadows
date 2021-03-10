//guard house based off shadow one
/* trying eval for making stations for guards so 
they can return crims to jail
eval return
"/daemon/destinations_d.c"->query_waystations("/d/islands/elf/guard1")
* // eval return
"/daemon/destinations_d.c"->clear_waystations("/d/islands/elf/guard1")
* // eval return
"/daemon/destinations_d.c"->generate_waystations("/d/islands/elf/guard1", 5, 3)
* eval return
"/daemon/destinations_d.c"->generate_waystations("/d/islands/elf/guard1", 5, 4)
*/
#include <std.h>
#include "elf.h"
#define GROVE "/d/islands/elf/grove2"
#define CELL "/d/islands/elf/cell"

inherit "/std/jail_main.c";

void create(){
   ::create();
   set_jail_location("Ashta'Rathai");
   set_cell(CELL);
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_name("Ashta'Rathai jail");
   set_short("The Ashta'Rathai jail tree");
   set_long("%^BOLD%^%^GREEN%^Jailer's Office \n\n%^RESET%^"+
      "%^GREEN%^This is a rather large tree with several"+
   " cages hanging from the branches where criminals are checked"+
   " in before being caged while their fate is decided.  "+
   "There is a simple desk in one corner and several chairs"+
   " in the room.  The tree sprawls up around fifty feet into"+
   " the air with many little resting places built onto it. "+
   " There is a list posted on the base of the tree. "+
   " Guards often gather here to meet."   );
   set_items(([
      "grate" : "Perhaps the guard won't mind if you peer through the "
          "grate to see who is in the cage.",
	  (({"cage","cell"})) : "This is a bronze cage with a "+
	  "grate on it to peer through",
	  "list" : "Type <list> to see how to use this room.",
   ]));
   set_listen("default","You can hear a chill wind blow.");
   set_smell("default","It smells of plants and water.");
   set_exits(([
      "northeast" : GROVE,
      "cage" : CELL,
	  "up" : ROOMS"office",
      "grate" : CELL,//invis exit
   ]));
   add_invis_exit("grate");
   add_pre_exit_function("grate", "GoThroughDoor");
   set_door("cage door",CELL,"cage","Ashta'Rathai jail key","lock");
   set_open("cage door",0);
   set_locked("cage door", 1, "lock");
   lock_difficulty("cage door",-90, "lock");
   set_lock_description("cage door", "lock",
      "This lock is sandwiched between two very heavy "
      "metal plates to prevent tampering.  The mechanism appears to be "
      "not only complex but require a very sturdy key to get the pieces "
      "to even move.");
  set_door_description("cell door", "This is a brass grate with a lock on it.  "+
   "It is placed at the bottom of the cage.");
   set_string("cage door","open","The cell door creaks loudly as it "
      "swings open.");
   set_string("cage door","close","An ominous thud echoes off the cage "
      "as the door latches shut solidly.");
}

void init() {
   ::init();
   add_action("peer_out", "peer");
}

void reset() {
   ::reset();
   if(!present("jailer"))
      new(MON"jailer")->move(TO);
   if(!present("mage guard"))
      new(MON"guard")->move(TO);
   if(!present("mirror warrior"))
      new(MON"guard2")->move(TO);
}

int GoThroughDoor() {
   if(query_verb() == "grate") {  
     write("You won't fit through there silly.");
     return 0;
   }
// need this to allow normal GoThroughDoor for the regular door exits
   return ::GoThroughDoor();
}

int peer_out(string str) {
   if(!str) {
      tell_object(TP,"Peer where?");
      return 1;
   }
   if(str == "cell" || str == "through grate" || str == "cage"){
        tell_object(TP,"You step up to the cage and peer into the cell.\n");
        tell_room(ETP,TPQCN+
		 " steps up to the cage and peers inside.\n",TP);
        tell_room(CELL,"You hear footsteps and catch "
            "a glimpse of movement through the grate in the door.\n",TP);
        TP->force_me("peer grate 1");
                return 1;
   }
}
