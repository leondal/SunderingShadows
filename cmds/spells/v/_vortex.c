#include <std.h>
#include <daemons.h>
#include <spell.h>
#include <magic.h>


inherit SPELL;

void create()
{
    ::create();
    set_spell_name("vortex");
    set_spell_level(([ "mage" : 7, "druid" : 7, "oracle" : 7 ]));
    set_mystery("waves");
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS vortex");
    set_damage_desc("bludgeoning, paralyzed");
    set_description("You create a vortex and send it at your opponents... Those who can't dodge become momentarely stuck and paralyzed in it.");
    splash_spell(2);
    set_save("reflex");
}

string query_cast_string()
{
    return "%^BOLD%^%^BLUE%^A vortex of %^WHITE%^water%^BLUE%^ and %^WHITE%^wind%^BLUE%^ forms around " + caster->QCN + "as " + caster->QS + " chant!";
}

void spell_effect(int prof)
{
    object* attackers;
    int i, admg;
    attackers = target_selector();

    tell_room(place, "%^BOLD%^%^BLUE%^A vortex of %^WHITE%^whirlwind%^BLUE%^ and %^CYAN%^water%^BLUE%^ forms and disperses from " + caster->QCN + " into all directions!%^RESET%^");
    if (!sizeof(attackers)) {
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
        } else {
            attackers[i]->set_paralyzed(8, "%^BOLD%^%^WHITE%^You're suspended in the currents of the vortex.%^RESET%^");
        }
        tell_object(attackers[i], "%^WHITE%^%^BOLD%^The water of the wortex hits you.%^RESET%^");
        damage_targ(attackers[i], attackers[i]->return_target_limb(), admg, "bludgeoning");
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
