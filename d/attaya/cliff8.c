#include <std.h>

inherit "/d/attaya/spec/ledge";

void create(){
	::create();
       set_exits(([
          "west":"/d/attaya/cliff9",
         "east":"/d/attaya/cliff7"
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

