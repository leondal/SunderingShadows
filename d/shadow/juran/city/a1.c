//Coded by Diego//

#include <std.h>
#include "../juran.h"
inherit JALLEY;

void create(){
    	::create();
	new(JMONS+"jellex")->move(TO);    	
    	set_exits(([
   		"east" : JROOMS+"r14",
		"west" : JROOMS+"a2"
    	]));
}