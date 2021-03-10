// --==** /cmds/priest/_heal.c **==--
// Modified by Pator@ShadowGate
// August 25 1995
#include <priest.h>

inherit SPELL;

void create()
{
    ::create();
    set_spell_name("shadow healing");
    set_spell_level(([ "bard" : 3, "druid" : 3, "mage" : 3, "cleric" : 3, "magus" : 3 ]));
    set_spell_sphere("illusion");
    set_syntax("cast CLASS shadow healing on TARGET");
    set_description("With this spell you connect your target to the shadow plane, granting them temporary, illusionary health points, but only if they already don't have them.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_casting_time(15);
    set_helpful_spell(1);
}


string query_cast_string()
{
    string cast;
        cast = "%^BLUE%^"+caster->QCN+" folds "+caster->QP+
            " hands as "+caster->QS+" chants the spell!\n";
    return "\n"+cast;
}


spell_effect(int prof)
{
    int rnd;

    // CAST UPON ONESELF
    if (caster == target) {
        tell_object(caster, "%^BLUE%^You reach out and channel energy at yourself.");
        tell_room(place, "%^BLUE%^" + YOU + " reaches out and channels energy at " + caster->QO + "self.", ({ caster, target }));
    }else {
        tell_object(caster, "%^BLUE%^You reach out and channel energy at " + target->QCN + ".");
        tell_room(place, "%^BLUE%^" + YOU + " channels energy at " + target->QCN + ".", ({ caster }));
    }

    rnd = clevel;

    if (target->query_hp() >= target->query_max_hp() + rnd) {
        target->set_hp(rnd + target->query_max_hp());
    } else {
        target->add_extra_hp(rnd);
    }

    dest_effect();
}

void dest_effect()
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
