#include <spell.h>
inherit SPELL;

void create()
{
    ::create();
    set_spell_name("snowball");
    set_spell_level(([ "mage" : 1, "druid":1]));
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS snowball on TARGET");
    set_damage_desc("bludgeoning, tripping");
    set_description("You create a small snowball and forcefully project it on target. If hit successfully it will stagger opponents for a brief moment.");
    set_save("fort");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
}
string query_cast_string()
{
    return "%^BOLD%^%^WHITE%^" + caster->QCN + " chants sonorously, dust forms in front of them into a small ball of snow.%^RESET%^";
}

spell_effect(int prof)
{
    int dam = sdamage;
    spell_successful();
    if (interactive(caster)) {
        tell_object(caster, "%^BOLD%^%^WHITE%^You project the snowball into direction of " + target->QCN + "!");
        tell_room(place, "%^BOLD%^%^WHITE%^" + caster->QCN + " forcefully projects the snowball at " + target->QCN + "!", ({ caster }));
    }
    if(do_save(target, 0))
    {
        dam /= 2;
    }
    else
    {
        target->set_tripped(1, "You are staggered byt the painfully thrown snoball!");
    }
    damage_targ(target, target->return_target_limb(), dam, "bludgeoning");
    TO->dest_effect();
}

void dest_effect()
{
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
