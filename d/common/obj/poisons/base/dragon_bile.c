#include <std.h>
#include <magic.h>
#include "../poison.h"
inherit POISON_INH;

void create()
{
	::create();
	add_id(({"dragon bile"}));	
	set_poison_dc(26);
	set_poison_effect_type(({"strength"}));
	set_poison_name("dragon bile");
	set_poison_dice(({3}));
	set_poison_num_dice(({6}));
	set_delivery_method("contact");
	set_poison_base_value(1500);
	set_number_of_effects(1);
}

