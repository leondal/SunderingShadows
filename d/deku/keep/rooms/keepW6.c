#include <std.h>
#include "../keep.h"
inherit KEEP;
void create() {
	::create();
	
	set_short("%^YELLOW%^Keep Blacktongue%^RESET%^");
	set_long("You are at the northwest corner of the keep.  Another guard tower "+
		"rests to the northwest of you and slightly to the east are the ruins of the "+
		"armor shop.  To the south of you there is another guard tower and an unmarked "+
		"building lies across from it.  The %^CYAN%^cobblestone path%^RESET%^ you are "+
		"traveling on continues to the south and the east.%^RESET%^");
	set_exits(([
		"northwest" : KEEPR + "towerNW1",
		"east" : KEEPR + "keepW7",
		"south" : KEEPR + "keepW5"
		] ));
	set_items(([
		({"path","cobblestone path"}) : "%^CYAN%^This path serves as a walkway within the keep.  It is in remarkably good shape.%^RESET%^",
		] ));
}

