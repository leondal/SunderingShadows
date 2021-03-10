#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("thumb screws");
	set_id(({ "thumbscrews", "thumb screws" }));
	set_short("%^RESET%^a set of thumbscrews%^RESET%^");
	set_obvious_short("%^RESET%^a set of thumbscrews%^RESET%^");
	set_long(
@AVATAR
%^RESET%^Though called thumb screws, these small %^ORANGE%^wood %^RESET%^and %^BOLD%^%^BLACK%^metal %^RESET%^devices can be used to crush fingers, thumbs, toes, noses, ears and even tails.  Designed to fit around the intended digit, the half-moon shaped %^BOLD%^%^BLACK%^metal cuffs %^RESET%^begin in the most extended position and is then tightened down by turning the small %^ORANGE%^wooden nob%^RESET%^ at the end of a threaded screw.  By doing this, the two pieces of metal are drawn together in such a way that they begin to flatten whatever is between them crushing %^BOLD%^%^WHITE%^bone %^RESET%^and stretching %^YELLOW%^skin %^RESET%^in a very painful manner.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(8);
}