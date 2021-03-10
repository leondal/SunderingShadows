#include <std.h>
#include <magic.h>
#include "../poison.h"
inherit POISON_INH;

void create()
{
	::create();
	add_id(({"striped toadstool"}));	
	set_poison_dc(11);
	set_poison_effect_type(({"wisdom", "wisdom", "intelligence"}));
	set_poison_name("striped toadstool");
	set_poison_dice(({1, 2, 1}));
	set_poison_num_dice(({1, 6, 4}));
	set_delivery_method("ingested");
	set_poison_base_value(180);
	set_number_of_effects(3);
}

