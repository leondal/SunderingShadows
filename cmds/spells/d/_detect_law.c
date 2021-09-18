#include <std.h>
#include <priest.h>
#include <daemons.h>

void create() {
    ::create();
    set_spell_name("detect law");
    set_spell_level(([ "cleric" : 1 ]));
    set_spell_sphere("divination");
    set_syntax("cast CLASS detect law on TARGET || <room>");
    set_description("Detect chaos will detect the presence of law in players or monsters.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_non_living_ok(1);
}

int preSpell() {
    object targ;
    targ = present(query_arg(), query_place());
    if(!objectp(targ) && arg != "room") {
        tell_object(caster,"You need either a target or <room> for this spell.");
        return 0;
    }
    if(!is_chaotic(caster)) {
        tell_object(caster,"Only casters of chaotic alignment may use this spell.");
        return 0;
    }
    return 1;
}

string query_cast_string() 
{
    return "%^BOLD%^%^GREEN%^"+YOU+" focuses on "+MINE+" holy symbol and chants softly.\n";
}

void spell_effect(int prof) 
{
    string arg;
    int i, hits = 0;
    object *alive,ob;

    arg = caster->realName(arg);
    if(arg == "") arg = ARG;
    if(arg == "room") 
    {
        alive = all_living(environment(CASTER));
        for (i=0;i<sizeof(alive);i++) 
        {
            if (is_lawful(alive[i]) && !alive[i]->query_invis()) 
            {
                hits ++;
                tell_object(caster,"%^BOLD%^%^GREEN%^You detect law in "+alive[i]->QCN+".");
            }
            continue;
        }
        if(!hits)
        {
            tell_object(caster,"%^BOLD%^%^YELLOW%^You detect no law.%^RESET%^");
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
        tell_object(CASTER,"You can't detect law in that.");
        dest_effect();
        return;
    } 
    else 
    {
        if (is_lawful(ob)) 
        {
            tell_object(caster, "%^BOLD%^%^GREEN%^You detect law in "+ob->QCN+".");
        } 
        else 
        {
            tell_object(caster,"%^BOLD%^%^YELLOW%^You detect no law in "+ob->QCN+".");
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