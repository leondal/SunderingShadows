//forest67.c

#include "../../newbie.h"
#include "forest.h"

inherit FOREST"inherit/forestedge";
//inherit the base room for the edge of the forest

void create(){
    ::create();
    set_exits(([
        "north":FOREST"forest60",
        "northeast":FOREST"forest61",
        "east":FOREST"forest68",
        "northwest":FOREST"forest59",
    ]));
}

void reset() {
    ::reset();
	if ((random(6) < 2 ) && (!present("kobold"))) {	
    	switch(random(3)) {
    		case 0: 
   		    	new(MONST"koboldf")->move(TO);
   		    	new(MONST"koboldf")->move(TO);
   		    	break;
   		    case 1:
    		   	new(MONST"koboldf3")->move(TO);
		    	new(MONST"koboldf")->move(TO);
				new(MONST"koboldf")->move(TO);
				break;
    		case 2:	
    			new(MONST"koboldf2")->move(TO);
				new(MONST"koboldf")->move(TO);
				new(MONST"koboldf")->move(TO);
				new(MONST"koboldf")->move(TO);
				break;
			}
		}
}