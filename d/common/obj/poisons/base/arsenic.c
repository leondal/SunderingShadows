#include <std.h>
#include <magic.h>
#include "../poison.h"
inherit POISON_INH;

void create()
{
	::create();
	add_id(({"arsenic"}));	
	set_poison_dc(13);
	set_poison_effect_type(({"constitution"}));
	set_poison_name("arsenic");
	set_poison_dice(({1, 1}));
	set_poison_num_dice(({1, 8}));
	set_delivery_method("ingested");
	set_poison_base_value(120);
	//set_number_of_effects(2);
}
