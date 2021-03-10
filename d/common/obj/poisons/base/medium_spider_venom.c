#include <std.h>
#include <magic.h>
#include "../poison.h"
inherit POISON_INH;

void create()
{
	::create();
	add_id(({"medium spider venom"}));	
	set_poison_dc(14);
	set_poison_effect_type(({"strength"}));
	set_poison_name("medium spider venom");
	set_poison_dice(({1, 1}));
	set_poison_num_dice(({4, 4}));
	set_delivery_method("injury");
	set_poison_base_value(150);
	//set_number_of_effects(3);
}
