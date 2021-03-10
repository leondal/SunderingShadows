#include <std.h>
#include <magic.h>
#include "../poison.h"
inherit POISON_INH;

void create()
{
	::create();
	add_id(({"purple worm poison"}));	
	set_poison_dc(24);
	set_poison_effect_type(({"strength"}));
	set_poison_name("purple worm poison");
	set_poison_dice(({1, 2}));
	set_poison_num_dice(({6, 6}));
	set_delivery_method("injury");
	set_poison_base_value(700);
	//set_number_of_effects(3);
}

