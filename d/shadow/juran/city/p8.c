//Coded by Diego//

#include <std.h>
#include "../juran.h"
inherit JPARK;

void create(){
    	::create();
    	set_exits(([
   		"northwest" : JROOMS+"r38",
   		"east" : JROOMS+"p1",
   		"southeast" : JROOMS+"f1",
   		"south" : JROOMS+"p7"
    	]));
}