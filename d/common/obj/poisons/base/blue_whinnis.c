#include <std.h>
#include <magic.h>
#include "../poison.h"
inherit POISON_INH;

void create()
{
	::create();
	add_id(({"blue whinnis"}));	
	set_poison_dc(14);
	set_poison_effect_type(({"constitution"}));
	set_poison_name("blue whinnis");
	set_poison_dice(({1}));
	set_poison_num_dice(({1}));
	set_delivery_method("injury");
	set_poison_base_value(120);
	//set_number_of_effects(3);
}

