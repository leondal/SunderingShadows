//a10.c

#include <std.h>
#include "../tharis.h"

inherit ALLEY;

void create(){
   ::create();
	set_exits(([
	"northwest":ROOMS"a9",
	"east":ROOMS"a12",
	]));

}
