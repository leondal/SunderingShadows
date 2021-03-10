#include <std.h>
#include "../drownew.h"
inherit PASSAGE;

void create(){
::create();
  	set_exits(([
		"southeast" : DNROOMS+"dn1",
		"northeast" : DNROOMS+"dn3",
		"southwest" : DNROOMS+"dn30"
    	]));
}