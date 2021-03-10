#include <std.h>
#include <magic.h>
#include "../poison.h"
inherit POISON_INH;

void create()
{
	::create();
	add_id(({"small centipede venom"}));	
	set_poison_dc(11);
	set_poison_effect_type(({"dexterity"}));
	set_poison_name("small cendipede venom");
	set_poison_dice(({1}));
	set_poison_num_dice(({2}));
	set_delivery_method("injury");
	set_poison_base_value(90);
	//set_number_of_effects(3);
}

