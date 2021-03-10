//Coded by Diego//

#include <std.h>
#include "../juran.h"
inherit JPARK;

void create(){
    	::create();
    	set_exits(([
   		"west" : JROOMS+"p5",
   		"northwest" : JROOMS+"f1",
   		"north" : JROOMS+"p3",
   		"southeast" : JROOMS+"r29"
    	]));
}