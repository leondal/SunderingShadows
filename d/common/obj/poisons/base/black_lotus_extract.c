#include <std.h>
#include <magic.h>
#include "../poison.h"
inherit POISON_INH;

void create()
{
	::create();
	add_id(({"black lotus extract"}));	
	set_poison_dc(20);
	set_poison_effect_type(({"constitution"}));
	set_poison_name("black lotus extract");
	set_poison_dice(({3}));
	set_poison_num_dice(({6}));
	set_delivery_method("contact");
	set_poison_base_value(4500);
}

