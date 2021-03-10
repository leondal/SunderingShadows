#include <std.h>
#include "../theater.h"
inherit COST;
int FLAG;
	void create(){ 
	::create();
	add_item(({"clothing","costumes"}),"%^BOLD%^%^WHITE%^A variety "+
	"of costumes fill the racks. The clothing seems to be separated"+
	" between%^BLUE%^ male%^WHITE%^ and %^MAGENTA%^female%^WHITE%^ "+
	"costumes. Some of the costumes appear to have been slid "+
	"out of order.",);
	set_exits(([ "north" : ROOMDIR"cost2",
			 "west" : ROOMDIR"cost3",
			]));
}
void init(){
::init();
	add_action("slide","slide");
	add_action("slide","shove");
}

int slide(string str){
 	if(str != "costumes" && str != "clothing") 
      return notify_fail("Slide what?\n");

   	tell_object(TP,"%^BOLD%^%^RED%^Fighting against the weight "+
	"of the clothing, you manage to shove the costumes to the "+
	"side with some effort.  An opening to the south is revealed.");
	tell_room(ETP,"%^BOLD%^%^RED%^"+TPQCN+" groans and huffs as"+
	" "+TPQO+" fights against the weight of the clothing.  "+
	"With some effort "+TPQS+" finally manages to shove the "+
	"costumes to the side, revealing an opening to the south.",TP);
        	add_exit(ROOMDIR"cost5","south");
		FLAG = 1;
		return 1;
}
void reset() { 
	::reset(); 
		FLAG=0; 
	return; 
}
