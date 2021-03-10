#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("jaw breaker");
	set_id(({ "plates", "metal plates", "jawbreaker", "jaw breaker" }));
	set_short("%^BOLD%^%^BLACK%^jawbreaker%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^a set of metal plates%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^When closed and pulled apart, this device is small and compact, allowing for easy transportation.  Consisting of two small plates of %^RESET%^metal %^BOLD%^%^BLACK%^about the size and shape of a pony's horseshoe, a threaded metal circle is affixed at the top of each plate's curve.  These circles are then fitted around a threaded %^RESET%^metal bar %^BOLD%^%^BLACK%^in such a way that the plates can travel up and down when the bar is turned.  By twisting the bar the two plates expand away or contract toward each other, forcing whatever the two plates are set between to do the same.  Often used to extend the jaw, or ribs of a person to the point of %^RESET%^%^CYAN%^breaking%^BOLD%^%^BLACK%^, these devices have long been used by torturers to gather information from less then willing sources.  Due to the way the device is designed, if used in the mouth, one must remove it in order to allow the speaker to talk.%^RESET%^

AVATAR
	);
	set_weight(5);
	set_value(50);
}