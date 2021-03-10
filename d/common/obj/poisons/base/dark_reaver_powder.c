#include <std.h>
#include <magic.h>
#include "../poison.h"
inherit POISON_INH;

void create()
{
	::create();
	add_id(({"dark reaver powder"}));	
	set_poison_dc(18);
	set_poison_effect_type(({"constitution", "constitution", "strength"}));
	set_poison_name("dark reaver powder");
	set_poison_dice(({2, 1, 1}));
	set_poison_num_dice(({6, 6, 6}));
	set_delivery_method("ingested");
	set_poison_base_value(300);
	set_number_of_effects(3);
}
