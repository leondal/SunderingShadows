#include <std.h>
#include "../keep.h"
inherit KEEP;
void create() {
	::create();
	set_short("%^YELLOW%^Keep Blacktongue%^RESET%^");
	set_long("This is the northwestern part of the Keep.  To the south are the "+
		"ruins of the blacktongue armory.  A guard tower can be seen to the northwest "+
		"and to the northeast of you.  The %^CYAN%^cobblestone path%^RESET%^ you are "+
		"traveling on continues to the east and the west.");
	set_exits(([
		"east" : KEEPR + "keep3",
		"south" : KEEPR + "armorer",
		"west" : KEEPR + "keepW6"
		] ));
	set_items(([
		({"path","cobblestone path"}) : "%^CYAN%^This path serves as a walkway within the keep.  It is in remarkably good shape.%^RESET%^",
		] ));
}

