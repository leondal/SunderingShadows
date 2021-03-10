//a8.c

#include <std.h>
#include "../tharis.h"

inherit ALLEY;

void create(){
   ::create();
	set_exits(([
	"west":ROOMS"a7",
	"southeast":ROOMS"a9",
	]));
}
