#include <std.h>

inherit VAULT;

void create(){
::create();
	set_name("tunnel");
    set_terrain(BUILT_TUNNEL);
    set_travel(DIRT_ROAD);
	set_short("tunnel passage");
	set_long(
    		"%^RESET%^%^ORANGE%^"+
		"The tunnel is dry and dusty.  The walls are formed of rock and "+
		"dirt, but appear to be stable.  Strange tracks cover the floor, "+
		"they look familiar, but then again something is not quite right "+
		"about them.  The ceiling is low, not more than seven feet from the floor\n"+
		"%^RESET%^"
    	);
	set_property("indoors",1);
	set_property("light",0);
	set_smell("default","The tunnel smells faintly sweet.");
	set_listen("default","You hear faint scratching sounds echoing all around.");
	set_items(([
		({"wall","walls"}) : "The rock and dirt walls look very solid with an "+
			"occasional dotting of a mold or a fungus to break its monotony.\n",
		"floor" : "The dirt floor is marked with unusual tracks.\n",
		({"tracks","track"}) : "The tracks are diagonal grooves in the dirt "+
			"like a snake might make, but much too large for that to be true.\n",
		({"ceiling","roof"}) : "The ceiling is made from stone in this area and "+
			"has some regular markings on it.\n"
        	]));

    	set_exits(([
		"south" : "/d/deku/dark/tunnel1"
    	]));
}
void init() {
  	::init();
  	add_action("search_em","search");
}
int search_em(string str) {
    	if(!str) {
        	tell_object(TP,"Search what?");
        	return 1;
    	}
  	if(str == "ceiling" || str == "roof"){
        	if(member_array("up",TO->query_exits()) != -1) {
        		tell_object(TP,"The door in the ceiling has already been found!");
            	return 1;
            }
     		tell_object(TP,"You look over the ceiling carefully and discover "+
     			"a thin rectangular crevice outlining a trapdoor. \n");
     		tell_room(ETP,""+TPQCN+" discovers a trapdoor in the ceiling.\n",TP);

      	add_exit("/d/deku/dark/pit0","up");
    		("/d/deku/dark/pit0")->add_exit("/d/deku/dark/tunnel0","down");

    	   	("/d/deku/dark/pit0")->set_door("trapdoor","/d/deku/dark/tunnel0","down","dark "+
			"key");
    		("/d/deku/dark/pit0")->set_locked("trapdoor",0,"lock");
     		set_locked("trapdoor",0,"lock");
    		("/d/deku/dark/pit0")->lock_difficulty("trapdoor",10,"lock");
    		("/d/deku/dark/pit0")->set_door_description("trapdoor","The trapdoor "+
    			"is a door that is set into the floor.");
    		("/d/deku/dark/pit0")->set_string("trapdoor","open","You lift the "+
    			"trapdoor and see into a tunnel below you.\n");

    		set_door("trapdoor","/d/deku/dark/pit0","up","dark key");
    		set_door_description("trapdoor","The trapdoor is a door that covers "+
    			"the hole in the ceiling.");
    		set_string("trapdoor","open","You push the trapdoor up to open it.  "+
    			"Dirt, debris and bones rain down on you from the floor of "+
    			"the room above.\n");
     		return 1;
     	}
}