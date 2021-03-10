#include <std.h>
#include "../keep.h"
inherit KEEP;
void create() {
	::create();
	set_short("%^YELLOW%^Keep Blacktongue%^RESET%^");
	set_long("This is the western part of the Keep.  To the east of you "+
		"is an unmarked building.  Directly to the west is another guard tower.  "+
		"The top of a guard tower is visible far to the northwest of here.  The "+
		"%^CYAN%^cobblestone path%^RESET%^ that you are traveling on continue to the "+
		"north and the south.%^RESET%^");
	set_exits(([
		"west" : KEEPR + "towerW1",
		"east" : KEEPR + "barrack2",
		"south" : KEEPR + "keepW3",
		"north" : KEEPR + "keepW5"
		] ));
	set_items(([
		({"path","cobblestone path"}) : "%^CYAN%^This path serves as a walkway within the keep.  It is in remarkably good shape.%^RESET%^",
		] ));
}

