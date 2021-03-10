//Coded by Diego//

#include <std.h>
#include "../juran.h"
inherit JALLEY;

void create(){
    	::create();
    	set_exits(([
   		"north" : JROOMS+"a8",
   		"south" : JROOMS+"r44"
    	]));
}