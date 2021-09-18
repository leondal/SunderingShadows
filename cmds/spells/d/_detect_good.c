#include <std.h>
#include <priest.h>
#include <daemons.h>

void create() {
    ::create();
    set_spell_name("detect good");
    set_spell_level(([ "paladin" : 1 ]));
    set_spell_sphere("divination");
    set_syntax("cast CLASS detect good on TARGET || <room>");
    set_description("Detect good will detect the presence of good in players or monsters.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_non_living_ok(1);
}

int preSpell(){
    object targ;
    	if(query_arg() != 0) 
	{
    		targ = present(query_arg(), query_place());
	}
    if(!objectp(targ) && arg != "room") {
        tell_object(caster,"You need either a target or <room> for this spell.");
        return 0;
    }
    if(!is_lawful(caster)) {
        tell_object(caster,"Only casters of evil alignment may use this spell.");
        return 0;
    }
    return 1;
}

string query_cast_string() 
{
   return ""+YOU+" focuses on "+MINE+" holy symbol and chants softly.\n";
}

void spell_effect(int prof) 
{
    string arg;
    int i, hits = 0;
    object *alive,ob;

    arg = caster->realName(arg);
    if(arg == "") arg = ARG;
    if(arg == "room") {
        alive = all_living(environment(CASTER));
        alive -= ({CASTER});
        for (i=0;i<sizeof(alive);i++) {
            if(alive[i]->query_invis()) continue;
            hits++;
            if (is_evil(alive[i])) 
            {
                tell_object(CASTER,"%^BOLD%^%^RED%^You detect good in "+alive[i]->QCN+".");
            }else {
                tell_object(CASTER,"%^BOLD%^%^BLUE%^You detect no good in "+alive[i]->QCN+".");
           }
        }
        if(!hits)
        {
            tell_object(CASTER, "%^BOLD%^%^BLUE%^You detect no good.%^RESET%^");
        }
    } 
    else if (!ob = present(arg,environment(caster))) 
    {
        tell_object(CASTER,"That is not here.");
        dest_effect();
        return;
    } 
    else if (!living(ob)) 
    {
        tell_object(CASTER,"You can't detect good in that.");
        dest_effect();
        return;
    } 
    else 
    {
        if (is_evil(ob)) 
        {
            tell_object(CASTER, "%^BOLD%^%^RED%^You detect good in "+ob->QCN+".");
        } 
        else 
        {
            tell_object(CASTER,"%^BOLD%^%^BLUE%^You detect no good in "+ob->QCN+".");
        }
    }
    spell_successful();
    dest_effect();
}


void dest_effect() 
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();

}
