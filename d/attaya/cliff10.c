#include <std.h>

inherit "/d/attaya/spec/ledge";

void create(){
	::create();
	set_property("indoors",0);
	set_property("light",1);
    set_exits(([
          "west":"/d/attaya/cliff11",
         "east":"/d/attaya/cliff9"
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

