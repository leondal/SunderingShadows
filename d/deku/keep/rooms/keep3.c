#include <std.h>
#include "../keep.h"
inherit KEEP;
void create() {
	::create();
	set_short("%^YELLOW%^Keep Blacktongue%^RESET%^");
	set_long("This is the northern part of Keep Blacktongue.  The main %^YELLOW%^tower%^RESET%^ "+
		"of the keep rests directly south of you, it is immense and blocks "+
		"your view in that direction.  The ruins of a shop can be seen to the "+
		"southwest and to the southeast.  Directly to the north of you is another "+
		"guard tower.  The %^CYAN%^cobblestone path%^RESET%^ you are traveling on "+
		"continues to the east and the west.");
	set_exits(([
		"west" : KEEPR + "keepW7",
		"north" : KEEPR + "towerN1",
		"east" :  KEEPR + "keepE7"
		] ));
	set_items(([
		({"path","cobblestone path"}) : "%^CYAN%^This path serves as a walkway within the keep.  It is in remarkably good shape.%^RESET%^",
		({"tower","main tower","immense tower","south tower"}) : "%^YELLOW%^This is the main tower of keep blacktongue, is rises high above the other guard towers of the keep.  Every floor of the tower is covered with windows of various sizes and shapes.%^RESET%^",
		] ));
	
	
}

