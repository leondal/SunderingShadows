//forest61.c

#include "../../newbie.h"
#include "forest.h"

inherit FOREST"inherit/forestridge";
//inherit the base room for the ridge area

void create(){
    ::create();
    set_exits(([
        "north":FOREST"forest52",
        "northeast":FOREST"forest53",
        "east":FOREST"forest62",
        "southeast":FOREST"forest69",
        "south":FOREST"forest68",
        "southwest":FOREST"forest67",
        "west":FOREST"forest60",
        "northwest":FOREST"forest51",
    ]));
}

void reset() {
    ::reset();
	if ((random(6) < 2) && (!present("kobold"))) {	
    	switch(random(3)) {
    		case 0: 
   		       	new(MONST"koboldf")->move(TO);
   		    case 1:
    		   	new(MONST"koboldf2")->move(TO);
		    	new(MONST"koboldf")->move(TO);
				break;
    		case 2:	
    			new(MONST"koboldf1")->move(TO);
				new(MONST"koboldf")->move(TO);
				new(MONST"koboldf")->move(TO);
				new(MONST"koboldf")->move(TO);
				break;
			}
		}
}