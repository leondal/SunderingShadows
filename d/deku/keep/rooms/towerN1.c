#include <std.h>
#include "../keep.h"
inherit TOWERI1;
void create() {
	::create();
	set_exits(([
		"up" : KEEPR + "towerN2",
		"south" : KEEPR + "keep3"
		]));
}
