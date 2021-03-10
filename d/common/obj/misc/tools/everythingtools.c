#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("tools");
	set_id(({ "tools", "tool set", "small tool set" }));
	set_short("%^RESET%^%^ORANGE%^A small tool set%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^A small tool set%^RESET%^");
	set_long(
@AVATAR
Contained within this leather pouch is a set of generic tools that would most likely be useful in repairing most anything.  Inside you can see several whetstones, oilcloths, bottles of polish along with various files, saws, bits of metal, and other such things one would need for day to day repair on weapons, armor, or perhaps even jewelry.

AVATAR
	);
	set_weight(1);
	set_value(465);
	set_property("lore difficulty",0);
}