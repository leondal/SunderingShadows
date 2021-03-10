#include <std.h>
#include <daemons.h>
#include "death_effects.h"
inherit EFFECT_BASE;
int effectHits;
void effectDamage();

void create() 
{
	::create();
    	set_name("a noxious cloud of gas");
	set_short("%^BOLD%^%^GREEN%^a noxious cloud of gas%^RESET%^");
	set_id(({"gas", "cloud of gas", "noxious cloud", "cloud"}));
	set_long("%^BOLD%^%^GREEN%^This thick cloud of noxious "+
	"gas hangs heavily over everything here.  It is very difficult "+
	"to breath.%^RESET%^");
	set_effect_type("gas");
	effectHits = 0;	
}

void effectDamage()
{
	object *vics;
	int x, dam;
	if(!objectp(TO)) return;
	if(!objectp(ETO)) return;
	vics = filter_array(all_living(ETO), "is_non_immortal", FILTERS_D);
	vics -= ({TO->query_origin_object()});
	dam = (int)TO->query_effect_level();
	for(x = 0;x < sizeof(vics);x++)
	{
		if(!objectp(vics[x])) continue;
		if("/daemon/saving_throw_d"->fort_save(vics[x], 0 - dam))
		{
			tell_object(vics[x], "%^BOLD%^%^BLACK%^You cough and choke "+
			"on the %^BOLD%^%^GREEN%^noxious%^BOLD%^%^BLACK%^ gas "+
			"but manage to avoid most of its effect.%^RESET%^");
			
			tell_room(ETO, vics[x]->QCN + "%^BOLD%^%^BLACK%^ coughs and "+
			"chokes on the %^BOLD%^%^GREEN%^noxious%^BOLD%^%^BLACK%^ gas "+
			"but seems to avoid most of its effect.%^RESET%^", vics[x]);
			
			vics[x]->do_damage(vics[x]->return_target_limb(), (roll_dice(dam, 4)/2));
			continue;
		}
		tell_object(vics[x], "%^BOLD%^%^BLACK%^You cough and choke "+
		"on the %^BOLD%^%^GREEN%^noxious%^BOLD%^%^BLACK%^ gas as "+
		"it seeps deep into your lungs!%^RESET%^");
	
		tell_room(ETO, vics[x]->QCN+"%^BOLD%^%^BLACK%^ coughs and chokes "+
		"on the %^BOLD%^%^GREEN%^noxious%^BOLD%^%^BLACK%^ gas!"+
		"%^RESET%^", vics[x]);
		
		vics[x]->do_damage(vics[x]->return_target_limb(), roll_dice(dam, 4));
		vics[x]->set_paralyzed(4, "%^BOLD%^%^GREEN%^You cough and choke "+
		"on the noxious gas!%^RESET%^");
		continue;
	}
	effectHits--;
	if(effectHits) 
	{
		call_out("effectDamage", 6);
		return;
	}
	else 
	{
		tell_room(ETO, "%^BOLD%^%^GREEN%^The noxious cloud of gas "+
		"dissipates!%^RESET%^");
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
	tell_room(where, "%^BOLD%^%^GREEN%^A thick cloud of noxious gas "+
	"rolls out from the corpse of "+origin+"%^BOLD%^%^GREEN%^!%^RESET%^");
	TO->move(where);
	effectHits = (int)TO->query_effect_level() / 10;
	if(effectHits < 1) effectHits = 1;
	effectDamage();
	return;
}