#include <std.h>

inherit "/d/attaya/spec/ledge";

void create(){
	::create();
    set_long(::query_long()+"A staircase begins here and extends down the cliff.");
    set_exits(([
                   "west":"/d/attaya/cliff6",
                   "down":"/d/attaya/cliff4"
                   ]));
}

void reset(){
	int num, i;
	::reset();
	
	if(!present("firedemon")){
		num = random(4)+1;
		for(i=0;i<num;i++)
			new("/d/attaya/mon/firedemon")->move(TO);
	}
	
}

