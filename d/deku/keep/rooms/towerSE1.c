#include <std.h>
#include "../keep.h"
inherit TOWERI1;
void create() {
	::create();
	set_exits(([
		"up" : KEEPR + "towerSE2",
		"northwest" : KEEPR + "keepE2"
		] ));
}

