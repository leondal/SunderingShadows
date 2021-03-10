//Coded by Diego//

#include <std.h>
#include "../jdrow.h"

inherit DCAV;

void create(){
 	::create();
  	set_exits(([
		"northeast" : DROOMS+"c8",
		"east" : DROOMS+"c9",
		"southeast" : DROOMS+"c10",
		"south" : DROOMS+"c6",
		"west" : DROOMS+"c3",
		"north" : DROOMS+"c4"
    ]));
}