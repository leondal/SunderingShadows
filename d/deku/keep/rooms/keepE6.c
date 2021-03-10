#include <std.h>
#include "../keep.h"
inherit KEEP;
void create() {
	::create();
	set_short("%^YELLOW%^Keep Blacktongue%^RESET%^");
	set_long("You are at the northeast corner of the keep.  Northeast of you "+
		"rests one of many guard towers.  You can see the blacksmith building to the west "+
		"and the ruins of an alchemist shop far to the south.  The %^CYAN%^cobblestone path "+
		"%^RESET%^you are traveling on continues to the west and the south.%^RESET%^");
	set_exits(([
		"northeast" : KEEPR + "towerNE1",
		"west" : KEEPR + "keepE7",
		"south" : KEEPR + "keepE5"
		] ));
	set_items(([
		({"path","cobblestone path"}) : "%^CYAN%^This path serves as a walkway within the keep.  It is in remarkably good shape.%^RESET%^",
		] ));
}

