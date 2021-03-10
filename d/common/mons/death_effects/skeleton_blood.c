#include <std.h>
#include <daemons.h>
#include "death_effects.h"
inherit EFFECT_BASE;
int effectHits;
void effectDamage();
object __effectWhere;

void create() 
{
	::create();
    	set_name("a skeleton summons");

	set_short("a skeleton summons");

	set_id(({"skeleton mon"}));

	set_long("%^BOLD%^a skeleton summoner");

	set_effect_type("undead");

	set_environment_required(0);

	effectHits = 0;	
}

void effectDamage()
{
	object mon;
	string myrace, origin, skel_str;
	int lev, x;
	if(!objectp(TO)) return;
	if(!objectp(__effectWhere)) return;
	lev = (int)TO->query_effect_level();
	x = lev / 12;

	if(x < 1) x = 1;
	if(x > 10) x = 10;
	origin = TO->query_effect_origin();
	if(x == 1) skel_str = "a %^BOLD%^%^WHITE%^skeleton%^BOLD%^%^RED%^ rises";
	else skel_str = x+" %^BOLD%^%^WHITE%^skeletons%^BOLD%^%^RED%^ rise";

	tell_room(__effectWhere, "%^BOLD%^%^RED%^Animated by the blood "+
	"of "+origin+" "+skel_str+ " up from the ground!%^RESET%^");

	while(x) 
	{
		mon = new(CMONS+"skeleton");
		mon->scale_to(lev);
		mon->move(__effectWhere);		
		x--;	
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
	tell_room(where, "%^BOLD%^%^RED%^Blood splashes out from the corpse of "+
	origin+"%^BOLD%^%^RED%^ and saturates the ground here!%^RESET%^");
	effectHits = (int)TO->query_effect_level() / 10;
	__effectWhere = where;
	if(effectHits < 1) effectHits = 1;
	effectDamage();
	return;
}