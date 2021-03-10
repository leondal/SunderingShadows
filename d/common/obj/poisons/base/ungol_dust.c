#include <std.h>
#include <magic.h>
#include "../poison.h"
inherit POISON_INH;

void create()
{
	::create();
	add_id(({"ungol dust"}));	
	set_poison_dc(15);
	set_poison_effect_type(({"charisma"}));
	set_poison_name("ungol dust");
	set_poison_dice(({1, 1, 1}));
	set_poison_num_dice(({1, 6, 1}));
	set_delivery_method("inhaled");
	set_poison_base_value(1000);
	set_number_of_effects(3);
}

