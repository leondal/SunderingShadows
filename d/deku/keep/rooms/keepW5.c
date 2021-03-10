#include <std.h>
#include "../keep.h"
inherit KEEP;
void create() {
	::create();
	set_short("%^YELLOW%^Keep Blacktongue%^RESET%^");
	set_long("This is the northwestern part of the Keep.  You see the "+
		"side of a building to the east of you.  Guard towers rests "+
		"to the northwest and southwest and to the the southeast of here "+
		"there is an unmarked building.  The %^CYAN%^cobblestone path%^RESET%^ "+
		"you are traveling on continues to the north and the south.%^RESET%^");
	set_exits(([
		"north" : KEEPR + "keepW6",
		"south" : KEEPR + "keepW4"
		] ));
	set_items(([
		({"path","cobblestone path"}) : "%^CYAN%^This path serves as a walkway within the keep.  It is in remarkably good shape.%^RESET%^",
		] ));
}

