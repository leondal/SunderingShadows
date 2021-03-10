#include <std.h>
#include "../antioch.h"
inherit "/std/food.c";

void create()
{
	::create();
	set_name("standard rations");
	set_short("Standard rations");
	set_id(({"standard rations","rations","food"}));
	set_long(
	"These are standard rations, typical for any adventurer on a long journey."+
	" They have little taste to them but they are filling."
	);
	set_weight(3);
	set_value(10);
   set_strength(50);
	set_destroy();
	set_poison(0);
	set_canSave(1);
	set_my_mess("You eat your standard rations.");
	set_your_mess("eats some standard rations.");
}
