#include <std.h>
#include "../keep.h"
inherit TOWERI1;

void create() {
	::create();
	set_exits(([
		"up" : KEEPR + "towerNW2",
		"southeast" : KEEPR + "keepW6"
		] ));
}
