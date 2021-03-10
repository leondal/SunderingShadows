//updated by Circe 11/24/04 with description and ideas by Lusell
//some code adapted from the Shadow jail
// converted to the new inheritable jail by *Styx* 9/2004

/* To change the waystations for the guards to finding the jail if needed...
* eval return "daemon/destinations_d.c"->query_waystations("/d/dagger/tonovi/town/jail1")
* eval return "/daemon/destinations_d.c"->clear_waystations("/d/dagger/tonovi/town/jail1")
* eval return "/daemon/destinations_d.c"->generate_waystations("/d/dagger/tonovi/town/jail1", 6, 3)  seemed to cover it decently without a horribly huge mapping
*/


#include <std.h>
#include <daemons.h>
#include "/d/dagger/tonovi/town/short.h"

#define CELL "/d/dagger/tonovi/town/cell"

inherit "/std/jail_main";

void create(){
    ::create();
    set_jail_location("Tonovi");
    set_cell(CELL);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",1);
    set_property("light",2);
    set_name("Tonovi City Jail");
    set_short("Tonovi City Jail");
    set_property("no sticks",1);
/*
    set_long(
      "You are in the main room of the jail of Tonovi.  From here you can see many cells, most empty but some contain the thieves and killers of the city, awaiting judgement or punishment."
    );
Original desc
*/
    set_long("%^ORANGE%^This is the City of Tonovi jail.  "+
       "A beautiful %^BOLD%^%^BLACK%^ebony desk %^RESET%^%^ORANGE%^"+
       "is in the center of the room, with a mahogany chair "+
       "slightly pulled out from behind it.  The office is "+
       "immaculate, no signs of dust or dirt anywhere, and "+
       "everything is in its place.  A large %^YELLOW%^book "+
       "%^RESET%^%^ORANGE%^sits atop the well-ordered "+
       "%^BOLD%^%^BLACK%^desk%^RESET%^%^ORANGE%^, open to a "+
       "page not quite filled with names yet.  Gazing beyond "+
       "the desk into a narrow hallway, you can see some "+
       "%^BOLD%^%^BLACK%^prison cells %^RESET%^%^ORANGE%^"+
       "containing people being held for their punishment.  A "+
       "wooden door leads back into the cells, a %^BOLD%^"+
       "%^BLACK%^metal grate %^RESET%^%^ORANGE%^fitted into "+
       "the upper part.  "+
       "There is a %^YELLOW%^wooden sign %^RESET%^%^ORANGE%^"+
       "upon the wall with script burned into it.\n");
    set_smell("default", "It smells deodorized, as if something is "
	"masking less pleasant smells.");
    set_listen("default", "The sounds from the bazaar and the thick "
	"wood of the door to the cell mask most of the moans and "
	"complaints from the prisoners.");
    set_items(([
       "desk" : "%^BOLD%^%^BLACK%^Beautiful and very "+
          "black... this desk is a sight to behold.  It is "+
          "large and sits in the center of the room.  "+
          "There are seven drawers in it, three on each "+
          "side and one in the middle.  The top of the desk "+
          "is arranged neatly, everything in its place.  Under "+
          "a book, you can just make out what appears to be "+
          "the city seal burned ever so slightly into the top "+
          "of the desk.%^RESET%^",
       ({"chair","mahogany chair"}) : "%^ORANGE%^This dark, "+
          "mahogany chair appears to clash with the decor in "+
          "the room.  But as it sits behind the desk empty, "+
          "it begins to blend in, complimenting it.  The "+
          "scrollwork on the chair depicts scenes involving "+
          "dragons.  The %^MAGENTA%^cushion %^ORANGE%^is made "+
          "from a lavender velvet and looks very comfortable to "+
          "sit in.%^RESET%^",
       ({"book","law book"}) : "%^YELLOW%^This book is "+
          "bound in bright yellow silk.  The pages are "+
          "crisp and look to be fresh.  The book is currently "+
          "open to a page that is not quite filled up with "+
          "names.%^RESET%^\n(<help jail> for commands)",
       ({"sign","wooden sign"}) : "%^YELLOW%^Tonovi City Jail%^RESET%^\n"
          "The sign directs you to the various lists posted on the "
	  "walls.  (%^BOLD%^< help jail >%^RESET%^ for the commands "
	  "to see the lists and other commands available)",
       ({"grate","metal grate"}) : "The metal grate is fitted "+
          "in the upper part of the door.  "+
          "You could probably peer through the grate to see who "+
          "is in the cell."
    ]));
    set_exits(([
      "south" : RPATH "bazaar1",
      "cell" : CELL,
      "grate" : CELL
    ]));
    set_invis_exits(({"grate"}));
   add_pre_exit_function("grate", "GoThroughDoor");
   set_door("cell door",CELL,"cell","Tonovi jail key","lock");
   set_open("cell door",0);
   set_locked("cell door", 1, "lock");
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

int GoThroughDoor() {
   if(query_verb() == "grate") {  
     write("You won't fit through there, silly.");
     return 0;
   }
// need this to allow normal GoThroughDoor for the regular door exits
   return ::GoThroughDoor();
}

void init() {
   ::init();
   add_action("peer_out", "peer");
}

void reset() {
   ::reset();
   if(!present("waynon"))
      new(MPATH"jail_guard")->move(TO);
   if(!present("tonovi guard"))
      new("/d/dagger/tonovi/guards/guard")->move(TO);
}

int peer_out(string str) {
   if(!str) {
      tell_object(TP,"Peer where?");
      return 1;
   }
   if(str == "grate" || str == "through grate" || str == "cell" || str == "into cell"){
      	tell_object(TP,"You step up to the door and peer into the cell.\n");
      	tell_room(ETP,TPQCN+" steps up to the cell door and peers
inside.\n",TP);
      	tell_room(CELL,"You hear footsteps and catch "
            "a glimpse of movement through the grate in the door.\n",TP);
	write("/d/dagger/tonovi/town/cell"->query_long());
      	TP->force_me("peer grate 1");
    		return 1;
   }
}
