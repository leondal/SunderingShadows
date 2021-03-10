#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("tool set");
	set_id(({ "set", "tools", "tool set", "armorsmithing tool set" }));
	set_short("%^BOLD%^%^BLACK%^A small tool set%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^A small tool set for armor%^RESET%^");
	set_long(
@AVATAR
Contained within this leather pouch is a set of tools most likely used for armorsmithing.  Inside you see some %^BOLD%^%^WHITE%^polish%^RESET%^, an %^BOLD%^%^BLACK%^oil%^RESET%^%^ORANGE%^cloth%^RESET%^, a small %^RESET%^%^RED%^hammer%^RESET%^, plus a myraid of replacement leather, resizing equipment, and such that one would expect to need for day to day repairs.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(250);
	set_property("lore difficulty",0);
         set_item_bonus("craft, armorsmith",2);
}
