#include <std.h>

inherit "/d/attaya/spec/ledge";

void create(){
	::create();
    set_long(::query_long()+"A staircase set into the mountain begins here and desends into warmer altitudes.");
    set_exits(([
                   "east":"/d/attaya/cliff69",
                   "down":"/d/attaya/cliff67"
                   ]));
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

