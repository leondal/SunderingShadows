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
    	set_name("a maggot summons");

	set_short("a maggot summons");

	set_id(({"maggot summoner"}));

	set_long("%^BOLD%^a maggot summoner");

	set_effect_type("undead");

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

	if(x < 2) x = 2;
	if(x > 10) x = 10;

	tell_room(__effectWhere, "%^BOLD%^%^GREEN%^A sickening squishy "+
	"sound echoes here as some giant %^RESET%^%^ORANGE%^bloated maggots"+
	"%^BOLD%^%^GREEN%^ crawl out of the remains of "+TO->query_effect_origin()+
	"%^RESET%^");

	while(x) 
	{
		mon = new(CMONS+"maggot");
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
	tell_room(where, "%^RESET%^%^GREEN%^The corpse of "+origin+
	" bursts open and giant %^RESET%^%^ORANGE%^bloated maggots%^RESET%^"+
	"%^GREEN%^ begin crawling out!%^RESET%^");

	effectHits = (int)TO->query_effect_level() / 10;
	__effectWhere = where;
	if(effectHits < 1) effectHits = 1;
	effectDamage();
	return;
}