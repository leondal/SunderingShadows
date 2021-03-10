//Coded by Diego//

#include <std.h>
#include "../juran.h"
inherit JPARK;

void create(){
    	::create();
    	set_exits(([
   		"north" : JROOMS+"p7",
   		"northeast" : JROOMS+"f1",
   		"east" : JROOMS+"p5",
   		"southwest" : JROOMS+"r25"
    	]));
}