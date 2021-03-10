//hill31a.c - entrance to hobgoblin lair

#include "../../newbie.h"

inherit VAULT;
int items;

void create(){
   ::create();
   set_property("light",2);
   set_property("no teleport",1);
   set_terrain(HILLS);
   set_travel(FOOT_PATH);   
   set_short("%^BOLD%^%^BLACK%^Lair entrance%^RESET%^");
   set_long(
@STYX
This appears to be a somewhat fortified entrance to the lair of something most likely unfriendly.  There is a makeshift gate to the northeast that covers the way further into the hillside.  You can make out a downward slope past the gate.   
STYX
   );
   set_smell("default","You catch a whiff of fresh blood.");
   set_listen("default","You hear voices arguing from beyond the gate.");
   set_items( ([ "slope" : "The earthen floor is dry and packed from use.  Here and there you can make out a footprints that look humanoid.", 
	({"hillside"}):"%^GREEN%^The otherwise rolling hillside outside opened into this cave entrance that is blocked by a gate.",
	]) );
   set_exits(([
       "gate":HILL"hill31b",
       "southwest":HILL"hill31",
   ]));
   set_door("gate","/d/newbie/rooms/hill/hill31b","gate",0);
   set_door_description("gate", "This is a crude gate made from tree limbs lashed together with leather straps.");
 	set_string("gate","open","The gate groans loudly as it swings open.");
 	set_open("gate",0);
    "/d/newbie/rooms/hill/hill31b"->set_open("gate",0);
}

void init() {
        ::init();
}

void reset() {
	::reset();
	if (!present("hobgoblin") ) {	
    	switch(random(5)) {
    		case 0: 
   		    	new(HILL"mon/hobgobf")->move(TO);
   		    	break;
   		case 1:
   		    	new(HILL"mon/hobgob")->move(TO);
    		   	new(HILL"mon/hobgobf2")->move(TO);
    		   	new(HILL"mon/hobgobfe")->move(TO);
			break;
    		case 2:	
    			new(HILL"mon/hobgobf")->move(TO);
			new(HILL"mon/hobgob")->move(TO);
			break;
		case 3:
    			new(HILL"mon/hobgobf2")->move(TO);
			new(HILL"mon/hobgobfe")->move(TO);
			break;			
    		case 4:	
    			new(HILL"mon/hobgobfe")->move(TO);
			break;
		}
	}
}
