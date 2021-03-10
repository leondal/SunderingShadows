//Coded by Diego//

#include <std.h>
#include "../mos.h"
inherit "/std/lab";

void create(){
	object ob;
    	::create();
   	set_short("%^MAGENTA%^Laboratory%^RESET%^");
    	set_long(
    		"%^GREEN%^"+
    		"A large chalkboard fills the front of this large room.  Counters dominate the "+
    		"east and west walls with cupboards above them for storage of various "+
    		"supplies and equipment.  There are half a dozen large tables placed "+
    		"throughout the room each with glass beakers, tubes, vials, burners, and "+
    		"other equipment used in the search for alchemical knowledge.  Four of "+
    		"the tables seem to be in use with on going experiments bubbling "+
    		"unattended.  On the south wall there are shelves that hold more "+
    		"supplies of glassware needed for the experiments.  Many burn scars mar "+
    		"the room leaving you only guessing as to how they came about.  There is "+
    		"a single tapestry hanging on the north wall.\n"+
    		"%^RESET%^"+
    		"Help laboratory will give you further help on the use of this room.\n"
    	);
    	set_property("indoors",1);
    	set_property("light",2);
		set_terrain(STONE_BUILDING);
        set_travel(PAVED_ROAD);
    	set_smell("default","Exotic smells of spices, potions, spell components "+
    		"rush to greet your nose and makes your eyes water.");
    	set_listen("default","Bubbling sounds of brewing potions fill the room.");
    	set_items(([
        	({"counters","counter"}) : "These are table tops attached to the walls "+
        		"with cabinets beneath them and cupboards above them for storage.",
        	({"shelf","shelves"}) : "Shelving dominates the southern wall and the "+
        		"shelves are full of equipment except for the set of shelves in the "+
			"center.\n",
		"tapestry" : "The tapestry seems out of place in this room that has no "+
			"other decorations.  It is full of bright colors depicting no "+
			"scene or person.\n"
     	]));
  	set_search("shelf","The shelf seems loose as though it is not as attached as the "+
		"other shelves, maybe that is why there is no glassware on it.");
  	set_search("shelves","The shelf in the center seems loose as though it is not "+
  		"as attached as the other shelves, maybe that is why there is no "+
  		"glassware on it.");
  	set_search("tapestry","As you search the tapestry you notice, when you lift it "+
  		"away from the wall, that there is a small hole in the wall behind it.  "+
  		"Is the hole caused by some errant experiment of the mages or could it "+
  		"be there to peep into the next room.");
     	set_exits(([
   		"east" : MROOMS+"moslib",
   		"hole" : MROOMS+"mosscry"
 	]));

    	set_door("brown door",MROOMS+"moslib","east","guild earring");
    	set_door_description("brown door","This is a normal "+
		"looking wooden door painted %^RESET%^%^ORANGE%^brown %^RESET%^with a "+
		"simple lock.  There are burn marks all over the door as if there "+
		"has been an intense fire.");
   	set_string("brown door","open","You open the "+
   		"door noiselessly into a room full books and tomes.\n");

  	setOwner("none");
   	setLabId("blades");

  	ob = new("std/bboard");
  	ob->set_name("board");
  	ob->set_id( ({ "board", "chalk board", "laboratory board" }) );
  	ob->set_board_id("lab_board");
  	ob->set("short", "Chalk Board");
 	ob->set("long", "This is a slate board where the mages engaged in experimentation "+
 		"jot down their ideas and work out their formulaes.\n");
  	ob->set_max_posts(10);
  	ob->set_location(MROOMS+"moslab");

    set_invis_exits(({"hole"}));
    set_trap_functions(({"hole"}),({"nogo"}),({"hole"}));

}
void init() {
  	::init();
  	add_action("pull_em","pull");
  	add_action("push_em","push");
  	add_action("peep_em","peep");
}
int push_em(string str) {
    	if(!str) {
        	tell_object(TP,"Push what?");
        	return 1;
    	}
  	if((str == "shelf closed") || (str=="shelves closed")){
      	if(member_array("north",TO->query_exits()) != -1) {
     			tell_object(TP,"You push on the shelf and close the secret door!  \n");
     			tell_room(ETP,""+TPQCN+" pushes on the shelf closing the secret "+
				"door.\n",TP);
     			remove_exit("north");
     			(MROOMS+"mosscry")->remove_exit("south");
            	return 1;
            }
     		tell_object(TP,"Why would you want to push the shelf closed when "+
     			"it is already closed?\n");
    		return 1;
     }
}
int pull_em(string str) {
    	if(!str) {
        	tell_object(TP,"pull what?");
        	return 1;
    	}
  	if((str == "shelf open") || (str=="shelves open")){
     		if(member_array("north",TO->query_exits()) != -1) {
        		tell_object(TP,"The secret door has already been opened to the "+
        			"north!. \n");
            	return 1;
            }
     		tell_object(TP,"You pull on the shelf and the secret door opens to "+
     			"a small darkened room!  \n");
     		tell_room(ETP,""+TPQCN+" pulls on the shelf and the wall "+
			"opens to a small darkened room.\n",TP);
     		add_exit(MROOMS+"mosscry","north");
     		(MROOMS+"mosscry")->add_exit(MROOMS+"moslab","south");
     		return 1;
     }
}
int nogo(){
   	if(avatarp(TP)) return 1;
    	if(interactive(TP)){
    		TP->move(MROOMS+"moslab");
	    	return 1;
    	}
}
int peep_em(string str) {
    	if(!str) {
        	tell_object(TP,"Peep what?");
        	return 1;
    	}
  	if(str == "hole"){
      	tell_object(TP,"You move behind the tapestry and peer through a hole in "+
      		"the wall into room with a mirror.\n");
      	tell_room(ETP,""+TPQCN+"moves behind the tapestry on the north wall "+
      		"making the tapestry look very lumpy.\n",TP);
      	TP->force_me("peer hole 1");
    		return 1;
     }
}

