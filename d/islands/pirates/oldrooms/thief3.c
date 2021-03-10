#include <std.h>
#include "../piratedefs.h"

inherit ROOM;

// object ob;

void create(){ 
    ::create();
    set_property("indoors",1);
    set_property("light",2);
//   set_property("no teleport",1);
   set_terrain(BUILT_CAVE);
   set_travel(DIRT_ROAD);
    set_short( "Thieves' Guild of Pirate's Cove");

    set_long(
        "%^BOLD%^Thieves' Guild%^RESET%^\n"
       "You have descended into the thieves' guild. "
      "It's dingy and rather unsafe looking. "
      "A rough hewn counter stands here. "
       "There is a notice tacked on the wall. " 
       "To the east is the thieves' store.\n"
      "To the north is the exit."
      "\n"
    );

    set_smell("default","You smell weapon oil and leather.");
    set_listen("default","Its pretty quiet here.");
/* removing non-IC boards that aren't really needed *Styx*  5/10/03

    ob = new("std/bboard");
    ob->set_name("board");
    ob->set_id( ({ "board", "bulletin board", "pirate's cove thieves board","thief board"}) );
    ob->set_board_id("pirate_thief_board");
    ob->set_short("The Pirate's Cove Thieves Guild Board");
     ob->set_long("A musty old tack board sits on the west. "
      "This is the place thieves can make suggestions "
       "and leave messages for one another."
      "\n"
    );
    ob->set_max_posts(20);
    ob->set_location(CAVES"thief3");
*/

    set_items(([
	"notice":"A piece of parchment is tacked here.",
	"counter":"The counter looks worn."
      ]));

    set_exits(([
	"north":CAVES"thief2",
	"east":CAVES"thief4"
      ]));

}
void init(){
    ::init();
    add_action("read","read");
}


int read(string str){
    if (!str) return notify_fail("read what?\n");
    if (str !="notice") return notify_fail("That is not here?\n");

    else{
    tell_object(TP,"You read the notice.");
      tell_room(ETP,""+TPQCN+" reads a notice.",TP);
	write("To all thieves!");
	write("Due to the transient population and the clerical "
      "demands on myself, Guildmaster of the thieves guild, "
	  "I have decided to just say to hell with the one "
	  "time fee idea and just charge higher prices at the "
	  "store.  If ya don't like it don't shop here. "
	  "By the way if you see that dead beat Alden "
	  "kick him in the teeth and kill him. "
	  "Thank-you and Have a nice day.\n"
	  "\n"
	  "Signed Cedwin Hobblefoot."
	);

	return 1;
    }
}
