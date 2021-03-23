#include <std.h>

inherit SPELL;

void dest_effect();

void create()
{
    ::create();
    set_spell_name("thorn spray");
    set_spell_level(([ "cleric" : 6, "druid" : 6]));
    set_domains("plant");
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS thorn spray on TARGET");
    set_description("This spell will cause a number of sharp thorns to fly from the caster's hand toward the target.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
}

void spell_effect(int prof)
{
    int num, numdarts, i;

    numdarts = sdamage;

    tell_object(caster, "%^ORANGE%^Sharp thorns shoot from your hand at " + target->QCN + "!");
    tell_object(target, "%^ORANGE%^Sharp thorns shoot from " + caster->QCN + "'s hand at you!");
    tell_room(place, "%^ORANGE%^Sharp thorns shoot from " + caster->QCN + "'s hand at " + target->QCN + "!", ({ caster, target }));

    damage_targ(target, target->return_target_limb(), numdarts, "piercing");
    spell_kill(target, caster);
    dest_effect();
}

void dest_effect()
{
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
