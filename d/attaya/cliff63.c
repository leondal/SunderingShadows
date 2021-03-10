#include <std.h>

inherit "/d/attaya/spec/ledge";

void create(){
	::create();
	set_name("Ledge on the Obsidian Staircase.");
    set_long(::query_long()+"You are just above the smokescreen that wafts up from the River of Flame. From here, you look out over the black clouds and see the beautiful ocean in the distance. At once, you long to be on the beach again. Far above you, are the walls to the Crystalline Tower of the Black Dawn. You cannot see the tower itself because the walls are too high, and you are a long way beneath them.");
    set_exits(([
                   "west":"/d/attaya/cliff62",
                   "east":"/d/attaya/cliff64"
                   ]));
	
    set_smell("default", "It is getting cooler as you rise higher.");
    set_listen("default", "The whistle of the wind here is the only sound");
}

void reset(){
	int num, i;
	::reset();
	
	if(!present("entity")){
		num = random(4)+1;
		for(i=0;i<num;i++)
			new("/d/attaya/mon/entity")->move(TO);
	}
	
}

