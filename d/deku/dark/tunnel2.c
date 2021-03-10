#include <std.h>

inherit VAULT;

void create(){
::create();
    set_terrain(BUILT_TUNNEL);
    set_travel(DIRT_ROAD);
	set_name("tunnel");
	set_short("tunnel passage");
	set_long(
    		"%^RESET%^%^ORANGE%^"+
		"The tunnel is dry and dusty.  The walls are formed of rock and "+
		"dirt, but appear to be stable.  Strange tracks cover the floor, "+
		"they look familiar, but then again something is not quite right "+
		"about them.  Loose dirt and small rocks litter the floor.\n"+
		"%^RESET%^"
    	);
	set_property("indoors",1);
	set_property("light",0);
	set_smell("default","The tunnel smells cloyingly sweet.");
	set_listen("default","You hear scratching and clicking sounds echoing "+
		"all around.");
	set_items(([
		({"wall","walls"}) : "The rock and dirt walls look very solid with an "+
			"occasional dotting of a mold or a fungus to break its monotony.\n",
		"floor" : "The dirt floor is marked with unusual tracks.\n",
		({"tracks","track"}) : "The tracks are diagonal grooves in the dirt "+
			"like a snake might make, but much too large for that to be true.\n",
		"ceiling" : "The ceiling is made from dirt and rocks and appears to be "+
			"stable in this area.\n",
		({"loose dirt","dirt","small rocks","rocks"}) : "There is more loose "+
			"dirt and small rocks in this part of the tunnel than the "+
			"previous rooms.  There does not appear to have been any collapse "+
			"in this area to account for the extra rubble.\n"
        	]));
	set_search(({"loose dirt","dirt","small rocks","rocks"}),"You look closely at "+
		"the areas where the dirt and rocks have accumulated and notice that "+
		"there is a no natural explanation of there being more in this room "+
		"than any other.\n");
	set_search(({"wall","walls"}),"A search of the walls shows that they are "+
		"different from the other walls of the tunnel.  The walls look the "+
		"same from a distance, but upon close examination you find that the "+
		"walls have many small circular depressions that look like little doors.\n");
	set_search("floor","The floor is smooth and level, except for the loose stones "+
		"and loose dirt.  Upon close examination you can see that there are many "+
		"little round depressions that look like little doors.\n");
    	set_exits(([
		"southeast" : "/d/deku/dark/tunnel3",
		"northeast" : "/d/deku/dark/tunnel1"
    	]));
	set_trap_functions(
		({"northeast","southeast"}),
		({"spear_em","spear_em"}),
		({"northeast","southeast"})
	);
}

int spear_em(){
	int i, j;
 object *inven;
	inven = all_living(TO);
 inven -= ({TP});
	j = sizeof(inven);

	tell_object(TP,"As you move through the room you feel a stone in the floor "+
		"give way and then hear a click.\n");
	TP->force_me("emote gulps");
	tell_room(TO,"%^BOLD%^%^RED%^Several small holes appear in the floor and walls.\n");
	tell_room(TO,"%^BOLD%^%^RED%^Several spears thrust out of the floor and "+
		"walls suddenly!");
	for(i=0;i<j;i++) {
  if(!objectp(inven[i])) continue;
  if(!inven[i]->query_stats("dexterity")>random(25)){
  	tell_object(inven[i],"%^BOLD%^%^RED%^The rusty iron headed spears "+
  	"slice wickedly into your flesh!");
 	 inven[i]->do_damage("torso",random(20)+10);
   }
  else {
  	tell_object(inven[i],"%^RED%^You manage to avoid the worst of the "+
  	"spears, but are unable to avoid them all.");
  	inven[i]->do_damage("torso",random(15)+5);
  }
  inven[i]->add_attacker(TO);
  inven[i]->continue_attack();
  if (objectp(inven[i])) {
   inven[i]->remove_attacker(TO); 
  }
 }
 
 if(!TP->query_stats("dexterity")>random(25)){
 	tell_object(TP,"%^RED%^The rusty iron headed spears slice wickedly into your "+
 	"flesh and block your passage onward!");
 	TP->do_damage("torso",random(30)+10);
 	TP->add_attacker(TO);
 	TP->continue_attack();
  if(objectp(TP)) {
 	 TP->remove_attacker(TO);
  }
  return 1;
 }
 
 tell_object(TP,"%^BOLD%^%^RED%^You avoid most of the spears, but are unable "+
 	"to avoid them all as you move to the next room.");
 TP->do_damage("torso",random(15)+10);
 TP->add_attacker(TO);
 TP->continue_attack(); 
 if(objectp(TP)) {
  TP->remove_attacker(TO); 
 }
 return 0;
}
