//Coded by Diego//

#include <std.h>
#include "../jdrow.h"

inherit DCAV;

void create(){
	::create();
   set_exits(([
		"northeast" : DROOMS+"c7",
		"east" : DROOMS+"c8",
		"southeast" : DROOMS+"c9",
		"south" : DROOMS+"c5",
		"southwest" : DROOMS+"c3"
   ]));
}