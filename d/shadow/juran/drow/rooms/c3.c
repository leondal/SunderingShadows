//Coded by Diego//

#include <std.h>
#include "../jdrow.h"

inherit DCAV;

void create(){
	::create();
   set_exits(([
		"northwest" : DROOMS+"c1",
		"west" : DROOMS+"c2",
		"northeast" : DROOMS+"c4",
		"east" : DROOMS+"c5",
		"southeast" : DROOMS+"c6"
   ]));
}