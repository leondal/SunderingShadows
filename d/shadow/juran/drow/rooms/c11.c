//Coded by Diego//

#include <std.h>
#include "../jdrow.h"

inherit DCAV;

void create(){
	::create();
   set_exits(([
		"northeast" : DROOMS+"c14",
		"northwest" : DROOMS+"c6",
		"north" : DROOMS+"c10"
   ]));
}