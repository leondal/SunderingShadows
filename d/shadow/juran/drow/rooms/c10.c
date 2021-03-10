//Coded by Diego//

#include <std.h>
#include "../jdrow.h"

inherit DCAV;

void create(){
	::create();
   set_exits(([
		"northeast" : DROOMS+"c13",
		"east" : DROOMS+"c14",
		"south" : DROOMS+"c11",
		"west" : DROOMS+"c6",
		"northwest" : DROOMS+"c5",
		"north" : DROOMS+"c9"
   ]));
}