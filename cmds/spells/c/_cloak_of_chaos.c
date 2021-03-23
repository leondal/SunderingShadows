#include <priest.h>
#include <magic.h>
#include <spell.h>

inherit SPELL;

int timer, flag, stage, toggle, counter;

void create()
{
    ::create();
    set_spell_name("cloak of chaos");
    set_spell_level(([ "cleric" : 8, "mage" : 8]));
    set_spell_sphere("abjuration");
    set_syntax("cast CLASS cloak of chaos");
    set_damage_desc("divine damage, 4 AC, 4 to all saves");
    set_description("You are surrounded by a cloak of random colors that will harm all your opponents and will slightly protect you. This is nimbus-family spell that won't work with other nimbuses. Like other numbuses it requires a certain alignment from caster.");
    set_property("magic", 1);
    traveling_aoe_spell(1);
}

int preSpell()
{
    int align = caster->query_true_align();
    if (caster->query_property("nimbus")) {
        tell_object(caster, "You are still affected by cloak of chaos or another nimbus spell.");
        return 0;
    }
    if (!(align == 7 || align == 8 || align == 9)) {
        tell_object(caster, "You are of improper alignment to use this spell!");
        return 0;
    }
    return 1;
}

void spell_effect(int prof)
{
    int duration;
    duration = (ROUND_LENGTH * 10) * clevel;

    tell_object(caster, "%^BOLD%^%^MAGENTA%^You feel powers of chaos warding you from pesky order!");
    tell_room(place, "%^BOLD%^%^MAGENTA%^" + caster->QCN + " is suddenly surrounded by chaotic colours!", caster);

    caster->set_property("spelled", ({ TO }));
    caster->set_property("nimbus", 1);
    caster->set_property("added short", ({ "%^BOLD%^%^WHITE%^ %^RED%^(%^ORANGE%^i%^CYAN%^n %^BOLD%^%^RED%^a %^ORANGE%^r%^CYAN%^a%^RESET%^%^ORANGE%^n%^BOLD%^%^GREEN%^d%^RED%^o%^RESET%^%^CYAN%^m %^BOLD%^%^BLUE%^p%^GREEN%^a%^RESET%^%^RED%^t%^GREEN%^t%^BOLD%^%^CYAN%^e%^RED%^r%^RESET%^%^ORANGE%^n %^BOLD%^o%^RESET%^%^RED%^f %^ORANGE%^c%^BOLD%^%^MAGENTA%^o%^ORANGE%^l%^GREEN%^o%^RESET%^%^RED%^r%^GREEN%^s%^RED%^)%^RESET%^" }));
    addSpellToCaster();
    spell_successful();
    caster->add_saving_bonus("all", 4);
    caster->add_ac_bonus(4);
    execute_attack();
    spell_duration = duration;
    set_end_time();
    call_out("dest_effect",spell_duration);
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
    object* attackers;
    int i;

    if (!flag) {
        flag = 1;
        ::execute_attack();
        return;
    }

    place = environment(caster);
    if (!objectp(caster) || !objectp(place)) {
        dest_effect();
        return;
    }

    attackers = filter_array(caster->query_attackers(), (: objectp($1) :));
    attackers = filter_array(attackers, (: $1->is_living() :));

    if (sizeof(attackers)) {
        define_base_damage(0);
        tell_room(place, "%^BOLD%^%^CYAN%^The primal chaos around " + caster->QCN + " falls upon " + caster->QP + " enemies!", ({ caster, target }));
        tell_object(caster, "%^BOLD%^%^CYAN%^The primal chaos around you falls upon your enemies!");
        for (i = 0; i < sizeof(attackers); i++) {
            if (SAVING_D->saving_throw(attackers[i], "spell", 0)) {
                continue;
            }
            tell_object(attackers[i], "%^BOLD%^%^CYAN%^You are scorched by the primal chaos as you strike "
                        "" + caster->QCN + "!");
            damage_targ(attackers[i], attackers[i]->return_target_limb(), sdamage, "divine");
        }
    }
    prepend_to_combat_cycle(place);
}

void dest_effect()
{
    remove_call_out("room_check");
    if (objectp(caster)) {
        tell_object(caster, "%^RESET%^%^MAGENTA%^The chaos around you fades.");
        caster->remove_property("nimbus");
        caster->add_ac_bonus(-4);
        caster->add_saving_bonus("all", -4);
        caster->remove_property_value("added short", ({ "%^BOLD%^%^WHITE%^ %^RED%^(%^ORANGE%^i%^CYAN%^n %^BOLD%^%^RED%^a %^ORANGE%^r%^CYAN%^a%^RESET%^%^ORANGE%^n%^BOLD%^%^GREEN%^d%^RED%^o%^RESET%^%^CYAN%^m %^BOLD%^%^BLUE%^p%^GREEN%^a%^RESET%^%^RED%^t%^GREEN%^t%^BOLD%^%^CYAN%^e%^RED%^r%^RESET%^%^ORANGE%^n %^BOLD%^o%^RESET%^%^RED%^f %^ORANGE%^c%^BOLD%^%^MAGENTA%^o%^ORANGE%^l%^GREEN%^o%^RESET%^%^RED%^r%^GREEN%^s%^RED%^)%^RESET%^" }));
    }
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
