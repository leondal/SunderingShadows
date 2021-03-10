//Coded by Diego//

#include <std.h>
#include "../juran.h"
inherit JALLEY;

void create(){
    	::create();
    	set_exits(([
   		"north" : JROOMS+"a4",
		"south" : JROOMS+"a6"
    	]));
}