#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("torture kit");
	set_id(({ "kit", "torture kit", "leather torture kit" }));
	set_short("%^RESET%^%^ORANGE%^a leather %^BOLD%^%^BLACK%^torture%^RESET%^%^ORANGE%^ kit%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^a small leather kit%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^ORANGE%^This leather kit is designed to hold several small items securely.  About two foot long when unrolled, a leather flap folds over the many small sleeves to keep what is inside secure.  The kit is then rolled up on itself and secured with a leather buckle that keeps it neat and organized.  While every torturer's kit is a little different, most have many of the similar things, including long, sharp %^MAGENTA%^needles%^ORANGE%^, iron %^BOLD%^%^BLACK%^nails%^RESET%^%^ORANGE%^, a set of small heavy weighted %^BOLD%^%^WHITE%^hammers %^RESET%^%^ORANGE%^for breaking the small bones in the hands and feet, %^CYAN%^pliers%^ORANGE%^, %^RESET%^scalpels%^ORANGE%^, skinning %^RED%^flensers %^ORANGE%^and wax %^YELLOW%^candles%^RESET%^%^ORANGE%^.%^RESET%^  

AVATAR
	);
	set_weight(8);
	set_value(450);
}