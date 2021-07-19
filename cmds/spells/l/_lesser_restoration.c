#include <magic.h>

inherit SPELL;

void create()
{
    ::create();
    set_spell_name("lesser restoration");
    set_spell_level(([ "cleric" : 2, "inquisitor": 2, "paladin" : 1, "druid" : 2 ]));
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS lesser restoration on TARGET");
    set_damage_desc("removes one negative status effect");
    set_description("This spell eliminates one status effect on a target at random. It also restores their stamina.

%^BOLD%^%^RED%^See also:%^RESET%^ status effects");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_casting_time(15);
    set_helpful_spell(1);
}

string query_cast_string()
{
    string cast;
    if (interactive(caster))
    {
        cast = ""+caster->QCN+"%^YELLOW%^ folds "+caster->QP+" hands as "+caster->QS+" prays for a divine spell!%^RESET%^\n";
    }
    else
    {
        cast = ""+caster->QCN+"%^YELLOW%^ calls for a divine spell!%^RESET%^\n";
    }
    return "\n"+cast;
}

spell_effect(int prof)
{
    int rnd;

    if (interactive(caster))
    {
        // CAST UPON ONESELF
        if ( caster == target )
        {
            tell_object(caster, "%^BOLD%^%^CYAN%^You chant a restorative blessing at yourself.%^RESET%^");
            tell_room(place, ""+caster->QCN+"%^BOLD%^%^CYAN%^ chants a restorative blessing at "+caster->QO+"self.%^RESET%^", ({ caster, target}) );
        }
        else
        {
            tell_object(caster, "%^BOLD%^%^CYAN%^You chant a restorative blessing at "+target->QCN+".%^RESET%^");
            tell_room(place, ""+caster->QCN+"%^BOLD%^%^CYAN%^ chants a restorative blessing at "+target->QCN+".%^RESET%^",({ caster}) );
        }
    }
    else
    {
        // OBJECT CALLS RESTORATION
        tell_room(environment(caster), ""+caster->QCN+"%^BOLD%^%^CYAN%^ chants a restorative blessing at "+target->QCN+".%^RESET%^",({ caster, target }) );
        tell_object(target, ""+caster->QCN+"%^BOLD%^%^CYAN%^ chants a blessing at you.%^RESET%^");
    }


    tell_object(target,"You feel invigorated and restored as the energy washes over you.");
    tell_room(ENV(target),target->QCN+" looks invigorated and restored.");

    //if(member_array(target,caster->query_attackers())==-1) {
        "/std/magic/cleanse"->lesser_restore(target);
    //}

    target->use_stamina(-target->query_max_stamina()/2);

    dest_effect();
}

void dest_effect()
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
