#include <std.h>
#include "../keep.h"
inherit TOWERI1;
void create() {
	::create();
	set_exits(([
		"up" : KEEPR + "towerSW2",
		"northeast" : KEEPR + "keepW2"
		] ));
}
