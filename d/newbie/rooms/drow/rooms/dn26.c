#include <std.h>
#include "../drownew.h"

inherit ALCOVE;

void create(){
::create();
  	set_exits(([
		"east" : DNROOMS+"dn25",
		"west" : DNROOMS+"dn27"
    	]));
}