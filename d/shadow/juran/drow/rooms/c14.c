//Coded by Diego//

#include <std.h>
#include "../jdrow.h"

inherit DCAV;

void create(){
	::create();
   set_exits(([
		"northeast" : DROOMS+"c15",
		"southwest" : DROOMS+"c11",
		"west" : DROOMS+"c10",
		"northwest" : DROOMS+"c9",
		"north" : DROOMS+"c13"
   ]));
}