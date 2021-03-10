//Coded by Diego//

#include <std.h>
#include "../jdrow.h"

inherit DCAV;

void create(){
	::create();
   set_smell("default","The scent of brimstone is carried in the air with "+
    		"traces of moisture from the north.");
  	set_exits(([
		"north" : DROOMS+"c7",
		"east" : DROOMS+"c12",
		"southeast" : DROOMS+"c13",
		"south" : DROOMS+"c9",
		"southwest" : DROOMS+"c5",
		"west" : DROOMS+"c4"
  	]));
}