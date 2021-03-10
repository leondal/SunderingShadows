//Coded by Diego//

#include <std.h>
#include "../jdrow.h"

inherit DCAV;

void create(){
	::create();
   set_exits(([
		"east" : DROOMS+"c15",
		"south" : DROOMS+"c14",
		"southwest" : DROOMS+"c10",
		"west" : DROOMS+"c9",
		"northwest" : DROOMS+"c8",
		"north" : DROOMS+"c12"
   ]));
}