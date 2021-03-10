#include <std.h>
#include "../keep.h"
inherit KEEP;
void create() {
	::create();
	set_short("%^YELLOW%^Keep Blacktongue%^RESET%^");
	set_long("This is the eastern part of the Keep.  To the west of you are "+
		"the ruins of an alchemist shop.  A wooden %^YELLOW%^sign%^RESET%^ has been planted in the "+
		"ground next to the entrance of it.  To the east of you is a guard tower.  The "+
		"%^CYAN%^cobblestone path%^RESET%^ you are traveling on continues to the north "+
		"and the south.%^RESET%^");
	set_exits(([
		"west" : KEEPR + "magic",
		"east" : KEEPR + "towerE1",
		"south" : KEEPR + "keepE3",
		"north" : KEEPR + "keepE5"
		] ));
	set_items(([
		({"path","cobblestone path"}) : "%^CYAN%^This path serves as a walkway within the keep.  It is in remarkably good shape.%^RESET%^",
		({"sign","wooden sign"}) : "%^YELLOW%^The alchemist shop is now closed, under order of Lord Hawk.%^RESET%^",
		] ));
}

