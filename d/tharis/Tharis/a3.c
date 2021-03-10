//a3.c

#include <std.h>
#include "../tharis.h"

inherit ALLEY;

void create(){
   ::create();
	set_exits(([
	"west":ROOMS"main3",
	"southeast":ROOMS"a4",
	]));
}
