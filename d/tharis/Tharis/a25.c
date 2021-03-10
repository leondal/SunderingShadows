//a25.c

#include <std.h>
#include "../tharis.h"

inherit ALLEY;

void create(){
   ::create();
	set_exits(([
	"southeast":ROOMS"a24",
	"northwest":ROOMS"a26",
	]));
}
