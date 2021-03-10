#include <std.h>
#include "../juran.h"

inherit "/std/rquestroom.c";
  object perm_corpse;

create(){
  	object ob;

  	::create();
  	set_terrain(CITY);
  	set_travel(PAVED_ROAD);
	remove_property("light");
  	set_property("light", -2);
  	set_property("indoors", 1);
  	set_short("Juran Adventurers' Hall");
  	set_long("%^BOLD%^This is the Juran adventurers' hall.%^RESET%^\n"+
		"Power hungry mercenaries meet here to discuss their "+
		"adventures and to check the list of items with rewards "+
		"for %^BOLD%^lower %^RESET%^levels.  \n%^BOLD%^%^BLUE%^There "+
		"is a bulletin board here and a small sign."
	);
  	set_quest_daemon("/daemon/quests_mid");

  	set_smell("default","You smell the odor of bodies that have exerted "+
  		"themselves, but have not yet washed.");
  	set_listen("default","You hear the clatter of gutteral languages.");
  	set_exits(([
          "southeast" : JROOMS+"r42"
      ]));
  	set_items( ([ 
     		"mercenaries" : "They appear to be blood curdling tales.",
     		"sign" : "Once you have found greater fame and fortune you should seek "
        		"out the other board with the higher level challenges."
   	]) );
  	ob = new("std/bboard");
  	ob->set_name("Juran quest board");
  	ob->set_short("Juran Adventurers' board");
  	ob->set_id( ({ "board", "bulletin board", "reality board" }) );
  	ob->set_board_id("jquests_board");
  	ob->set_long("An old piece of tanned and bleached skin hangs here "+
  		"where mercenaries who pass through Juran post information on "+
  		"the realities they have discovered.\n");
  	ob->set_max_posts(50);
  	ob->set_queue();
  	ob->set_location(JROOMS+"quest_room");
}

void init(){
  	::init();
  	add_action("quest_info","quest");
}

int quest_info(){
  	string *quests;
  	int how_many;

  	quests = TP->query_quests();
  	how_many = sizeof(quests);
  	while(how_many--){
    		write("%^GREEN%^Quest %^WHITE%^#%^YELLOW%^ "+(how_many + 1)+" %^BLUE%^ 			"+quests[how_many]);
  	}
  	return 1;
}
int remove_message(string str) {
  	write("Permission administratively denied.");
 	return 1;
}

/*
void reset() {
  object corpseob;
   if (!objectp(corpseob=present("drowfcorpse",TO))) {
     corpseob = new("/std/Object");
     corpseob->set_name("drow corpse");
     corpseob->set_short("%^MAGENTA%^A drow corpse rotting on a pike");
    corpseob->set_long(read_file("/realms/garrett/maddesc"));
    corpseob->set_id( ({"drowfcorpse","drow corpse", "female drow corpse","corpse on a pike" }) );
  corpseob->add_id("corpse");
   corpseob->move(TO);
  perm_corpse = corpseob;
  }
   if(!present("pike"))
new("/realms/dinji/coolstuff/piked_arkhdel.c")->move(TO);
}

*/
int loose_object(object ob) {
  if (perm_corpse == ob) return 0;
  return 1;
}
