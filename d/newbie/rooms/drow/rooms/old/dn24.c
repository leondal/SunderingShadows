#include <std.h>
#include "../drownew.h"

inherit PASSAGE;

void create(){
::create();
  	set_exits(([
		"southeast" : DNROOMS+"dn23",
		"northwest" : DNROOMS+"dn25"
    	]));
}