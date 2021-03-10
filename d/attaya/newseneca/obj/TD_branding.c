#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("branding iron");
	set_id(({ "branding iron", "iron", "brand" }));
	set_short("%^BOLD%^%^BLACK%^branding iron%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^branding iron%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This length of iron is about three feet long.  A thick %^RESET%^%^ORANGE%^leather handle %^BOLD%^%^BLACK%^wraps one end, providing a secure and safe means of handling this device.  The other end has been twisted into a brand.  A shaped image that when heated in a %^RESET%^%^RED%^fire %^BLACK%^%^BOLD%^can burn its design into whatever it is pressed against.  Originally designed for marking %^RESET%^%^ORANGE%^livestock%^BOLD%^%^BLACK%^, these have been used to mark other, more %^RESET%^delicate%^BOLD%^%^BLACK%^, property as well.%^RESET%^

AVATAR
	);
	set_weight(4);
	set_value(10);
}