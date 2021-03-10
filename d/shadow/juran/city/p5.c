//Coded by Diego//

#include <std.h>
#include "../juran.h"
inherit JPARK;

void create(){
    	::create();
    	set_exits(([
   		"west" : JROOMS+"p6",
   		"northwest" : JROOMS+"p7",
   		"north" : JROOMS+"f1",
   		"northeast" : JROOMS+"p3",
   		"east" : JROOMS+"p4"
    	]));
}