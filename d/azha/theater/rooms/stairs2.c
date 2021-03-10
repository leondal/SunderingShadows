#include <std.h>
#include "../theater.h"
inherit STAIRS;
int FLAG;
	void create(){ 
	::create();
	add_item(({"rug","runner","carpet","floor"}),"%^YELLOW%^Woven from a lightweight"+
		" wool, the vibrant colors of the runner can still be made out in some"+
		" sections.  A faint %^RESET%^%^ORANGE%^orange%^BOLD%^ sunburst pattern"+
		" can be made out, though it seems time has eroded a majority of this"+
		" pattern. The yellow rug is threadbare in certain areas though, with"+
		" holes dotting it's surface.  A %^RED%^fiery red%^YELLOW%^ raguly "+
                "border frames the yellow wool. There appears to be two worn paths "+
		"in the carpet.  One leading from the stairs to the west and another"+
		" that leads to the northern wall and stops.",);
	add_item(({"walls","wall"}),"%^RED%^The plaster walls are "+
		"painted a dark shade of red, working in harmony with the lavish "+
		"decorations of the theater. The north wall appears to have a "+
		"faint seamline.",);
        add_item(({"north wall","northwall"}),"%^RED%^A faint seamline separates"+
		" a section of the north wall from the rest of the wall.  There does"+
		" not seem to be any sign of a hand hold or hardware that might suggest"+
		" this is a door.  Looking closer at the dark red walls though, you can"+
		" see signs of handprints pressed against this section of the wall.",);
	set_exits(([ "west" : ROOMDIR"mezz1",
			 "stairs" : ROOMDIR"stairs1",
	]));
	}


void init(){
::init();
        add_action("press","press");
        add_action("press","slide");
}
int press(string str){
     	if(str != "north wall" && str != "northwall") 
      	return notify_fail("Press What?\n");

      tell_object(TP,"%^BOLD%^%^RED%^You press your hand to the "+
		"panel and push on the wall.  The section parts from the wall"+
		" and slides to the left, revealing a ladder leading up.");
	tell_room(ETP,"%^BOLD%^%^RED%^"+TPQCN+" presses a section"+
		" of the north wall back and slides it open, revealing a "+
		"ladder leading up.",TP);
      		add_exit(ROOMDIR"cat1","up");
         		FLAG = 1;
   	return 1;
}
void reset() { 
	::reset(); 
		FLAG=0; 
	return; 
}

