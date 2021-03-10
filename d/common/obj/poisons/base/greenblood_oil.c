#include <std.h>
#include <magic.h>
#include "../poison.h"
inherit POISON_INH;

void create()
{
	::create();
	add_id(({"greenblood oil"}));	
	set_poison_dc(13);
	set_poison_effect_type(({"constitution"}));
	set_poison_name("greenblood oil");
	set_poison_dice(({1, 1}));
	set_poison_num_dice(({1, 2}));
	set_delivery_method("injury");
	set_poison_base_value(100);
	//set_number_of_effects(3);
}

