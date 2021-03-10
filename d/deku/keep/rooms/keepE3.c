#include <std.h>
#include "../keep.h"
inherit KEEP;
void create() {
	::create();
	set_short("%^YELLOW%^Keep Blacktongue%^RESET%^");
	set_long("You are in the southeastern part of the Keep.  To the north you see "+
		"the ruins of an alchemist shop, there is a guard tower across from them, and "+
		"directly to the south you see another guard tower.  The %^CYAN%^cobblestone "+
		"path%^RESET%^ you are traveling on continues to the north and the south.");
	set_exits(([
		"north" : KEEPR + "keepE4",
		"south" : KEEPR + "keepE2"
		] ));
	set_items(([
		({"path","cobblestone path"}) : "%^CYAN%^This path serves as a walkway within the keep.  It is in remarkably good shape.%^RESET%^",
		] ));
}

