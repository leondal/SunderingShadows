//Coded by Diego//

#include <std.h>
#include "../jdrow.h"

inherit DCAV;


void create(){
 	::create();
  	set_exits(([
		"west" : DROOMS+"c0",
		"north" : DROOMS+"c1",
		"east" : DROOMS+"c3"
   ]));
}