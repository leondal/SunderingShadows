// Modified by PAtor@ShadowGate
// August 25 1995

#include <priest.h>
#include <daemons.h>
inherit SPELL;

void create() {
    ::create();
    set_spell_name("sense poison");
    set_spell_level(([ "psion" : 1 ]));
    set_spell_sphere("clairsentience");
    set_syntax("cast CLASS sense poison on TARGET");
    set_description("Will detect if any poisons are present on an "+
	"object or a creature and if so, which poisons.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_non_living_ok(1);
    set_helpful_spell(1);
}

string query_cast_string() {
   return ""+YOU+" focuses on "+MINE+" psionic powers.\n";
}

void DoPoisonDisplay(mixed poison)
{
	int x, lvl;
	string *pnames, info;
	info = TARGET->QCN + " %^BOLD%^%^GREEN%^is affected by the "+
	"following";
	pnames = keys(poison);
	lvl = CASTER->query_level() + roll_dice(1,20);
	if(sizeof(pnames) > 1) info += " poisons:\n\n";
	else info += " poison:\n\n";
	for(x = 0;x < sizeof(pnames);x++)
	{
		info += "%^BOLD%^%^GREEN%^" + capitalize(pnames[x]);
		info += "%^BOLD%^%^WHITE%^ ( %^BOLD%^%^RED%^";
		if(lvl >= poison[pnames[x]]["DC"]) 
		{
			info += poison[pnames[x]]["TrueInfo"];
		}
		else info += poison[pnames[x]]["Info"];
		info += "%^BOLD%^%^WHITE%^ )%^RESET%^";
		info += "\n";
		continue;
	}
	tell_object(CASTER, info);
	return;
}

void spell_effect(int prof) 
{
	int x;
	mixed poison;
	
	poison = POISON_D->query_poisons_affecting(TARGET);

    // interactive calls detect poison
    if (interactive(CASTER)) 
	{
      	if (mapp(poison)) 
	  	{
			DoPoisonDisplay(poison);	
			//DoPoisonDisplay();		
            	tell_room(PLACE, YOU+" senses poison in the area.",CASTER);
			if(interactive(TARGET))
			{
                tell_object(TARGET,YOU+" sniffed and found interesting smells on you.");
			}
        } 
		else 
		{
            tell_object(CASTER,"You sense no poison in "+HIM+".");
            tell_room(PLACE,YOU+" senses no poison in the area.",CASTER);
			if(interactive(TARGET)) 
			{
            		tell_object(TARGET,YOU+" sniffed and found nothing of interest on you.");
			}
        }
    }
    // object calls detect poison
    else 
	{
        if (mapp(poison)) 
		{
            DoPoisonDisplay(poison);	
            tell_room(PLACE,YOU+" senses poison in the area.");
            if(interactive(TARGET)) 
            {
	            tell_object(TARGET,YOU+" sniffed and found interesting smells on you.");
            } 
        } 
        else 
        {
            tell_room(PLACE,YOU+" senses no poison in the area.");
            if(interactive(TARGET)) 	
            {
                tell_object(TARGET,YOU+" sniffed and found nothing of interest on you.");
            }
        }
    }
    spell_successful();
    dest_effect();
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();

}
