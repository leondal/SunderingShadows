#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("healer's kit");
	set_id(({ "kit", "healer's kit" }));
	set_short("%^RESET%^%^ORANGE%^A healer's kit%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^A healer's kit%^RESET%^");
	set_long(
@AVATAR
%^RESET%^This is a mid sized leather pouch that contains several healer's items.  Inside are a few bandages, a needle and thread, a pestle and mortar, and other such items one would expect in the day to day practice of medicine.

AVATAR
	);
	set_weight(2);
	set_value(330);
	set_property("lore difficulty",0);
         set_item_bonus("healing",2);
}
