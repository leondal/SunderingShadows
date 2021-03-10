// updated to use willSave & eliminate special food inherit, fix to /std/food also fixed problem with not being filling from poison being set 0 after setting strength  *Styx* 12/24/03

#include <std.h>
#include "../antioch.h"
inherit "/std/food.c";

void create() {
	::create();
	set_name("dry rations");
	set_short("Dry rations");
	set_id(({"dry rations","rations","food"}));
	set_long(
	"These are some dry rations. Not too appetizing and ruined if you get"+
	" them wet. They are filling even though not very tasty."
	);
	set_weight(8);
	set_value(10);
   set_strength(40);
	set_destroy();
	set_poison(0);
	set_canSave(1);
	set_my_mess("You eat the very dry, rather tasteless rations.");
	set_your_mess("eats some dry rations.");
}
