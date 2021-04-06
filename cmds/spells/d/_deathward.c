#include <std.h>
#include <magic.h>

inherit SPELL;

void create()
{
    ::create();
    set_spell_name("deathward");
    set_spell_level(([ "paladin" : 4, "druid" : 5, "inquisitor" : 4, "cleric" : 4, "psion" : 4]));
    set_discipline("egoist");
    set_spell_sphere("abjuration");
    set_syntax("cast CLASS deathward [on TARGET]");
    set_description("Those most blessed of the gods can call upon their favor to ward away the very hand of death itself. This spell protects against death spells, as well as many spell-like effects.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

int preSpell()
{
    if (!target) {
        target = caster;
    }

    if (target->query_property("no death")) {
        tell_object(caster, "They are already under the influence of a similar effect.");
        return 0;
    }
    return 1;
}

string query_cast_string()
{
    return "%^RED%^" + caster->QCN + " invokes " + caster->QP + " patron's favor!";
}

void spell_effect(int prof)
{
    if (!objectp(target) || !objectp(place)) {
        dest_effect();
        return;
    }

    tell_object(target, "%^BOLD%^%^WHITE%^The blessings of your god fill you with co%^YELLOW%^n%^WHITE%^fid%^YELLOW%^e%^WHITE%^nce!");
    tell_room(place, "%^BOLD%^%^WHITE%^" + target->QCN + "'s eyes light with %^YELLOW%^fe%^WHITE%^rv%^YELLOW%^or %^WHITE%^as " + caster->QP + " prayer is answered!", target);
    target->set_property("no death", 1);
    spell_successful();
    addSpellToCaster();
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH * 12;
    set_end_time();
    call_out("dest_effect",spell_duration);
}

void dest_effect()
{
    if (objectp(target)) {
        tell_object(target, "%^BOLD%^%^WHITE%^You feel the protection of your god fade from you.%^RESET%^");
        target->set_property("no death", -1);
    }
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
