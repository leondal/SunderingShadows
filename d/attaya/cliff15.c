
#include <std.h>

inherit "/d/attaya/spec/atemple";

void create(){
	::create();
    set_long(::query_long()+"In the shadows, you see movement. Invisible warriors slip in and out. Every now and then, you see shadows on the pillars, then when you seek out the sources, they are gone. This is truely a fearful place. The reaper of death kneels upon a cliff far above and watches you.");
       set_exits(([
          "south":"/d/attaya/cliff14",
          "north":"/d/attaya/cliff16",
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
