//Coded by Diego//

#include <std.h>
#include "../juran.h"
inherit JPARK;

void create(){
    	::create();
    	set_exits(([
   		"west" : JROOMS+"p8",
   		"east" : JROOMS+"p2",
   		"southwest" : JROOMS+"p7",
   		"south" : JROOMS+"f1",
   		"southeast" : JROOMS+"p3"
    	]));
}