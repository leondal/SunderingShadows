
#include <std.h>

inherit "/d/attaya/spec/ledge";

void create(){
	::create();
set_long(::query_long()+"A narrow groove is carved into the cliff. A stairway begins here and ascends into the groove.");
       set_exits(([
          "west":"/d/attaya/cliff7",
          "east":"/d/attaya/cliff5",
         "up":"/d/attaya/cliff46"
]));
}

void reset(){
	int num, i;
	::reset();
	
	if(!present("firebolt")){
		num = random(4)+1;
		for(i=0;i<num;i++)
			new("/d/attaya/mon/firebolt")->move(TO);
	}
	
}


