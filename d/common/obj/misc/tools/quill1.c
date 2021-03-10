#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("quill");
	set_id(({ "quill", "writing quill" }));
	set_short("%^RESET%^%^RED%^A fine writing quill%^RESET%^");
	set_obvious_short("%^RESET%^%^RED%^A fine writing quill%^RESET%^");
	set_long(
@AVATAR
%^RESET%^This is a fine writing quill crafted from the feather of a %^BOLD%^%^RED%^cardinal%^RESET%^.  The end of it has been sharpened to a fine point to allow precise strokes to be made.

AVATAR
	);
	set("read",
@AVATAR


AVATAR
	);
     set("langage","common");	set_weight(1);
	set_value(25);
	set_property("lore difficulty",0);
}