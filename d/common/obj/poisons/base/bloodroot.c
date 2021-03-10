#include <std.h>
#include <magic.h>
#include "../poison.h"
inherit POISON_INH;

void create()
{
	::create();
	add_id(({"bloodroot"}));	
	set_poison_dc(12);
	set_poison_effect_type(({"0","constitution", "wisdom"}));
	set_poison_name("bloodroot");
	set_poison_dice(({1, 1, 1}));
	set_poison_num_dice(({2, 4, 3}));
	set_delivery_method("injury");
	set_poison_base_value(100);
	set_number_of_effects(3);
}

int ProcessEffect(object vic, int WhichEffect, int DC)
{
	int dam;
	if(!objectp(TO)) return 0;
	if(!objectp(vic)) return 0;
	if(WhichEffect == 1) return 0;
	dam = TO->query_poison_damage(WhichEffect);
	if((int)TO->PoisonSave(vic, DC, TO->query_saving_throw(WhichEffect)))
	{
		TO->base_message(vic, 1, WhichEffect);
		return 0;			
	}
	TO->base_message(vic, 0, WhichEffect);
	
	if((string)TO->query_effect_type(WhichEffect) == "life")
	{
		vic->cause_typed_damage(vic,vic->return_target_limb(),dam,PoisonDamageType);		
	}
	return dam;	
}	