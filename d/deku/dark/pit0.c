#include <std.h>

inherit VAULT;

void set_rope(int rope);

int rope_present;

int FLAG;

void create(){
::create();
	set_name("dark pit");
	set_short("Dark pit");
    set_terrain(BUILT_CAVE);
    set_travel(RUBBLE);
	set_long(
    		"%^RESET%^%^RED%^"+
		"The pit is dark and the smell here is terrible.  The floor is "+
		"littered with piles of debris and sharp stones.  Old bones from animals "+
		"that became trapped in this hole litter the floor.  With luck, tools, "+
		"and skill you should be able to climb out of here before you starve "+
		"to death.\n"+
		"%^RESET%^"
    	);
	set_property("indoors",1);
	set_property("light",0);
	set_smell("default","This hole smells like something died and rotted here.");
	set_listen("default","You hear only the sounds you make echoed off the walls.");
	set_items(([
      	({"molds","fungi","mold","fungus"}) : "Various colors of molds and fungi "+
      		"cling to the walls, floor and ceiling.\n",
		({"wall","walls"}) : "The rock walls look very solid with an occasional "+
			"dotting of a mold or a fungus to break its monotony.\n",
		"floor" : "The floor is covered with debris and what appears to be "+
			"bones, but the center of the floor is irregular.\n",
		({"stones","sharp stones","bones","debris"}) : "The stones on the floor, along "+
			"with the bones, make for a very uncomfortable surface to land on.",
		({"piles","pile"}) : "Some of the piles seem to be from animals that "+
			"could not find their way out and at least one seems to be rotted "+
			"leather and other gear from an unfortunate adventurer.\n"
        	]));
	FLAG = 0;
 
        set_climb_exits((["climb":({"/d/deku/dark/room7",20,6,100})]));
    	set_fall_desc("%^BOLD%^%^RED%^You fall back into the pit tumbling into the "+
		"darkness until you come to a sudden and painful stop at the "+
		"bottom!%^RESET%^\n");

    	set_search("floor","The floor is covered with debris and what appears to be "+
    		"bones.  In the center of the floor you see that the debris is raised "+
    		"in a rectangular pattern like it was covering a trapdoor or "+
    		"something.  Maybe you can uncover it?\n");
    	set_search(({"piles","pile"}),"Some of the piles seem to be from animals that "+
			"could not find their way out and at least one seems to be rotted "+
			"leather and other gear from an unfortunate adventurer.  Maybe if "+
			"you dig around in them you might find some thing of use.\n");
}
void init() {
  	::init();
  	add_action("dig_em","dig");
  	add_action("uncover_em","uncover");
}
int dig_em(string str) {
    	int stuff;
    	if(!str) {
        	tell_object(TP,"Dig what?");
        	return 1;
    	}
   	if(FLAG == 0) {
        	FLAG = 1;
    		if(str == "pile" || str == "piles"){
    			tell_object(TP,"You dig around in the rotted pile of leather and "+
    				"find some items that are still useful!  \n");
    			tell_room(ETO,""+TPQCN+" searches the pile of rotted leather and "+
    				"finds something.\n");
    			new("/d/common/obj/misc/climb_tool")->move(TO);
    			stuff = (random(5));
        		if(stuff == 1)new("/d/common/obj/sheath/jeweled_lsheath")->move(TO);
        		else if(stuff == 2)new("/d/common/obj/sheath/jeweled_lstaff")->move(TO);
        		else if(stuff == 3)new("/d/common/obj/sheath/jeweled_mholster")->move(TO);
        		else if(stuff == 4)new("/d/common/obj/sheath/jeweled_msheath")->move(TO);
        		else new("/d/common/obj/sheath/jeweled_ssheath")->move(TO);
      	return 1;
  		}
	}else {
        	tell_object(TP,"There is nothing left of value in the piles.");
        	return 1;
    	}
}
int uncover_em(string str) {
    	if(!str) {
        	tell_object(TP,"Uncover what?");
        	return 1;
    	}
  	if(str == "trapdoor" || str == "trap door" || str == "door"){
        	if(member_array("down",TO->query_exits()) != -1) {
        		tell_object(TP,"The door has already been uncovered!");
            	return 1;
            }
     		tell_object(TP,"You move the debris, bones, and dirt away to find "+
     			"a trapdoor in the floor of this pit. \n");
     		tell_room(ETP,""+TPQCN+" removes the debris from the center of the "+
     			"floor revealing a trapdoor.\n",TP);

     		add_exit("/d/deku/dark/tunnel0","down");
		("/d/deku/dark/tunnel0")->add_exit("/d/deku/dark/pit0","up");
		
    		set_door("trapdoor","/d/deku/dark/tunnel0","down","dark key");
    		set_locked("trapdoor",0,"lock");
     		("/d/deku/dark/tunnel0")->set_locked("trapdoor",0,"lock");
    		lock_difficulty("trapdoor",10,"lock");
    		set_door_description("trapdoor","The trapdoor is a door that is set "+
    			"into the floor.");
    		set_string("trapdoor","open","You lift the trapdoor and see into a "+
    			"tunnel below you.\n");

    		("/d/deku/dark/tunnel0")->set_door("trapdoor","/d/deku/dark/pit0","up","dark "+
			"key");
    		("/d/deku/dark/tunnel0")->set_door_description("trapdoor","The trapdoor is "+
    			"a door that covers the hole in the ceiling.");
    		("/d/deku/dark/tunnel0")->set_string("trapdoor","open","You push the "+
    			"trapdoor up to open it.  Dirt, debris and bones rain down on "+
    			"you from the floor of the room above.\n");
     return 1;
     }
}
