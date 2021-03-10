#include <std.h>
#include <priest.h>
inherit SPELL;

int timer, flag, stage, toggle, counter;

void create()
{
    ::create();
    set_spell_name("vampiric shadow shield");
    set_spell_level(([ "mage" : 5, "assassin" : 3, "oracle" : 5, "magus" : 5 ]));
    set_mystery(({ "darkness", "shadow" }));
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS vampiric shadow shield");
    set_damage_desc("negative energy on living");
    set_description("You raise shadows of the undead to guard you from those who mean you harm. Up to eight livings that attack you will be harmed and their essences will be used to heal you.");
    set_save("reflex");
    set_helpful_spell(1);
    traveling_aoe_spell(1);
}

string query_cast_string()
{
    return "%^BOLD%^%^BLACK%^As " + caster->QCN + " chants in low undertones shadows raise and surround " + caster->QO + ".%^RESET%^";
}

int preSpell()
{
    if (caster->query_property("vampiric shadow shield")) {
        tell_object(caster, "You are already protected by this spell.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof)
{
    int duration;
    duration = (ROUND_LENGTH * 6) * clevel;
    tell_room(place, "%^BOLD%^%^BLACK%^" + caster->QCN + " completes " + caster->QP + " the chant and is surrounded by restless shadows.", caster);
    tell_object(caster, "%^BOLD%^%^BLACK%^You complete your chant and are surrounded by restless shadows!");
    caster->set_property("vampiric shadow shield", 1);
    caster->set_property("spelled", ({ TO }));
    caster->set_property("added short", ({ "%^RESET%^%^ORANGE%^ (%^BOLD%^%^BLACK%^eng%^RESET%^%^ORANGE%^u%^BOLD%^%^BLACK%^lf%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^d i%^RESET%^%^ORANGE%^n %^BOLD%^%^BLACK%^sh%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^dows%^RESET%^%^ORANGE%^)%^WHITE%^" }));
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
    attackers = filter_array(attackers, (: objectp($1) :));
    attackers = filter_array(attackers, (: !$1->query_property("negative energy affinity") :));
    attackers = filter_array(attackers, (: !do_save($1, 0) :));

    if (sizeof(attackers)) {
        define_base_damage(0);
        tell_room(place, "%^BOLD%^%^BLACK%^Sh%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^d%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^ws around " + caster->QCN + " caress " + caster->QP + " enemies!", ({ caster, target }));
        tell_object(caster, "%^BOLD%^%^BLACK%^Sh%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^d%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^ws around you caress your enemies.");
        for (i = 0; i < sizeof(attackers); i++) {
            tell_object(attackers[i], "%^BOLD%^%^BLACK%^You are caressed by the shield of shadows as you strike " + caster->QCN + "!");
            damage_targ(attackers[i], attackers[i]->return_target_limb(), sdamage, "negative energy");
        }
        if (caster->query_hp() < caster->query_max_hp()) {
            damage_targ(caster, caster->return_target_limb(), -sdamage / 8 * (i > 8?8:i), "untyped");
        }
    }
    prepend_to_combat_cycle(place);
    counter--;
}

void dest_effect()
{
    remove_call_out("room_check");
    if (objectp(caster)) {
        tell_room(environment(caster), "%^BOLD%^%^ORANGE%^The shadows around " + caster->QCN + " retreat.", caster);
        tell_object(caster, "%^BOLD%^%^ORANGE%^The shadows around you retreat.");
        caster->remove_property("vampiric shadow shield");
        caster->remove_property_value("added short", ({ "%^RESET%^%^ORANGE%^ (%^BOLD%^%^BLACK%^eng%^RESET%^%^ORANGE%^u%^BOLD%^%^BLACK%^lf%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^d i%^RESET%^%^ORANGE%^n %^BOLD%^%^BLACK%^sh%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^dows%^RESET%^%^ORANGE%^)%^WHITE%^" }));
    }
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
