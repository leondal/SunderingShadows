#include <std.h>
#include <magic.h>
#include "../poison.h"
inherit POISON_INH;

void create()
{
	::create();
	add_id(({"niltharit"}));	
	set_poison_dc(13);
	set_poison_effect_type("constitution");
	set_poison_name("niltharit");
	set_poison_dice(6);
	set_poison_num_dice(3);
	set_delivery_method("contact");
	set_poison_base_value(650);
}

int ProcessEffect(object vic, int WhichEffect, int DC)
{
	if(!objectp(TO)) return 0;
	if(WhichEffect != 2) return 0;
	if(!(int)TO->PoisonSave(vic, DC, TO->query_saving_throw(WhichEffect)))
	{
		TO->base_message(vic, 0, WhichEffect);	
		return (int)TO->query_poison_damage();
	}
	TO->base_message(vic, 1, WhichEffect);	
	return 0;
}	