#include <std.h>
#include <priest.h>
inherit SPELL;

int timer, flag, stage, toggle, counter;

void create()
{
    ::create();
    set_spell_name("cloak of winds");
    set_spell_level(([ "druid" : 2, "mage" : 3, "ranger" : 3, "oracle" : 3, "magus" : 3, "cleric" : 2 ]));
    set_mystery("wind");
    set_domains("air");
    set_spell_sphere("abjuration");
    set_syntax("cast CLASS cloak of winds");
    set_damage_desc("3 / 4 bludgeoning, 2 AC");
    set_description("You raise a strong wind and wrap yourself into it. It will push away your enemies and incoming attacks, and will do it with forceful strength.");
    set_helpful_spell(1);
    traveling_aoe_spell(1);
}

int preSpell()
{
    if (caster->query_property("cloak of winds")) {
        tell_object(caster, "You are already protected by this spell.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof)
{
    int duration;
    duration = (ROUND_LENGTH * 6) * clevel;
    tell_room(place, "%^WHITE%^%^BOLD%^A cloak of winds surrounds and embraces " + caster->QCN + ".", caster);
    tell_object(caster, "%^WHITE%^%^BOLD%^A cloak of winds surrounds and embraces you.");
    caster->set_property("cloak of winds", 1);
    caster->set_property("spelled", ({ TO }));
    caster->set_property("added short", ({ "%^WHITE%^ (%^BOLD%^%^CYAN%^beyond a veil of winds%^RESET%^%^WHITE%^)%^RESET%^" }));
    caster->add_ac_bonus(2);

    addSpellToCaster();
    spell_successful();
    execute_attack();
    counter = 6 * clevel;
    call_out("room_check", ROUND_LENGTH);
}

void room_check()
{
    if (!objectp(caster) || !objectp(ENV(caster))) {
        dest_effect();
        return;
    }

    prepend_to_combat_cycle(ENV(caster));

    call_out("room_check", ROUND_LENGTH * 2);
    return;
}

void execute_attack()
{
    object* attackers, room;
    int i;

    if (!flag) {
        flag = 1;
        ::execute_attack();
        return;
    }

    if (!objectp(caster)) {
        dest_effect();
        return;
    }

    if (!objectp(ENV(caster))) {
        dest_effect();
        return;
    }

    place = ENV(caster);

    if (!objectp(place) || counter < 0) {
        dest_effect();
        return;
    }

    attackers = caster->query_attackers();

    if (sizeof(attackers)) {
        define_base_damage(0);
        tell_room(place, "%^BOLD%^%^WHITE%^Winds around " + caster->QCN + " forcefully push " + caster->QP + " enemies!", ({ caster, target }));
        tell_object(caster, "%^GREEN%^%^The winds around you forcefully push your enemies!");
        for (i = 0; i < sizeof(attackers); i++) {
            if (!objectp(attackers[i])) {
                continue;
            }

            tell_object(attackers[i], "%^WHITE%^%^BOLD%^You are pushed by the wind around " + caster->QCN + "'s body!");
            damage_targ(attackers[i], attackers[i]->return_target_limb(), sdamage * 3 / 4, "bludgeoning");
        }
    }
    prepend_to_combat_cycle(place);
    counter--;
}

void dest_effect()
{
    remove_call_out("room_check");

    if (objectp(caster)) {
        tell_room(environment(caster), "%^BOLD%^%^WHITE%^The cloak of winds around " + caster->QCN + " retreats.");
        caster->remove_property("cloak of winds");
        caster->remove_property_value("added short", ({ "%^WHITE%^ (%^BOLD%^%^CYAN%^beyond a veil of winds%^RESET%^%^WHITE%^)%^RESET%^" }));
        caster->add_ac_bonus(-2);
    }
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
