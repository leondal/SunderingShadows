#include <std.h>
#include <daemons.h>
#include <spell.h>
#include <magic.h>
inherit SPELL;

void second_hit();
void last_hit();

object* victims;

void create()
{
    ::create();
    set_author("odin");
    set_spell_name("caustic eruption");
    set_spell_level((["mage" : 7, "cleric" : 7 ]));
    set_domains("suffering");
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS caustic eruption");
    set_damage_desc("acid");
    set_description("You conjure an eruption of acid around, causing damage. On your turn in each of the next two rounds, your target takes additional acid damage.");
    set_verbal_comp();
    set_somatic_comp();
    splash_spell(3);
    set_save("reflex");
}

string query_cast_string()
{
    tell_object(caster, "%^BOLD%^%^GREEN%^You give voice to a word of conjuration, sending a faint tremor through the air.");
    tell_room(place, "%^BOLD%^%^GREEN%^" + caster->QCN + " gives voice to a word of conjuration, and you feel a faint tremor "
              "touch the air around you.", caster);
    return "display";
}

void spell_effect(int prof)
{
    object peep;
    victims = target_selector();

    if (!sizeof(victims)) {
        tell_object(caster,"%^BOLD%^%^GREEN%^Your spell fails to connect to anyone.");
        dest_effect();
    }

    foreach(peep in victims)
    {
        tell_object(peep, "%^BOLD%^%^GREEN%^Acid erupts and clings to your skin!%^RESET%^");
        tell_room(place, "%^BOLD%^%^GREEN%^" + peep->QCN + "'s skin burns as " + peep->QS + " is engulfed in acid!%^RESET%^", peep);

        if (!do_save(peep)) {
            damage_targ(peep, peep->return_peep_limb(), sdamage, "acid");
        } else {
            tell_object(peep, "%^GREEN%^You steel yourself and shrug off the worst of the pain.%^RESET%^");
            damage_targ(peep, peep->return_peep_limb(), sdamage / 2, "acid");
        }

    }
    spell_successful();
    call_out("second_hit", ROUND_LENGTH);
}

void second_hit()
{
    object peep;
    define_base_damage(0);

    foreach(peep in victims)
    {
        if (!objectp(peep)) {
            victims -= ({ peep });
            continue;
        }
        if (peep->query_hp() < 0) {
            victims -= ({ peep });
            continue;
        }

        tell_object(peep, "%^BOLD%^%^GREEN%^Another surge of pain runs through you as the acid continues to burn through your limbs.%^RESET%^");
        tell_object(environment(peep), "%^BOLD%^%^GREEN%^" + peep->QCN + " trembles as the acid continues to burn " + peep->QP + " frame.%^RESET%^", peep);
        if (!do_save(peep)) {
            damage_targ(peep, peep->return_peep_limb(), sdamage / 2, "acid");
        } else {
            tell_object(peep, "%^GREEN%^You steel yourself and shrug off the worst of the pain.%^RESET%^");
            damage_targ(peep, peep->return_target_limb(), sdamage / 4, "acid");
        }
    }

    if (!sizeof(victims)) {
        dest_effect();
    }

    call_out("last_hit", ROUND_LENGTH);
}

void last_hit()
{
    object peep;

    define_base_damage(0);

    foreach(peep in victims)
    {
        if (!objectp(peep)) {
            victims -= ({ peep });
            continue;
        }
        if (peep->query_hp() < 0) {
            victims -= ({ peep });
            continue;
        }
        tell_object(peep, "%^BOLD%^%^GREEN%^Caustic acid continues to bubble on your skin, sending a wracking pain through you before it finally fades!%^RESET%^");
        tell_object(environment(peep), "%^BOLD%^%^GREEN%^" + peep->QCN + " is shaken by a wracking pain, before finally the acid subsides.%^RESET%^", peep);
        if (!do_save(peep)) {
            damage_targ(peep, peep->return_peep_limb(), sdamage / 3, "acid");
        } else {
            tell_object(peep, "%^GREEN%^You steel yourself and shrug off the worst of the pain.%^RESET%^");
            damage_targ(peep, peep->return_target_limb(), sdamage / 6, "acid");
        }
    }
    dest_effect();
}

void dest_effect()
{
    if (find_call_out("second_hit") != -1) {
        remove_call_out("second_hit");
    }
    if (find_call_out("last_hit") != -1) {
        remove_call_out("last_hit");
    }
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
