#include <std.h>
#include "../drownew.h"

inherit PASSAGE;

void create(){
::create();
  	set_exits(([
		"northeast" : DNROOMS+"dn29",
		"southeast" : DNROOMS+"dn24",
		"west" : DNROOMS+"dn26"
    	]));
}