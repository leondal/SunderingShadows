#include <std.h>
#include <magic.h>
inherit SPELL;

int ticker;

void create() {
    ::create();
    set_spell_name("regenerate");
    set_spell_level(([ "cleric" : 7, "oracle":7 ]));
    set_mystery("life");
    set_domains("renewal");
    set_spell_sphere("healing");
    set_damage_desc("positive energy over clevel / 6 rounds");
    set_syntax("cast CLASS regenerate on TARGET");
    set_description("This spell cures substantial amount of damage over several rounds and removes all exhaustion, fatigue or confusion from the target, and all other cleansing effects that heal clears. Targets with negative energy affinity, such as undead, can't be affected by this spell.");
    set_verbal_comp();
    set_target_required(1);
    set_helpful_spell(1);
}

string query_cast_string() {
    tell_object(caster,"%^BOLD%^%^GREEN%^Motes of green light circle "+
		"around your head, growing in intensity as you chant.");
    tell_room(place,"%^BOLD%^%^GREEN%^Motes of green light circle around"+
		" "+caster->QCN+"'s head as "+caster->QS+" begins to chant.",caster);
    return "display";
}

int preSpell(){
    if(!objectp(target)) {
        tell_object(caster,"This spell requires a target.");
        return 0;
    }

    if (target->query_property("regeneration_spell") ||
        target->query_property("negative energy affinity")) {
        tell_object(caster,"%^BOLD%^%^GREEN%^The spell is forcefully repelled.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof) {
    // ticker in rounds
    ticker = clevel + 1;

    if (!present(target, place)) {
        tell_object(caster, "Your target has left the area.");
        dest_effect();
        return;
    }

    if (target->query_property("regeneration_spell") ||
        target->query_property("negative energy affinity")) {
        tell_object(caster,"%^BOLD%^%^GREEN%^The spell is forcefully repelled.");
        dest_effect();
        return;
    }

    if (caster == target) {
        tell_object(target, "%^GREEN%^%^BOLD%^You can feel a warmth spread " +
                    "over your body as the motes seeps into your skin.");
        tell_room(place, "%^BOLD%^%^GREEN%^The motes of light seep into" +
                  " " + caster->QCN + "'s skin.", caster);
    }else {
        tell_object(target, "%^BOLD%^%^GREEN%^You can feel a warmth spread over " +
                    "your body as the motes that circled " + caster->QCN + " seeps into your skin.");
        tell_room(place, "%^BOLD%^%^GREEN%^The motes of green light fly away from" +
                  " " + caster->QCN + "'s head and seep into " + target->QCN + "'s skin.", caster);
    }

    target->set_property("spelled", ({TO}));
    target->set_property("regeneration_spell", 1);
    addSpellToCaster();
    spell_successful();

    regenerate_target();
}

void regenerate_target()
{
    if (!objectp(target)) {
        dest_effect();
        return;
    }

    if (ticker < 0) {
        dest_effect();
        return;
    }

    if (target->query_hp() < 0) {
        dest_effect();
        return;
    }

    sdamage = roll_dice(1, clevel);

    if (target->query_hp() < target->query_max_hp()) {
        tell_object(target,"%^BOLD%^%^GREEN%^Currents of radiant energy restore your wounds.");
        tell_room(ENV(target),"%^BOLD%^%^GREEN%^Radiant mist raises from " +target->QCN+"'s feet and restores " +target->QP+" wounds.", target);
        damage_targ(target, target->return_target_limb(), sdamage, "positive energy");
    }

    if (target->query_property("effect_fatigued") ||
        target->query_property("effect_exhausted")) {
        "/std/magic/cleanse"->regenerate(target);
    }

    call_out("regenerate_target", ROUND_LENGTH);
    ticker--;

}

void dest_effect()
{
    if (find_call_out("regenerate_target") != -1) {
        remove_call_out("regenerate_target");
    }

    if (objectp(target)) {
        target->remove_property("regeneration_spell");
        tell_object(target,"%^BOLD%^%^GREEN%^The warmth fades away from your skin.");
        tell_room(ENV(target),"%^BOLD%^%^GREEN%^Motes of green light fade away from " +target->QCN+"'s skin.", target);
    }

    ::dest_effect();

    if (objectp(TO)) {
        TO->remove();
    }
}
