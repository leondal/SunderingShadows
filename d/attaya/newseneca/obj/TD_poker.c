#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("iron poker");
	set_id(({ "poker", "iron poker", "iron" }));
	set_short("%^BOLD%^%^BLACK%^iron poker%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^iron poker%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This device is a three foot length of iron metal with a sharply tapered point at one end and a thick %^RESET%^%^ORANGE%^leather%^BOLD%^%^BLACK%^ wrapped handle at the other.  Though dangerous enough on its own, when the tip is heated in a %^RESET%^%^RED%^fire %^BOLD%^%^BLACK%^it can brand the flesh of whatever it comes in contact with.%^RESET%^

AVATAR
	);
	set_weight(4);
	set_value(5);
}