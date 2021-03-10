#include <std.h>
#include "../keep.h"
inherit KEEP;
void create() {
	::create();
	set_short("%^YELLOW%^Keep Blacktongue%^RESET%^");
	set_long("You are standing just inside the entrance gates of the Keep.  "+
		"To the south is the drawbridge out.  To the north is a %^RED%^brick%^RESET%^ path "+
		"leading to the %^YELLOW%^looming tower%^RESET%^.  There is a two story building "+
		"to the east and to the west lie the ruins of the once populated pub.  The "+
		"%^CYAN%^cobblestone path%^RESET%^ you are traveling on continues to the east "+
		"and the west.%^RESET%^");
	set_exits(([
		"south" : KEEPR + "draw",
		"north" : KEEPR + "keep2",
		"west" :  KEEPR + "keepW1",
		"east" :  KEEPR + "keepE1"
    ] ));
	set_items(([
		({"tower","main tower","north tower","looming tower"}) : "%^YELLOW%^This is the main tower of keep blacktongue, is rises high above the other guard towers of the keep.  Every floor of the tower is covered with windows of various sizes and shapes.%^RESET%^",
		({"cobblestone path"}) : "%^CYAN%^This path serves as a walkway throughout the keep.  It is in remarkably good shape.%^RESET%^",
		({"brick path"}) : "%^RED%^This path continues north toward the main tower of Keep Blacktongue.%^RESET%^",
		({"path","paths"}) : "%^BLUE%^There are two paths here, one made of %^CYAN%^cobblestone%^RESET%^%^BLUE%^ and the other of %^RED%^brick%^RESET%^%^BLUE%^.%^RESET%^",
    ] ));
}

