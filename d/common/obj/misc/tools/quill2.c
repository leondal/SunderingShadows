#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("quill");
	set_id(({ "quill", "writing quill" }));
	set_short("%^BOLD%^%^BLACK%^A fine writing quill%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^A fine writing quill%^RESET%^");
	set_long(
@AVATAR
%^RESET%^This is a fine writing quill crafted from the feather of a %^BOLD%^%^BLACK%^raven%^RESET%^.  The end of it has been sharpened to a fine point to allow precise strokes to be made.

AVATAR
	);
	set_weight(1);
	set_value(25);
	set_property("lore difficulty",0);
}