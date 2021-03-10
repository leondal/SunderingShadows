#include <std.h>

inherit "/d/attaya/spec/atemple";

void create(){
	::create();
    set_long(::query_long()+" You are just inside an incredible temple that has been carved into the mountain! The sky is visible above, but only as a ribbon past the cliff walls. Huge columns line the walls and vanish into the darkness before you.");
    set_exits(([
                   "south":"/d/attaya/cliff11",
                   "north":"/d/attaya/cliff13",
                   ]));
}

void reset(){
	int num, i;
	::reset();
	
	if(!present("guardian")){
		num = random(4)+1;
		for(i=0;i<num;i++)
			new("/d/attaya/mon/guardian")->move(TO);
        new("/d/attaya/mon/uwarrior")->move(TO);
	}
	
}

