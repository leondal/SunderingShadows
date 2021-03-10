#include <std.h>
#include "../keep.h"
inherit KEEP;
void create() {
	::create();
	set_short("%^YELLOW%^Keep Blacktongue%^RESET%^");
        set_long("You are at the southeast corner of the keep.  A guard tower is just "+
		"southeast of here and you see several buildings directly to the north.  Just west "+
		"of here is the entrance gate to the keep, which leads to the dark forest outside.  "+
		"The %^CYAN%^cobblestone path%^RESET%^ you are traveling on continues to the north and "+
		"the west.%^RESET%^");
	set_exits(([
		"southeast" : KEEPR + "towerSE1",
		"west" : KEEPR + "keepE1",
		"north" : KEEPR + "keepE3"
		] ));
	set_items(([
		({"path","cobblestone path"}) : "%^CYAN%^This path serves as a walkway within the keep.  It is in remarkably good shape.%^RESET%^",
		] ));
}


