#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("skinning knife");
	set_id(({ "knife", " skinning knife" }));
	set_short("%^RESET%^A sharp %^BOLD%^%^BLACK%^titanium %^RESET%^skinning knife");
	set_long(
@AVATAR
This is a razor sharp %^BOLD%^%^BLACK%^titanium %^RESET%^skinning knife.  Its blade is about six inches long and has a filet blade along one side and a serrated edge along the other.  The handle is made from sturdy %^BLACK%^%^BOLD%^ash %^RESET%^and has been skillfully wrapped with a dull %^ORANGE%^tan %^RESET%^leather cord.

AVATAR
	);
	set_weight(3);
	set_value(250);
}


