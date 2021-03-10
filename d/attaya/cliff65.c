
#include <std.h>

inherit "/d/attaya/spec/ledge";

void create(){
	::create();
	set_name("Ledge on the Obsidian Staircase.");
	set_property("indoors",0);
	set_property("light",2);
    set_long(::query_long()+"A staircase begins here and ascends up the cliff again. Far above you, are the walls to the Crystalline Tower of the Black Dawn. You cannot see the tower itself because the walls are too high, and you are a long way beneath them.");
set_exits(([
               "up":"/d/attaya/cliff66",
               "west":"/d/attaya/cliff64"
               ]));
}

void reset(){
	int num, i;
	::reset();
	
	if(!present("toclahar")){
		num = random(4)+1;
		for(i=0;i<num;i++)
			new("/d/attaya/mon/toclahar")->move(TO);
	}
	
}

