#include <std.h>
#include "../keep.h"
inherit TOWERI1;
void create() {
	::create();
	set_exits(([
		"up" : KEEPR + "towerW2",
		"east" : KEEPR + "keepW4"
		] ));
}

