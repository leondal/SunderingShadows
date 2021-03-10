
#include <std.h>

inherit "/d/attaya/spec/atemple";

void create(){
	::create();
    set_long(::query_long()+"The skies above you clear for a moment. It is still incredibly dark within these walls. You can almost feel the plight of the tortured souls toiling away to carve these massive pillars, and you ask yourself for what purpose. What might this be a temple of?... What could possibly be worshipped here?");
       set_exits(([
          "south":"/d/attaya/cliff13",
          "north":"/d/attaya/cliff15",
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
