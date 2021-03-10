#include <std.h>
#include <magic.h>
#include "../poison.h"
inherit POISON_INH;

void create()
{
	::create();
	add_id(({"terinav root"}));	
	set_poison_dc(16);
	set_poison_effect_type(({"dexterity"}));
	set_poison_name("terinav root");
	set_poison_dice(({1, 2}));
	set_poison_num_dice(({6, 6}));
	set_delivery_method("contact");
	set_poison_base_value(750);
}
