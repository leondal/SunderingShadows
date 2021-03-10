#include <std.h>
#include "../keep.h"
inherit KEEP;
void create() {
	::create();
	set_short("%^YELLOW%^Keep Blacktongue%^RESET%^");
	set_long("You are in the southwestern part of the Keep.  To the east of you "+
		"is the side of an unknown building.  North of here rests a guard tower "+
		"and an unmarked building lies directly across from it.  The %^CYAN%^cobblestone "+
		"path%^RESET%^ you are traveling on continues to the north and the south.%^RESET%^");
	set_exits(([
		"north" : KEEPR + "keepW4",
		"south" : KEEPR + "keepW2"
		] ));
	set_items(([
		({"path","cobblestone path"}) : "%^CYAN%^This path serves as a walkway within the keep.  It is in remarkably good shape.%^RESET%^",
		] ));
}

