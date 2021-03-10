//a4.c

#include <std.h>
#include "../tharis.h"

inherit ALLEY;

void create(){
   ::create();
	set_exits(([
	"northwest":ROOMS"a3",
	"east":ROOMS"a5",
	]));
}
