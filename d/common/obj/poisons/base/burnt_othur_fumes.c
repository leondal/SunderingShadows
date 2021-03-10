#include <std.h>
#include <magic.h>
#include "../poison.h"
inherit POISON_INH;

void create()
{
	::create();
	add_id(({"burnt othur fumes"}));	
	set_poison_dc(18);
	set_poison_effect_type(({"constitution"}));
	set_poison_name("burnt othur fumes");
	set_poison_dice(({1, 3}));
	set_poison_num_dice(({1, 6}));
	set_delivery_method("inhaled");
	set_poison_base_value(2100);
	//set_number_of_effects(3);
}
