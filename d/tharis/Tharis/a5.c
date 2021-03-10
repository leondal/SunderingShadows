//a5.c

#include <std.h>
#include "../tharis.h"

inherit ALLEY;

void create(){
   ::create();
	set_exits(([
	"west":ROOMS"a4",
	"south":ROOMS"a6",
	]));
}
