#include <std.h>
#include <daemons.h>
#include <spell.h>
#include <magic.h>

inherit SPELL;

void create()
{
    ::create();
    set_spell_name("blood raze");
    set_spell_level(([ "innate" : 5 ]));
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS blood raze");
    set_damage_desc("fire, negative energy");
    set_description("You expend some of your bloodlust, sending away crimson flames at your enemies. If your enemies are living, you will drain them for both health and bloodlust.");
    set_verbal_comp();
    set_somatic_comp();
    set_blood_magic(1);
    splash_spell(2);
    set_save("reflex");
}

string query_cast_string()
{
    return "%^BOLD%^%^BLACK%^" + caster->QCN + " raises " + caster->QP + " hand, as if to strike outwards.";
}

void spell_effect(int prof)
{
    object* attackers;
    int i, admg;
    attackers = target_selector();

    attackers = filter_array(attackers, (: $1->query_property("minion") != $2:), caster);

    caster->add_bloodlust(-500);
    tell_room(place, "%^BOLD%^%^RED%^" + caster->QCN + " waves hand and releases an arc of crimson red flames!%^RESET%^");
    if (sizeof(attackers) < 1) {
        tell_object(caster, "%^RED%^The flames surround you but fail to touch anything as nobody is attacking you.%^RESET%^");
        dest_effect();
        return;
    }

    for (i = 0; i < sizeof(attackers); i++) {
        if (!objectp(attackers[i])) {
            continue;
        }
        admg = sdamage;
        if (do_save(attackers[i])) {
            admg /= 2;
        }
        tell_object(attackers[i], "%^RED%^%^BOLD%^The %^BLACK%^flame%^RED%^ burns through you!%^RESET%^");
        tell_room(place, "%^RED%^%^BOLD%^The %^BLACK%^crimson flame%^RED%^ burns through " + attackers[i]->QCN + "!%^RESET%^", attackers[i]);
        if (RACE_D->is_valid_blooddrain_target(attackers[i], caster)) {
            caster->add_bloodlust(100);
            caster->cause_typed_damage(caster, "torso", admg / 8, "negative energy");
        }

        damage_targ(attackers[i], attackers[i]->return_target_limb(), admg, "fire");

    }
    spell_successful();
    dest_effect();
}

void dest_effect()
{
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
