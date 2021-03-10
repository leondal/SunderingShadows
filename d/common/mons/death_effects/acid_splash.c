#include <std.h>
#include <daemons.h>
#include "death_effects.h"
inherit EFFECT_BASE;
object *__effectVictims, __effectWhere;
int effectHits;
void effectDamage();

void create() 
{
	::create();
    	set_name("acid splash");

	set_short("%^RESET%^%^GREEN%^an acid splash%^RESET%^");

	set_id(({"acid", "splash", "acid splash"}));

	//players should never see this so meh :P
	set_long("%^RESET%^%^GREEN%^A thick splash of acid.");

	set_effect_type("splash");

	effectHits = 0;	
	__effectVictims = ({});
}

void effectDamage()
{
	object *vics, env, *vics_to_remove;
	int x, dam, flag;	
	if(!objectp(TO)) return;
	if(!objectp(__effectWhere)) return;
	if(!sizeof(__effectVictims)) 
	{
		vics = filter_array(all_living(__effectWhere), "is_non_immortal", FILTERS_D);
		vics -= ({TO->query_origin_object()});
	}
	else
	{
		vics = __effectVictims;
		__effectVictims = ({});
		flag = 1;
	}
	vics_to_remove = ({});
	dam = (int)TO->query_effect_level() / 4;

	if(dam < 4) dam = 4;
	if(dam > 20) dam = 20;

	for(x = 0;x < sizeof(vics);x++)
	{
		if(!objectp(vics[x])) continue;
		if(flag == 1)
		{
			env = environment(vics[x]);
		}
		else env = __effectWhere;
		if(!objectp(env)) continue;

		tell_object(vics[x], "%^RESET%^%^GREEN%^You are burned by "+
		"the acid!%^RESET%^");	

		tell_room(env, vics[x]->QCN+"%^RESET%^%^GREEN%^ is burned by "+
		"acid!%^RESET%^", vics[x]);

		if("/daemon/saving_throw_d"->fort_save(vics[x], 0 - dam))
		{
			vics_to_remove += ({vics[x]});
			vics[x]->do_damage(vics[x]->return_target_limb(), roll_dice((dam/2), 10));
			continue;						
		}
		if(!flag) 
		{
			__effectVictims += ({vics[x]});
		}
		vics[x]->do_damage(vics[x]->return_target_limb(), roll_dice(dam, 10));		
		continue;
	}

	effectHits--;

	if(sizeof(vics_to_remove))
	{
		tell_object(vics_to_remove, "%^BOLD%^%^GREEN%^The burning of the acid "+
		"ceases!%^RESET%^");
	}
	__effectVictims -= vics_to_remove;

	if(effectHits && sizeof(__effectVictims)) 
	{
		call_out("effectDamage", 6);
		return;
	}

	else 
	{
		TO->remove();
	}	
}

void startEffect(object where)
{
	string origin;
	if(!objectp(TO)) return;
	origin = TO->query_effect_origin();
	if(!objectp(where) && !stringp(origin)) 
	{
		TO->remove();
		return;
	}

	tell_room(where, "%^RESET%^%^GREEN%^Acid splashes out "+
	"from the corpse of "+origin+"%^RESET%^%^GREEN%^ and "+
	"saturates you!%^RESET%^");

	__effectWhere = where;

	effectHits = (int)TO->query_effect_level() / 10;
	if(effectHits < 1) effectHits = 1;
	effectDamage();
	return;
}