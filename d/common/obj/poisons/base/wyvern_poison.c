#include <std.h>
#include <magic.h>
#include "../poison.h"
inherit POISON_INH;

void create()
{
	::create();
	add_id(({"wyvern poison"}));	
	set_poison_dc(17);
	set_poison_effect_type(({"constitution"}));
	set_poison_name("wyvern poison");
	set_poison_dice(({2, 2}));
	set_poison_num_dice(({6, 6}));
	set_delivery_method("injury");
	set_poison_base_value(3000);
	//set_number_of_effects(3);
}

