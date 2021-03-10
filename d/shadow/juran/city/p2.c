//Coded by Diego//

#include <std.h>
#include "../juran.h"
inherit JPARK;

void create(){
    	::create();
    	set_exits(([
   		"west" : JROOMS+"p1",
   		"northeast" : JROOMS+"r34",
   		"southwest" : JROOMS+"f1",
   		"south" : JROOMS+"p3"
    	]));
}