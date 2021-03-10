// by Styx - 8/2005

#include <std.h>
#define OUT "/d/darkwood/tabor/room/greene2"
#define CELL "/d/darkwood/tabor/room/jail_cell"
#define GALLOWS "/d/darkwood/tabor/room/gallows"

inherit "/std/jail_main.c";

void create(){
   ::create();
   set_jail_location("Tabor");
   set_cell("/d/darkwood/tabor/room/jail_cell");
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_name("Tabor Gaol");
   set_short("Tabor's Gaol");
   set_long("%^BOLD%^Tabor's Gaol%^RESET%^\n"+
   "You are standing inside Tabor's Gaol, just east of here is Greene"+
   " street and you have the urge to leave this place and get back out"+
   " into the open air.  The building is incredibly plain and ugly"+
   " looking, with iron bars covering the windows, and several cells"+
   " that are full of filthy prisoners.  There is a guard's desk to"+
   " one side of the room and a large sign near some lists on the wall.\n"
   "There is a book on the desk with a list of names "
   "scratched in it. <help jail>"
   );
   set_items(([
      "grate" : "Perhaps the guard won't mind if you peer through the "
          "grate to see who is in the cell.",
      "desk" : "There is a guard's desk off to one side of the room with"+
   	" a well-used %^BOLD%^<list>%^RESET%^ on it.",
      ({"sign", "lists", "list" }) : "%^YELLOW%^Tabor City Jail%^RESET%^\n"
          "The sign directs you to the various lists posted on the "
	  "walls.  (%^BOLD%^< help jail >%^RESET%^ for the commands "
	  "to see the lists and other commands available)",
   ]));
   set_exits(([
      "east" : OUT,
      "cell" : CELL,
      "grate" : CELL,
      "south" : GALLOWS,
   ]));
   add_invis_exit("grate");
   add_pre_exit_function("grate", "GoThroughDoor");
   set_door("cell door",CELL,"cell","Tabor jail key","lock");
   set_open("cell door",0);
   set_locked("cell door", 1, "lock");
//   CELL->set_locked("cell door",1);  // I think this is the recursion problem
   lock_difficulty("cell door",-90, "lock");
   set_lock_description("cell door", "lock",
      "This lock is sandwiched between two very heavy "
      "metal plates to prevent tampering.  The mechanism appears to be "
      "not only complex but require a very sturdy key to get the pieces "
      "to even move.");
   set_door_description("cell door", "This is a door made of three inch "
      "thick oaken boards.  It has a section cut out and replaced with a "
      "grate of inch diameter iron bars so that some air can still get to "
      "the prisoners.");
   set_string("cell door","open","The cell door creaks loudly as it "
      "swings open.");
   set_string("cell door","close","An ominous thud echoes off the walls "
      "as the heavy cell door slams shut solidly.");
}

void reset() {
   ::reset();
   if(!present("guard"))
	new("/d/darkwood/tabor/mon/guard")->move(TO);
   if(!present("jailer"))
	new("/d/darkwood/tabor/mon/Tjailer")->move(TO);
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
   if(str == "grate" || str == "through grate"){
      	tell_object(TP,"You step up to the door and peer into the cell.\n");
      	tell_room(ETP,TPQCN+" steps up to the cell door and peers
inside.\n",TP);
      	tell_room(CELL,"You hear footsteps and catch "
            "a glimpse of movement through the grate in the door.\n",TP);
      	TP->force_me("peer grate 1");
    		return 1;
   }
}
