//forest64.c

#include "../../newbie.h"
#include "forest.h"

inherit FOREST"inherit/forestridge";
//inherit the base room for the ridge area

void create(){
    ::create();
    set_exits(([
        "north":FOREST"forest55",
        "northeast":FOREST"forest56",
        "east":FOREST"forest65",
        "south":FOREST"forest71",
        "southwest":FOREST"forest70",
        "west":FOREST"forest63",
        "northwest":FOREST"forest54",
    ]));
}

void reset() {
    ::reset();
	if ((random(6) < 2 ) && (!present("kobold"))) {	
    	switch(random(3)) {
    		case 0: 
   		    	new(MONST"koboldf2")->move(TO);
   		    	new(MONST"koboldf")->move(TO);
   		    	new(MONST"koboldf")->move(TO);
   		    	break;
   		    case 1:
    		   	new(MONST"koboldf1")->move(TO);
		    	new(MONST"koboldf")->move(TO);
				new(MONST"koboldf")->move(TO);
   		    	new(MONST"koboldf")->move(TO);
				break;
    		case 2:	
    			new(MONST"koboldf3")->move(TO);
				new(MONST"koboldf")->move(TO);
				new(MONST"koboldf")->move(TO);
				new(MONST"koboldf")->move(TO);
				break;
			}
		}
}