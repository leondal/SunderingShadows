#include <spell.h>
#include <daemons.h>
#include <magic.h>
#include <std.h>

inherit SPELL;

int mybonus;

void create()
{
    ::create();
    set_spell_name("divine power");
    set_spell_level(([ "cleric" : 4, "inquisitor":4]));
    set_domains("war");
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS divine power");
    set_description("This spell will fill the caster with the rage of war, causing him to berserk madly. The strength of the caster's deity and a blessed speed result in blind fighting and reckless fearlessness. This spell does not work in conjunction with similar magical effects, such as rally, rage, haste, transformation, dance of a thousand cuts, or fell flight.%^RESET%^");
    set_verbal_comp();
    set_helpful_spell(1);
}

string query_cast_string()
{
    return "%^BOLD%^%^RED%^" + caster->QCN + " beats " + caster->QP + " chest repeatedly, shouts and jumps about madly.";
}

int preSpell()
{
    if ((int)CASTER->query_property("raged") || (int)CASTER->query_property("transformed") || (int)caster->query_property("dance-of-cuts")) {
        tell_object(caster, "You are already under the effect of a spell to aid you in combat.");
        return 0;
    }
    if ((int)CASTER->query_property("hasted") || pointerp(CASTER->query_property("rally"))) {
        tell_object(caster, "Similar magic already affects you.");
        return 0;
    }
    mybonus = clevel / 12 + 1; //same as rally melee
    return 1;
}

void spell_effect(int prof)
{
    tell_room(place, "%^BOLD%^%^CYAN%^The madness of war and the need for victory "
              "overwhelm " + caster->QCN + ".%^RESET%^", caster);
    tell_object(caster, "%^BOLD%^%^CYAN%^The madness of war and the need for victory overwhelm you.%^RESET%^");

    caster->set_property("berserked", 1);
    caster->set_property("dance-of-cuts", 1);
    caster->add_attack_bonus(mybonus);
    caster->add_damage_bonus(mybonus);
    addSpellToCaster();
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH;
    set_end_time();
    call_out("dest_effect",spell_duration);
    call_out("berserk", ROUND_LENGTH);
    caster->set_property("spelled", ({ TO }));
}

void berserk()
{
    if (!objectp(caster)) {
        return;
    }
    if (sizeof(caster->query_attackers())) {
        if (!random(4)) {
            tell_object(caster, "%^BOLD%^%^RED%^You berserk with a wild rage.");
            tell_room(environment(caster), "%^BOLD%^%^RED%^" + caster->QCN + " berserks madly.", caster);
        }
        caster->execute_attack();
    }

    if ((!caster->is_in_combat()) && (!random(10))) {
        //caster->do_damage("torso", random(2) + 1);
        damage_targ(caster, "torso", roll_dice(1,2), "untyped");
        tell_object(caster, "%^BOLD%^%^RED%^You hurt yourself in your lust for battle and victory.");
    }
    call_out("berserk", ROUND_LENGTH);
}

void dest_effect()
{
    if (objectp(caster)) {
        if (caster->query_property("berserked")) {
            tell_object(caster, "%^CYAN%^The rage leaves you.%^RESET%^");
            tell_room(environment(caster), "%^CYAN%^The rage of " +
                      "war lifts from " + caster->QCN + ".", caster);
            caster->remove_property("berserked");
            caster->remove_property("dance-of-cuts");
            caster->add_attack_bonus(-mybonus);
            caster->add_damage_bonus(-mybonus);
            caster->remove_property_value("spelled", ({ TO }));
            caster->use_stamina(25);
            remove_call_out("berserk");
        }
    }
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
