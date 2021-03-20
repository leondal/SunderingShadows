//kiss_of_torment.c
#include <std.h>
inherit SPELL;

void create() {
    ::create();
    set_spell_name("kiss of torment");
    set_spell_level(([ "cleric" : 5 ]));
    set_domains("suffering");
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS kiss of torment on TARGET");
    set_description("A simple touch from this spell will deal extreme torment to the victim, leaving them in agony and distress.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("fort");
}

string query_cast_sting() {
    return "%^RED%^With a loving look around, and an evil grin, "+caster->QCN+" starts to cast.";

}

void spell_effect(int prof) {

    tell_room(place,"%^RED%^"+caster->QCN+" looks with a mocking love at "+target->QCN+".",({caster,target}));
    tell_object(caster,"%^RED%^You look at "+target->QCN+" with a mocking love.");
    tell_object(target,"%^RED%^"+caster->QCN+" looks at you with a mocking love.");

    if (caster->Thaco(0,target,0) <= random(20)+1 ||
        caster->query_property("spectral_hand") &&
        !target->query_property("no paralyze")) {
        tell_room(place,"%^RED%^"+caster->QCN+" carresses "+target->QCN+" with a mocking love "
            "and "+target->QS+" falls writhing in horrific pain.",({caster,target}));
        tell_object(caster,"%^RED%^You carress "+target->QCN+" with a tender touch, and "+target->QS+" falls "
            "writhing in horrific pain.");
        tell_object(target,"%^RED%^"+caster->QCN+" carresses you with a tender touch and you fall "
            "writhing in horrific pain.");
        damage_targ(target, "torso",sdamage,"divine");
        if (!objectp(target)) return;
        target->set_paralyzed(12,"%^RED%^You are writhing in pain.");
        call_out("next_damage",9,target,1);


    } else {
        tell_room(place,"%^RED%^"+caster->QCN+" trys to caress "+target->QCN+" but fails.",({caster,target}));
        tell_object(caster,"%^RED%^You try to caress "+target->QCN+" but fail.");
        tell_object(target,"%^RED%^"+caster->QCN+" tries to carress you but fails.");
        dest_effect();
        return;
    }
}

void next_damage(object targ, int count)
{
    if(do_save(targ,-1) || count > 2) {
        dest_effect();
        return;
    }

    tell_object(targ,"%^RED%^You feel the spell continue, the torment continue.");
    switch (count) {
    case 1:
        damage_targ(targ,"torso",roll_dice(2,6)+random(2*clevel),"divine");
        break;
    case 2:
        damage_targ(targ,"torso",roll_dice(1,6)+random(clevel),"divine");
        break;

    default:
        return;
    }

    call_out("next_damage",9,targ,count++);
}

void dest_effect(){
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
