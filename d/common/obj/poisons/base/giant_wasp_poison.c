#include <std.h>
#include <magic.h>
#include "../poison.h"
inherit POISON_INH;

void create()
{
	::create();
	add_id(({"giant wasp poison"}));	
	set_poison_dc(18);
	set_poison_effect_type(({"dexterity"}));
	set_poison_name("giant wasp poison");
	set_poison_dice(({1}));
	set_poison_num_dice(({6}));
	set_delivery_method("injury");
	set_poison_base_value(210);
	//set_number_of_effects(3);
}

int ProcessEffect(object vic, int WhichEffect, int DC)
{
	int dam;
	if(!objectp(TO)) return 0;
	if(!objectp(vic)) return 0;
	dam = TO->query_poison_damage(WhichEffect);
	if((int)TO->PoisonSave(vic, DC, TO->query_saving_throw(WhichEffect)))
	{
		tell_object(vic, "%^BOLD%^%^RED%^You resist the "+
		"effects of the "+TO->query_poison_name()+"!%^RESET%^");
		return 0;			
	}
	tell_object(vic, "%^BOLD%^%^RED%^The "+TO->query_poison_name()+
	" eats away are your "+TO->query_effect_type(WhichEffect)+"!%^RESET%^");
	
	if((string)TO->query_effect_type(WhichEffect) == "life")
	{
		vic->cause_typed_damage(vic,vic->return_target_limb(),dam,PoisonDamageType);		
	}
	return dam;	
}	