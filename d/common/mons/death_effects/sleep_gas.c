#include <std.h>
#include <daemons.h>
#include "death_effects.h"
inherit EFFECT_BASE;
int effectHits;
void effectDamage();

void create() 
{
	::create();
    	set_name("a thick cloud of blue smoke");

	set_short("%^BOLD%^%^WHITE%^a thick cloud of %^BOLD%^%^BLUE%^"+
	"blue%^BOLD%^%^WHITE%^ smoke%^RESET%^");

	set_id(({"gas", "cloud of smoke", "blue cloud", "cloud", "smoke"}));

	set_long("%^BOLD%^%^BLUE%^This thick cloud of blue "+
	"smoke hangs heavily over everything here.  It is very difficult "+
	"to breath.%^RESET%^");

	set_effect_type("gas");
	effectHits = 0;	
}

void effectDamage()
{
	string myrace;
	object *vics;
	int x, dam;
	if(!objectp(TO)) return;
	if(!objectp(ETO)) return;
	vics = filter_array(all_living(ETO), "is_non_immortal", FILTERS_D);
	vics -= ({TO->query_origin_object()});
	dam = (int)TO->query_effect_level();
	dam = dam / 5;
	if(dam < 2) dam = 2;
	if(dam > 20) dam = 20;
	for(x = 0;x < sizeof(vics);x++)
	{
		if(!objectp(vics[x])) continue;
		myrace = (string)vics[x]->query_race();

		if("/daemon/saving_throw_d"->fort_save(vics[x], 0 - dam) ||
		myrace == "elf" || myrace == "drow" || myrace == "half-elf" ||
		myrace == "half-drow")
		{
			tell_object(vics[x], "%^BOLD%^%^WHITE%^You inhale the "+
			"%^BOLD%^%^BLUE%^blue smoke%^BOLD%^%^WHITE%^ but "+
			"it doesn't seem to affect you at all.%^RESET%^");
		
			tell_room(ETO, vics[x]->QCN + "%^BOLD%^%^WHITE%^ inhales "+
			"the %^BOLD%^%^BLUE%^blue smoke%^BOLD%^%^WHITE%^ but "+
			"doesn't seem to be affected at all.%^RESET%^", vics[x]);

			continue;
		}

		tell_object(vics[x], "%^BOLD%^%^WHITE%^You inhale the "+
		"%^BOLD%^%^BLUE%^blue smoke%^BOLD%^%^WHITE%^ and suddenly "+
		"fall into a deep restless sleep!%^RESET%^");

		tell_room(ETO, vics[x]->QCN+"%^BOLD%^%^WHITE%^ inhales the "+
		"%^BOLD%^%^BLUE%^blue smoke%^BOLD%^%^WHITE%^ and suddenly "+
		"falls into a deep sleep!%^RESET%^", vics[x]);
		
		vics[x]->set_asleep(dam, "%^BOLD%^%^BLUE%^You are in a deep "+
		"restless sleep!%^RESET%^");
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
		tell_room(ETO, "%^BOLD%^%^WHITE%^The thick cloud of %^BOLD%^%^BLUE%^"+
		"blue smoke%^BOLD%^%^WHITE%^ dissipates!%^RESET%^");
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
	tell_room(where, "%^BOLD%^%^BLUE%^A thick cloud of blue smoke "+
	"rolls out from the corpse of "+origin+"%^BOLD%^%^BLUE%^!%^RESET%^");
	TO->move(where);
	effectHits = (int)TO->query_effect_level() / 20;
	if(effectHits < 1) effectHits = 1;
	effectDamage();
	return;
}