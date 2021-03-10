// body blades
#include <std.h>
#include <priest.h>
#include <magic.h>

inherit SPELL;

int timer, flag, stage, toggle, counter;

void create()
{
    ::create();
    set_spell_name("body blades");
    set_spell_level(([ "cleric" : 2, "inquisitor" : 2]));
    set_spell_sphere("combat");
    set_syntax("cast CLASS body blades");
    set_description("This spell will cause razor sharp blades to sprout from the caster's skin, protecting them from harm "
                    "and doing damage to anyone who attacks the caster.");
    set_verbal_comp();
    set_helpful_spell(1);
    traveling_aoe_spell(1);
}

string query_cast_string()
{
    tell_object(caster, "%^RED%^Rubbing some iron shavings onto your skin," +
                " you begin to chant in a low growl.");
    tell_room(place, "%^RED%^" + caster->QCN + " rubs some iron shavings onto" +
              " " + caster->QP + " skin as " + caster->QS + " chants in a low growl.", caster);
    return "display";
}

int preSpell()
{
    if (caster->query_property("body blades")) {
        tell_object(caster, "You are already protected by body blades.");
        return 0;
    }
    return 1;
}
void spell_effect(int prof)
{
    int duration;
    duration = (ROUND_LENGTH * 6) * clevel;
    tell_room(place, "%^RED%^Tiny blades push out of " + caster->QCN + "'s flesh as "
              "" + caster->QS + " completes " + caster->QP + " chant!", caster);
    tell_object(caster, "%^RED%^You can feel a slight twinge of pain as blades "
                "pierce through your flesh!");
    caster->set_property("body blades", 1);
    caster->set_property("spelled", ({ TO }));
    caster->set_property("added short", ({ "%^BOLD%^%^BLACK%^ (covered with blades)" }));
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
        tell_room(place, "%^BOLD%^%^BLUE%^Thorns that grow through " + caster->QCN + "'s skin scratch " + caster->QP + " enemies!", ({ caster, target }));
        tell_object(caster, "%^BLUE%^%^BOLD%^Thorns on your skin scratch your enemies.");
        for (i = 0; i < sizeof(attackers); i++) {
            if (!objectp(attackers[i])) {
                continue;
            }

            tell_object(attackers[i], "%^BOLD%^%^RED%^You are cut by the blades that have sprouted "
                        "from " + caster->QCN + "'s body!");

            damage_targ(attackers[i], attackers[i]->return_target_limb(), sdamage, "slashing");
        }
    }
    prepend_to_combat_cycle(place);
    counter--;
}
void dest_effect()
{
    remove_call_out("room_check");
    if (objectp(caster)) {
        tell_object(caster, "%^RED%^The blades sink back into your flesh.");
        tell_room(environment(caster), "%^RED%^The blades sink back into " + caster->QCN + "'s flesh.", caster);
        caster->remove_property("body blades");
        caster->remove_property_value("added short", ({ "%^BOLD%^%^BLACK%^ (covered with blades)" }));
    }
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
