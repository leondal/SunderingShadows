#include <std.h>
inherit "/std/food.c";

void create() {
	::create();
	set_name("iron rations");
	set_short("Iron rations");
	set_id(({"iron rations","rations","food"}));
	set_long(
	"These are iron rations. They are the most filling of the rations that"+
	" adventurers typically carry, and they are probably also the worst"+
	" tasting."
	);
	set_destroy();
	set_weight(5);
	set_value(15);
	set_poison(0);
   set_strength(60);
	set_canSave(1);
	set_my_mess("You quickly bolt down the iron rations, not wanting to taste them.");
	set_your_mess("bolts down some iron rations.");
}
