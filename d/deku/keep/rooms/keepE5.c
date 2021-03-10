#include <std.h>
#include "../keep.h"
inherit KEEP;
void create() {
	::create();
	set_short("%^YELLOW%^Keep Blacktongue%^RESET%^");
	set_long("This is the northeastern part of the Keep.  To the west of you is the side "+
		"of one of the buildings.  There is a guard tower northeast of you and toward the "+
		"south are the ruins of an alchemist shop.  Another guard tower rests across from the ruins.  "+
		"The %^CYAN%^cobblestone path%^RESET%^ you are traveling on continues to the "+
		"north and the south.%^RESET%^");
	set_exits(([
		"north" : KEEPR + "keepE6",
		"south" : KEEPR + "keepE4"
		] ));
	set_items(([
		({"path","cobblestone path"}) : "%^CYAN%^This path serves as a walkway within the keep.  It is in remarkably good shape.%^RESET%^",
		] ));
}

