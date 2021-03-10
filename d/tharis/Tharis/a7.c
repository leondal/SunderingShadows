//a7.c

#include <std.h>
#include "../tharis.h"

inherit ALLEY;

void create(){
   ::create();
	set_exits(([
	"east":ROOMS"a8",
	"west":ROOMS"main5",
	]));
}
