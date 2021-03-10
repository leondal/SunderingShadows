//wroad1.c

#include <std.h>

inherit "/d/tharis/road/wroad2";

void create(){
	::create();
   set_terrain(CITY);
   set_travel(DIRT_ROAD);
	
	set_property("light",2);
	set_property("indoors",0);
	set("short","The west road outside the gates");
	set("long",
@OLI
	%^BOLD%^%^YELLOW%^Road leading from the west gates%^RESET%^
Here you stand before the west gates of Tharis. These are the famed
gates of wealth to the people of Tharis. Here is where all the ores 
and lumber from the bountiful mines and forests that surround the
city. Around you the city bustles. A caravan comes through now and then,
much less than before. To the north the road follows the wall.
To the west the road extends towards the sunset passing by mines, both
active and inactive, to gradually meet with the borders of the 
Tsarvani Empire. Two guards stand guard over the gates. They stop all 
and turn them away.
OLI
	);
	set_exits(([
		"west":"/d/tharis/road/wroad2",
		"east":"/d/tharis/Tharis/wstreet10",
                "up":"/d/tharis/Tharis/tower4",
		"north":"/d/tharis/road/road21"
		]));
	set_items(([]));
	
   set_smell("default","Dust from a passing caravan tickles your nose.");
	set_listen("default","The city bustles around you.");
set_pre_exit_functions(({"east"}),({"stop_elf"}));
}

void reset(){
	::reset();
		
	if(!present("guard")){
		new("/d/tharis/monsters/gguard")->move(TO);
		new("/d/tharis/monsters/gguard")->move(TO);
	}
}

int stop_elf(){
   if(!present("guard")) return 1;
   if(avatarp(TP)) return 1;
   if(TP->query_invis()) return 1;
if((string)TP->query_race() == "half-elf") {
		write("%^BOLD%^The guard gives you an ugly look!");
		tell_room(TO,"%^BOLD%^The guard give "+TPQCN+" an ugly look!",TP);
		return 1;
	}
   if((string)TP->query_race() == "elf" || (string)TP->query_race() == "drow"){
		write("%^BOLD%^The guard grabs you and throws you to the ground!");
		tell_room(TO,"%^BOLD%^The guard grabs "+TPQCN+" and throws "+TP->query_objective()+" to the ground!",TP);
           tell_room(TO,"%^BOLD%^%^RED%^The guard yells: %^WHITE%^Use the the east gate you wretched creature!");
		return 0;
	}
        return 1;
}
