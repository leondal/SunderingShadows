//Coded by Diego//

#include <std.h>
#include "../juran.h"
inherit JPARK;

void create(){
    	::create();
    	set_exits(([
   		"west" : JROOMS+"f1",
   		"northwest" : JROOMS+"p1",
   		"north" : JROOMS+"p2",
   		"southwest" : JROOMS+"p5",
   		"south" : JROOMS+"p4"
    	]));
}