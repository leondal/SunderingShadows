#include <std.h>
#include "../keep.h"
inherit KEEP;
void create() {
	::create();
	set_short("%^YELLOW%^Keep Blacktongue%^RESET%^");
	set_long("This is the northeastern part of the Keep.  South of you are "+
		"the ruins of the keep blacksmith.  Guard towers rests to the northeast "+
		"and northwest of you.  The %^CYAN%^cobblestone path%^RESET%^ you are traveling "+
		"on continues to the east and the west.%^RESET%^");
	set_exits(([
		"west" : KEEPR + "keep3",
		"south" : KEEPR + "smithy",
		"east" : KEEPR + "keepE6"
		] ));
	set_items(([
		({"path","cobblestone path"}) : "%^CYAN%^This path serves as a walkway within the keep.  It is in remarkably good shape.%^RESET%^",
		] ));
}

