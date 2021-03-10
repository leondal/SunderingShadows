#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("stuffed bunny toy");
	set_id(({ "bunny", "toy", "stuffed animal", "stuffed toy", "stuffed bunny", "stuffed bunny toy", "bunny toy" }));
	set_short("%^BOLD%^%^WHITE%^a fuzzy bunny shaped stuffed animal%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^a fuzzy bunny shaped stuffed animal%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^A fuzzy little bunny made out of soft, durable cotton and filled to near bursting with down feathers.  Pure white, this little bunny is cute as a button with his little %^MAGENTA%^pink yarn nose %^WHITE%^and %^CYAN%^bright blue%^WHITE%^ button eyes.  Crouched down on all fours, his long ears stick straight up and his little cotton puff of a tail almost seems to twitch with eagerness for cuddling.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(350);
}