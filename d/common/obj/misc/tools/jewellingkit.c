#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("jeweller's tools");
        set_id(({ "jewelling kit", "jeweler's tools", "tools", "tool set" }));
	set_short("A set of %^BOLD%^%^RED%^jeweller's %^RESET%^tools");
	set_obvious_short("A set of %^BOLD%^%^RED%^jeweller's %^RESET%^tools");
	set_long(
@AVATAR
Contained within this leather pouch is a set of tools most likely used for jewelling.  Inside you see some %^BOLD%^%^WHITE%^polish%^RESET%^, a tiny hammer, along with various files, tweezers, jewelling saws, spare wire, and other such needed for day to day repairs on jewelry.

AVATAR
	);
	set_weight(1);
	set_value(250);
	set_property("lore difficulty",0);
         set_item_bonus("craft, jeweller",2);
}
