// Bless
#include <std.h>
#include <magic.h>

inherit SPELL;

#define ALIGN_D "/daemon/alignment_d.c"

int bonus;

void create()
{
    ::create();
    set_author("ares");
    set_spell_name("bolster");
    set_spell_level((["paladin" : 1]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS bolster on TARGET");
    set_description("This spell will bolster the target, giving them a slightly better chance to hit in combat as well as "
                    "allowing them to do a small amount more damage.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_helpful_spell(1);
}

int preSpell()
{
//    if(!ALIGN_D->is_good(caster)) {
    if (!target) {
        target = caster;
    }
    if (target->query_property("blessed")) {
        tell_object(caster, "%^BOLD%^%^RED%^Your target is already enjoying the blessings of a deity!%^RESET%^");
        return 0;
    }
    return 1;
}

string query_cast_string()
{
    tell_object(caster, "%^BOLD%^%^BLUE%^Raising your hands, you call upon your deity.");
    tell_room(place, "%^BOLD%^%^BLUE%^" + caster->QCN + " begins a boisterous chant" +
              " to " + caster->QP + " deity.", caster);
    return "display";
}

void spell_effect(int prof)
{
    int duration;
    duration = (ROUND_LENGTH * 20) * clevel;
    bonus = 1;
    if (target == caster) {
        tell_room(place, "%^BOLD%^%^BLUE%^An empowering aura surrounds" +
                  " " + caster->QCN + "'s for a moment.", target);
        tell_object(target, "%^BOLD%^%^BLUE%^You feel an empowering aura surround " +
                    "you for a moment, before it sinks into your skin.");
    }else {
        tell_object(caster, "%^BOLD%^You call on " + capitalize((string)caster->query_diety()) + "'s aid and bolster "
                    "" + target->QCN + ".");
        tell_object(target, "%^BOLD%^" + caster->QCN + " calls to " + caster->QP + " deity for aid, bolstering you.");
        tell_room(place, "%^BOLD%^" + caster->QCN + " calls to " + caster->QP + " deity for aid, bolstering "
                  "" + target->QCN + ".", ({ caster, target }));
    }
    target->add_damage_bonus(bonus);
    target->add_attack_bonus(bonus);
    addSpellToCaster();
    target->set_property("spelled", ({ TO }));
    target->set_property("blessed", 1);
    spell_successful();
}

void dest_effect()
{
    if (objectp(target)) {
        tell_object(target, "%^ORANGE%^You can feel the blessing you have been granted fade "
                    "away.");
        target->add_damage_bonus(-1 * bonus);
        target->add_attack_bonus(-1 * bonus);
        target->remove_property("blessed");
    }
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
