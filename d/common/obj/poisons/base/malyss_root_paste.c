#include <std.h>
#include <magic.h>
#include "../poison.h"
inherit POISON_INH;

void create()
{
	::create();
	add_id(({"malyss root paste"}));	
	set_poison_dc(16);
	set_poison_effect_type(({"dexterity"}));
	set_poison_name("malyss root paste");
	set_poison_dice(({1, 2}));
	set_poison_num_dice(({1, 4}));
	set_delivery_method("contact");
	set_poison_base_value(500);
}

