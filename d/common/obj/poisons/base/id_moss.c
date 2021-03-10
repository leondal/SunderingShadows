#include <std.h>
#include <magic.h>
#include "../poison.h"
inherit POISON_INH;

void create()
{
	::create();
	add_id(({"id moss"}));	
	set_poison_dc(14);
	set_poison_effect_type(({"intelligence"}));
	set_poison_name("id moss");
	set_poison_dice(({1, 2}));
	set_poison_num_dice(({4, 6}));
	set_delivery_method("ingested");
	set_poison_base_value(125);
	//set_number_of_effects(3);
}
