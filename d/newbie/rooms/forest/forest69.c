//forest69.c

#include "../../newbie.h"
#include "forest.h"

inherit FOREST"inherit/forestridge";
//inherit the base room for the ridge area

void create(){
    ::create();
    set_exits(([
        "north":FOREST"forest62",
        "northeast":FOREST"forest63",
        "east":FOREST"forest70",
        "southeast":FOREST"forest73",
        "south":FOREST"forest72",
        "west":FOREST"forest68",
        "northwest":FOREST"forest61",
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
    		   	new(MONST"koboldf1")->move(TO);
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