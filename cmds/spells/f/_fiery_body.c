#include <std.h>
#include <magic.h>
inherit SPELL;

string ashort;
int cond_test = 0;
int lastattack;

void effect(int direction)
{
    if (direction > 0) {
        caster->set_property("flying", 1);
        caster->set_property("fiery_body", 1);
    }else {
        caster->set_property("flying", -1);
        caster->remove_property("fiery_body");
    }

    caster->add_stat_bonus("dexterity", 7 * direction);
    caster->set_resistance_percent("fire", 133 * direction);
    caster->set_resistance_percent("acid", 50 * direction);
    caster->set_resistance_percent("electricity", 50 * direction);
    caster->set_resistance_percent("cold", -50 * direction);

    return;
}

void create()
{
    ::create();
    set_spell_name("fiery body");
    set_spell_level(([ "mage" : 9, "oracle" : 9, "warlock" : 4, "cleric" : 9, "druid" : 9 ]));
    set_mystery("flame");
    set_domains("fire");
    set_spell_sphere("alteration");
    set_syntax("cast CLASS fiery body");
    set_damage_desc("levitating, 133% resistance to fire, 50% to acid and electricity, -50% to cold, 6 dex bonus");
    set_description("This spell transforms your body into living flame. You and your equipment are immune to fire damage. For every three fire damage point taken you're healed one point. You ignore half of electricity and acid damage. You gain six dexterity bonus and ability to fly. You take half more damage from cold.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
    set_feats_required(([ "warlock" : "infernal practitioner"]));
}

int preSpell()
{
    if (caster->query_property("fiery_body")) {
        tell_object(caster, "%^BOLD%^%^WHITE%^You're already the flame itself.%^RESET%^");
        return 0;
    }
    return 1;
}

string query_cast_string()
{
    return "%^BOLD%^%^RED%^" + caster->QCN + " levitates above ground as " + caster->QS + " chants the spell.";
}

void spell_effect()
{
    ashort = "%^RESET%^%^RED%^ (%^BOLD%^%^RED%^f%^BOLD%^la%^BLACK%^m%^RED%^i%^RESET%^%^RED%^ng %^BOLD%^%^BLACK%^s%^RED%^il%^BLACK%^h%^RESET%^%^RED%^o%^BOLD%^ue%^BLACK%^t%^RED%^t%^RESET%^%^RED%^e%^RESET%^%^RED%^)";

    tell_room(ENV(caster), "%^BOLD%^%^RED%^As " + caster->QCN + " finishes the chant, " + caster->QP + " body turns into flame.%^RESET%^");

    effect(1);
    caster->set_property("added short", ({ ashort }));
    caster->set_property("spelled", ({ TO }));
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH;
    set_end_time();
    call_out("dest_effect", spell_duration);
    addSpellToCaster();
    spell_successful();
}

void dest_effect()
{
    if (objectp(caster)) {
        caster->remove_property_value("added short", ({ ashort }));
        tell_room(ENV(caster), "%^BOLD%^%^RED%^" + caster->QCN + " silhouette loses its fiery appearance.%^RESET%^");
        effect(-1);
    }
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
