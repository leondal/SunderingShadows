#include <std.h>
#include "../theater.h"
inherit MEZZ;
int FLAG;
	void create(){ 
	::create();
	set_exits(([ "east" : ROOMDIR"mezz1",
			]) );
}


void init(){
::init();
	add_action("part","part");
	add_action("part","open");
}
int part(string str){
 	if(str != "curtain" && str != "curtains") 
      return notify_fail("Part what?\n");

   	tell_object(TP,"%^RED%^You part the curtains, unveiling the boxseat.");
	tell_room(ETP,"%^BOLD%^%^RED%^"+TPQCN+" parts the curtains, "+
	"unveiling a boxseat.",TP);
   	add_exit(ROOMDIR"box2","boxseat");
		FLAG = 1;
		return 1;
}
void reset() { 
	::reset(); 
		FLAG=0; 
	return; 
}
