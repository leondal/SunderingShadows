#include <std.h>
#include <magic.h>
#include "../poison.h"
inherit POISON_INH;

void create()
{
	::create();
	add_id(({"insanity mist"}));	
	set_poison_dc(15);
	set_poison_effect_type(({"wisdom"}));
	set_poison_name("insanity mist");
	set_poison_dice(({1, 2}));
	set_poison_num_dice(({4, 6}));
	set_delivery_method("inhaled");
	set_poison_base_value(1500);
	//set_number_of_effects(3);
}
