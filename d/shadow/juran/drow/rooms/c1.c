//Coded by Diego//

#include <std.h>
#include "../jdrow.h"

inherit DCAV;

void create(){
	::create();
   set_exits(([
		"southwest" : DROOMS+"c0",
		"south" : DROOMS+"c2",
		"southeast" : DROOMS+"c3"
   ]));
}