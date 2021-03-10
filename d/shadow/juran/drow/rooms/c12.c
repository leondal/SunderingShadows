//Coded by Diego//

#include <std.h>
#include "../jdrow.h"

inherit DCAV;

void create(){
	::create();
   set_smell("default","The scent of brimstone is carried in the air with "+
   	"traces of moisture from the north.");
   set_exits(([
		"southeast" : DROOMS+"c15",
		"south" : DROOMS+"c13",
		"southwest" : DROOMS+"c9",
		"west" : DROOMS+"c8",
		"northwest" : DROOMS+"c7"
   ]));
}