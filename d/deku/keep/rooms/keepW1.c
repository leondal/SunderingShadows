#include <std.h>
#include "../keep.h"
inherit KEEP;
void create() {
	::create();
	set_short("%^YELLOW%^Keep Blacktongue%^RESET%^");
	set_long("You are just to the west of the entrance gate.  North of here are the "+
		"ruins of the once populated pub, it is deadly quiet there now.  To the west "+
		"of you is a guard tower and the main %^YELLOW%^tower%^RESET%^ of the keep rises "+
		"high in the air in the middle of the keep.  The %^CYAN%^cobblestone path%^RESET%^ "+
		"you are traveling on continues to the east and the west.");
	set_exits(([
		"north" : KEEPR + "pub",
		"west" : KEEPR + "keepW2",
		"east" : KEEPR + "keep1"
		] ));
	set_items(([
		({"path","cobblestone path"}) : "%^CYAN%^This path serves as a walkway within the keep.  It is in remarkably good shape.%^RESET%^",
		({"tower","main tower","north tower"}) : "%^YELLOW%^This is the main tower of keep blacktongue, is rises high above the other guard towers of the keep.  Every floor of the tower is covered with windows of various sizes and shapes.%^RESET%^",
		] ));
}

