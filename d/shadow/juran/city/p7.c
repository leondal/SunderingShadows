//Coded by Diego//

#include <std.h>
#include "../juran.h"
inherit JPARK;

void create(){
    	::create();
    	set_exits(([
   		"north" : JROOMS+"p8",
   		"northeast" : JROOMS+"p1",
   		"east" : JROOMS+"f1",
   		"southeast" : JROOMS+"p5",
   		"south" : JROOMS+"p6"
    	]));
}