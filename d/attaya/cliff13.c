#include <std.h>

inherit "/d/attaya/spec/atemple";

void create(){
	::create();
    set_long(::query_long()+"The pilars hold up numerous ledges above you. They are alive with activity. Guardians and warriors scramble across them like ants far above, perhaps converging on your spot! Beyond them, a sliver of sky marks the top of the cliff walls. All around you has been carved into the very rock. Numerous bones lie discarded against the walls and in the shadows.");
    set_exits(([
                   "south":"/d/attaya/cliff12",
                   "north":"/d/attaya/cliff14",
                   ]));
}

void reset(){
	int num, i;
	::reset();
	
	if(!present("warrior")){
		num = random(4)+1;
		for(i=0;i<num;i++)
			new("/d/attaya/mon/uwarrior")->move(TO);
	}
	
}
