#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

void create()
{
    ::create();
    set_spell_name("banshee blast");
    set_spell_level(([ "mage" : 6, "magus" : 6 ]));
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS banshee blast on TARGET");
    set_damage_desc("sonic");
    set_description("A caster invokes a horrible arcane scream directed at a target. Targets caught in the wave may attempt to dodge out of the damage. If they fail, they must withstand a mental assault or become panicked. ");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("reflex, then will");
    splash_spell(1);
    mental_spell();
}

string query_cast_string() {
    return "%^BLUE%^"+caster->QCN+" starts to chant in tongues fell, a feeling of otherwordly horror fills the place.";
}

void spell_effect(int prof)
{
    object *foes, foe;
    int dam;

    tell_object(caster,"%^BLUE%^You concentrate and release a HORRIBLE SCREAM, directed at " +target->QCN+".");
    tell_room(place,"%^BLUE%^"+caster->QCN+" releases a HORRIBLE SCREAM, directed at " +target->QCN+".",caster);
    message("info","%^BLUE%^You hear a horrible high-pitched scream.",nearbyRoom(place,2));

    foes = target_selector();

    if (sizeof(foes)) {
        foreach(foe in foes)
        {
            dam = sdamage;
            set_save("reflex");
            if (do_save(foe, 0)) {
                tell_object(foe, "%^BLUE%^You barely make your way out of the blast wave!");
                tell_room("%^BLUE%^" + foe->QCN + " barely makes it out of the blast wave!", foe);
                dam /= 2;
            } else {
                tell_object(foe,"%^BLUE%^%^BOLD%^You're blasted by the scream!");
                tell_room("%^BLUE%^%^BOLD%^" + foe->QCN + " is blasted by the scream!", foe);
                set_save("will");
                if (!do_save(foe, 0) ||
                    mind_immunity_damage(foe, "default")) {
                    "/std/effect/status/panicked"->apply_effect(foe, clevel / 12 + 1);
                }
            }
            damage_targ(foe, foe->return_target_limb(), dam, "sonic");
        }
    }

    spell_successful();
    dest_effect();
}
