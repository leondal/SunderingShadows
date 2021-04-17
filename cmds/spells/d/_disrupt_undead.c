// Mind Thrust
// ~Circe~ 7/19/05
#include <spell.h>
inherit SPELL;

void create() {
    ::create();
    set_spell_name("disrupt undead");
    set_spell_level(([ "cantrip" : 1 ]));
    set_spell_sphere("necromancy");
    set_damage_desc("positive energy on undead");
    set_syntax("cast cantrip disrupt undead on TARGET");
    set_description("With this spell, the caster directs a ray of positive energy that severely harms undead.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
}

spell_effect(int prof) {

    if(!target->is_undead())
    {
        tell_object(caster,"%^YELLOW%^As your target is not undead, the spell fizzles harmlessly.");
        dest_effect();
        return;
    }

    spell_successful();
    if (interactive(caster)) {
        tell_object(caster,"%^YELLOW%^You chant sonorously and direct a ray of light at "+target->QCN+"!");
        tell_room(place,"%^YELLOW%^"+caster->QCN+" chants sonorously and directs a ray of light at "+target->QCN+"!", ({caster}) );
    }
    tell_object(place,"%^YELLOW%^A ray of light scorches "+target->QP+"!");
    damage_targ(target, target->return_target_limb(), sdamage, "positive energy");
    TO->dest_effect();
}
