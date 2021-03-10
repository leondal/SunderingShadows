#include <std.h>
#include "../keep.h"
inherit TOWERI1;

void create() {
	::create();
	set_exits(([
		"up" : KEEPR + "towerE2",
		"west" : KEEPR + "keepE4"
		] ));
}

