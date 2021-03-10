// mist of the goddess
#include <priest.h>

inherit SPELL;

void create() {
    ::create();
    set_author("ares");
    set_spell_name("mist of the goddess");
    set_spell_level(([ "classless" : 5 ]));
    set_spell_sphere("elemental water");
    set_spell_domain("water");
    set_syntax("cast CLASS mist of the goddess on TARGET");
    set_description("This spell will send a cleansing mist into the target and remove all poisons and toxins from them as "
"well as quench their thirst and heal them a small amount and restore a small amount of stamina.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
	set_helpful_spell(1);
}

int preSpell()
{
    if(!objectp(target))
    {
        tell_object(caster,"This spell requires a target.");
        return 0;
    }
    return 1;
}

string query_cast_string()
{
    tell_object(caster,"%^CYAN%^%^Mist gathers around your hand, as you whirl"+
        " it through a complex gesture.");
    tell_room(place,"%^CYAN%^As "+caster->QCN+" works "+caster->QP+" hand"+
        " through a complex gesture, mist begins to gather around"+
        " "+caster->QO+".",caster);
    return "display";
}

void spell_effect(int prof)
{
    int tmp;
    if(!present(target,place))
    {
        tell_object(caster,"Your target has left the area.");
        dest_effect();
        return;
    }
	if(target == caster)
    {
        tell_room(place,"%^BOLD%^%^CYAN%^"+caster->QCN+" cloaks "+
            ""+caster->QS+"self in the cleansing mist.",target);
        tell_object(target, "%^BOLD%^%^CYAN%^You wrap the mist around"+
            " yourself, feeling it purifying and refreshing you.");
    }
    else
    {
        tell_object(caster,"%^CYAN%^%^BOLD%^Calling upon the purifying power of water,"+
            " you wrap "+target->QCN+" in the mist.");
        tell_object(target,"%^BOLD%^%^CYAN%^"+caster->QCN+" wraps you in the "+
            "refreshing mist.  You feel purified and cleansed!");
        tell_room(place,"%^BOLD%^%^CYAN%^"+caster->QCN+" wraps "+target->QCN+" in"+
            " the cleansing mist.",({target,caster}));
    }
    damage_targ(target, "torso", clevel, "positive energy");
    target->add_quenched(10000);
    //target->add_poisoning(-1*(int)target->query_poisoning());
	POISON_D->clear_poisons_by_dc(target, 1000, 0); //should clear all poisons this way - Saide
    target->add_intox(-1*(int)target->query_intox());
    // this is a pain, since if they go over, they'll pass out
    if(target->query_condition() < target->query_max_stamina())
    {
        tmp = 2 * ((int)target->query_max_stamina() - (int)target->query_condition());
        if(tmp > 25) { tmp = 25; }
        target->use_stamina(-1*tmp);
    }
    spell_successful();
    dest_effect();
}

void dest_effect()
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
