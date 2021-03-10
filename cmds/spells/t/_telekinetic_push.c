// Mind Thrust
// ~Circe~ 7/19/05
#include <spell.h>
inherit SPELL;

void create() {
    ::create();
    set_spell_name("telekinetic push");
    set_spell_level(([ "mage" : 5, "oracle" : 5, "psion" : 3 ]));
    set_mystery("ancestor");
    set_spell_sphere("alteration");
    set_syntax("cast CLASS telekinetic push on TARGET");
    set_damage_desc("force, prone");
    set_description("You push someone with force of your magic, harming them and kicking them prone. A strong willed opponent may remain standing and negate half of the damage.");
    set_verbal_comp();
    set_somatic_comp();
    set_save("will");
    set_target_required(1);
    set_silent_casting(1);
}

spell_effect(int prof)
{
    int dam = sdamage;
    spell_successful();
    if (interactive(caster)) {
        tell_object(caster,"%^BOLD%^%^WHITE%^You extend you hand in direction of "+target->QCN+", pushing them with force!");
        tell_room(place,"%^BOLD%^%^WHITE%^"+caster->QCN+" extends "+caster->QP+" hand in direction of "+target->QCN+" and pushes them with waves of force!", ({caster}) );
    }

    if (!do_save(target, 0)) {
        tell_room(place, "%^BOLD%^%^WHITE%^" + target->QCN + " falls to the ground!", target);
        tell_object(target, "%^BOLD%^%^WHITE%^You fall to the ground!");
        target->set_prone(roll_dice(1, 4), "You're trying to get back on your feet!");
    }else {
        dam /= 2;
    }
    tell_object(target,"%^BOLD%^%^WHITE%^Force of the push curshes you!");
    damage_targ(target, target->return_target_limb(), dam,"force");
    dest_effect();
}
