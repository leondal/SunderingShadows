//Coded by Diego//

#include <std.h>
#include "../jdrow.h"

inherit DCAV;

void create(){
	::create();
   set_exits(([
		"northeast" : DROOMS+"c12",
		"east" : DROOMS+"c13",
		"southeast" : DROOMS+"c14",
		"south" : DROOMS+"c10",
		"southwest" : DROOMS+"c6",
		"west" : DROOMS+"c5",
		"northwest" : DROOMS+"c4",
		"north" : DROOMS+"c8"
   ]));
}