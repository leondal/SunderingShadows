//Coded by Diego//

#include <std.h>
#include "../juran.h"
inherit JALLEY;

void create(){
    	::create();
    	set_exits(([
   		"north" : JROOMS+"a9",
   		"south" : JROOMS+"a7"
    	]));

}