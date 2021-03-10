#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("sewing kit");
	set_id(({ "kit", "sewing kit" }));
	set_short("%^RESET%^%^MAGENTA%^A sewing kit%^RESET%^");
	set_obvious_short("%^RESET%^%^MAGENTA%^A sewing kit%^RESET%^");
	set_long(
@AVATAR
This is a simple little sewing kit.  It consists of a neat little %^RESET%^%^MAGENTA%^brocade %^RESET%^bag filled with all kinds of needles, thimbles, thread, and so on.  It is quite compact and looks as if it would pack for travel well. 

AVATAR
	);
	set_weight(1);
	set_value(250);
	set_property("lore difficulty",0);
      set_item_bonus("craft, tailor",2);
}
