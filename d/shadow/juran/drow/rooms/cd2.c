//Coded by Diego//

#include <std.h>
#include "../jdrow.h"

inherit DHALL;

void create(){
   ::create();
   set_exits(([
		"northeast" : DROOMS+"cd3",
		"west" : DROOMS+"cd1"
   ]));
}