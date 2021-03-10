//a9.c

#include <std.h>
#include "../tharis.h"

inherit ALLEY;

void create(){
   ::create();
	set_exits(([
	"northwest":ROOMS"a8",
	"southeast":ROOMS"a10",
	]));
}
