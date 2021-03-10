#include <std.h>
#include <priest.h>
inherit SPELL;

int timer, flag, stage, toggle, counter;

void create()
{
    ::create();
    set_spell_name("blood pyre");
    set_spell_level(([ "innate" : 5]));
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS blood pyre");
    set_damage_desc("negative energy");
    set_description("You raise expend some of your bloodlust to create a hurricane of necrotic flames around you, .");
    set_save("reflex");
    set_helpful_spell(1);
    set_blood_magic(1);
    traveling_aoe_spell(1);
}

string query_cast_string()
{
    return "%^BOLD%^%^BLACK%^As " + caster->QCN + " concentrates, bloody red flames raise and surround " + caster->QO + ".%^RESET%^";
}

int preSpell()
{
    if (caster->query_property("blood pyre")) {
        tell_object(caster, "You are already affected by this spell.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof)
{
    int duration;
    duration = (ROUND_LENGTH * 6) * clevel;
    tell_room(place, "%^BOLD%^%^BLACK%^" + caster->QCN + "  " + caster->QP + " the chant and is surrounded by restless shadows.", caster);
    tell_object(caster, "%^BOLD%^%^BLACK%^You complete your concentration and are surrounded by restless flames!");
    caster->add_bloodlust(-1000);
    caster->set_property("blood pyre", 1);
    caster->set_property("spelled", ({ TO }));
    caster->set_property("added short", ({ "%^RESET%^%^RED%^ (%^BOLD%^%^BLACK%^eng%^RESET%^%^RED%^u%^BOLD%^%^BLACK%^lf%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^d i%^RESET%^%^RED%^n %^BOLD%^%^BLACK%^fl%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^mes%^RESET%^%^RED%^)%^WHITE%^" }));
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
        tell_room(place, "%^BOLD%^%^BLACK%^Fl%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^m%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^s around " + caster->QCN + " caress " + caster->QP + " enemies!", ({ caster, target }));
        tell_object(caster, "%^BOLD%^%^BLACK%^Fl%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^m%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^s around you caress your enemies.");
        for (i = 0; i < sizeof(attackers); i++) {
            tell_object(attackers[i], "%^BOLD%^%^BLACK%^You are caressed by the flames around " + caster->QCN + "!");
            damage_targ(attackers[i], attackers[i]->return_target_limb(), sdamage, "negative energy");
            if (RACE_D->is_valid_blooddrain_target(attackers[i], caster)) {
                caster->add_bloodlust(100);
                if (caster->query_hp() < caster->query_max_hp()) {
                    damage_targ(caster, caster->return_target_limb(), -sdamage / 8 * (i > 8?8:i), "untyped");
                }
            }
        }
    }
    prepend_to_combat_cycle(place);
    counter--;
}

void dest_effect()
{
    remove_call_out("room_check");
    if (objectp(caster)) {
        tell_room(environment(caster), "%^BOLD%^%^ORANGE%^The flames around " + caster->QCN + " fade.", caster);
        tell_object(caster, "%^BOLD%^%^ORANGE%^The flames around you fade.");
        caster->remove_property("blood pyre");
        caster->remove_property_value("added short", ({ "%^RESET%^%^RED%^ (%^BOLD%^%^BLACK%^eng%^RESET%^%^RED%^u%^BOLD%^%^BLACK%^lf%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^d i%^RESET%^%^RED%^n %^BOLD%^%^BLACK%^fl%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^mes%^RESET%^%^RED%^)%^WHITE%^" }));
    }
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
