#include <std.h>
#include <priest.h>
inherit SPELL;

int timer, flag, stage, toggle, counter;

void create()
{
    ::create();
    set_spell_name("thorn body");
    set_spell_level(([ "druid" : 4,]));
    set_domains("plant");
    set_spell_sphere("alteration");
    set_syntax("cast CLASS thorn body");
    set_damage_desc("piercing");
    set_description("Thorns grow through your skin, damaging all creature that attack you.");
    set_helpful_spell(1);
    traveling_aoe_spell(1);
}
int preSpell()
{
    if (caster->query_property("thorn body")) {
        tell_object(caster, "You are already protected by thorns.");
        return 0;
    }
    return 1;
}
void spell_effect(int prof)
{
    int duration;
    duration = (ROUND_LENGTH * 6) * clevel;
    tell_room(place, "%^GREEN%^" + caster->QCN + "'s skin grows in a multitude of thorns.", caster);
    tell_object(caster, "%^GREEN%^Your skin grows numerous thorns, and you look like a green hedgehog!");
    caster->set_property("thorn body", 1);
    caster->set_property("spelled", ({ TO }));
    caster->set_property("added short", ({ "%^RESET%^%^GREEN%^ (%^BOLD%^%^BLACK%^c%^RESET%^%^GREEN%^o%^BOLD%^%^BLACK%^v%^RESET%^%^GREEN%^e%^BOLD%^%^BLACK%^r%^RESET%^%^GREEN%^e%^BOLD%^%^BLACK%^d %^RESET%^%^GREEN%^i%^BOLD%^%^BLACK%^n th%^RESET%^%^GREEN%^o%^BOLD%^%^BLACK%^rns%^RESET%^%^GREEN%^)%^RESET%^" }));
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

    attackers = target_selector();

    if (sizeof(attackers)) {
        define_base_damage(0);
        tell_room(place, "%^GREEN%^Thorns that grow through " + caster->QCN + "'s skin scratch " + caster->QP + " enemies!", ({ caster, target }));
        tell_object(caster, "%^GREEN%^%^BOLD%^Thorns on your skin scratch your enemies.");
        for (i = 0; i < sizeof(attackers); i++) {
            if (!objectp(attackers[i])) {
                continue;
            }

            tell_object(attackers[i], "%^GREEN%^You are scratched by the thorns that cover " + caster->QCN + "'s body!");
            damage_targ(attackers[i], attackers[i]->return_target_limb(), sdamage, "piercing");
        }
    }
    prepend_to_combat_cycle(place);
    counter--;
}
void dest_effect()
{
    remove_call_out("room_check");
    if (objectp(caster)) {
        tell_room(environment(caster), "%^BOLD%^%^GREEN%^Thorns that were covering " + caster->QCN + " retreat.");
        caster->remove_property("thorn body");
        caster->remove_property_value("added short", ({ "%^RESET%^%^GREEN%^ (%^BOLD%^%^BLACK%^c%^RESET%^%^GREEN%^o%^BOLD%^%^BLACK%^v%^RESET%^%^GREEN%^e%^BOLD%^%^BLACK%^r%^RESET%^%^GREEN%^e%^BOLD%^%^BLACK%^d %^RESET%^%^GREEN%^i%^BOLD%^%^BLACK%^n th%^RESET%^%^GREEN%^o%^BOLD%^%^BLACK%^rns%^RESET%^%^GREEN%^)%^RESET%^" }));
    }
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
