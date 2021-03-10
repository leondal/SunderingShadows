#include <std.h>
#include "../keep.h"
inherit KEEP;
void create() {
	::create();
	set_short("%^YELLOW%^Keep Blacktongue%^RESET%^");
	set_long("You are just east of the entrance gate.  Just to the north of here are some "+
		"guard barracks.  Directly to the east you see a small guard tower.  The "+
		"%^CYAN%^cobblestone path%^RESET%^ you are traveling on continues to the east "+
		"and to the west.");
	set_exits(([
		"north" : KEEPR + "barrack1",
		"west" : KEEPR + "keep1",
		"east" : KEEPR + "keepE2"
		] ));
	set_items(([
		({"path","cobblestone path"}) : "%^CYAN%^This path serves as a walkway within the keep.  It is in remarkably good shape.%^RESET%^",
		] ));
}

