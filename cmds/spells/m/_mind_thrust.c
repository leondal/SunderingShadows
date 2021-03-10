// Mind Thrust
// ~Circe~ 7/19/05
#include <spell.h>
inherit SPELL;

void create() {
    ::create();
    set_spell_name("mind thrust");
    set_spell_level(([ "psion" : 1 ]));
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS mind thrust on TARGET");
    set_description("Mind thrust will cause the psion to manifest random psychic energy, directing it at a target.  The "
"target feels confused and in pain, much like an excrutiating migraine.  The damage caused grows with the psion's power.");
    set_target_required(1);
    mental_spell();
}

spell_effect(int prof) {
    int num, numdarts, damage, mylevel;
    string hardness;
    mylevel = clevel;

    spell_successful();
    if (interactive(caster)) {
        tell_object(caster,"%^MAGENTA%^You see an opening and pause, "+
           "training your gaze on "+target->QCN+"!");
        tell_object(target,"%^MAGENTA%^"+caster->QCN+" grows "+
           "utterly still and stares at you intently!");
        tell_room(place,"%^MAGENTA%^"+caster->QCN+" grows "+
           "utterly still, staring at "+target->QCN+" "+
           "intently!", ({caster, target}) );
    }
    damage = sdamage;

    if (interactive(caster)) {
            tell_object(caster,"%^BOLD%^%^MAGENTA%^A wave of your "+
               "psychic energy assaults "+target->QCN+"'s mind, "+
               "causing "+target->QP+" head to snap back!");
            tell_object(target,"%^BOLD%^%^MAGENTA%^Your head snaps "+
               "back as a wave of psychic energy from "+caster->QCN+" "+
               "assaults your mind, leaving you shaken!");
            tell_room(place,"%^BOLD%^%^MAGENTA%^"+target->QCN+"'s "+
               "head snaps back suddenly, leaving "+target->QO+" "+
               "looking confused!",({caster, target}) );
    } else {
            tell_object(target,"%^BOLD%^%^MAGENTA%^Your head snaps "+
               "back as a wave of psychic energy from "+caster->QCN+" "+
               "assaults your mind, leaving you shaken!");
            tell_room(place,"%^BOLD%^%^MAGENTA%^"+target->QCN+"'s "+
               "head snaps back suddenly, leaving "+target->QO+" "+
               "looking confused!",({caster, target}) );
    }
    damage_targ(target, target->return_target_limb(), damage,"mental");
    TO->dest_effect();
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
