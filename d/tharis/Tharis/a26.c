//a26.c

#include <std.h>
#include "../tharis.h"

inherit ALLEY;

void create(){
   ::create();
	set_exits(([
	"southeast":ROOMS"a25",
	"west":ROOMS"main7",
	]));
}
