#include <std.h>
#include "../drownew.h"

inherit PASSAGE;

void create(){
::create();
  	set_exits(([
		"northwest" : DNROOMS+"dn4",
		"southeast" : DNROOMS+"dn6"
    	]));
}