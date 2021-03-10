#include <std.h>
#include "../keep.h"
inherit KEEP;
void create() {
	::create();
	set_short("%^YELLOW%^Keep Blacktongue%^RESET%^");
	set_long("You are at the southwest corner of the Keep.  Just to the east "+
		"are the ruins of the once populated pub.  Further east of here is the "+
		"entrance gate of the keep, which leads outside to the dark forest.  The "+
		"%^CYAN%^cobblestone path%^RESET%^ you are traveling on continues to the north "+
		"and the east.%^RESET%^");
	set_exits(([
		"north" : KEEPR + "keepW3",
		"east" : KEEPR + "keepW1",
		"southwest" : KEEPR + "towerSW1"
		] ));
	set_items(([
		({"path","cobblestone path"}) : "%^CYAN%^This path serves as a walkway within the keep.  It is in remarkably good shape.%^RESET%^",
		] ));
}
