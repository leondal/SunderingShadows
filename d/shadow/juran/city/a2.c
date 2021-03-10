//Coded by Diego//

#include <std.h>
#include "../juran.h"
inherit JALLEY;

void create(){
    	::create();
    	set_exits(([
   		"east" : JROOMS+"a1",
		"west" : JROOMS+"a3"
    	]));
}