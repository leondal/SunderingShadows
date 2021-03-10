#include <std.h>
#include <magic.h>
#include "../poison.h"
inherit POISON_INH;

void create()
{
	::create();
	add_id(({"sassone leaf residue"}));	
	set_poison_dc(16);
	set_poison_effect_type(({"life", "constitution"}));
	set_poison_name("sassone leaf residue");
	set_poison_dice(({12, 6}));
	set_poison_num_dice(({2, 1}));
	set_delivery_method("contact");
	set_poison_base_value(300);
}

