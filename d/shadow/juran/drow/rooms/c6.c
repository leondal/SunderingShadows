//Coded by Diego//

#include <std.h>
#include "../jdrow.h"

inherit DCAV;

void create(){
 	::create();
   set_exits(([
		"northeast" : DROOMS+"c9",
		"east" : DROOMS+"c10",
		"southeast" : DROOMS+"c11",
		"northwest" : DROOMS+"c3",
		"north" : DROOMS+"c4"
   ]));
}