//Coded by Diego//

#include <std.h>
#include "../juran.h"
inherit JUNDER;

void create(){
    	::create();
   set_property("no teleport",1);
    	set_exits(([
   		"up" : JROOMS+"inn"
    	]));
}
