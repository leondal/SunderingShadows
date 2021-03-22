#include <priest.h>
#include <magic.h>
inherit SPELL;


int bonus;

void create()
{
    ::create();
    set_author("nienne");
    set_spell_name("spell turning");
    set_spell_level(([ "mage" : 7, "oracle" : 7 ]));
    set_mystery("spellscar");
    set_spell_sphere("abjuration");
    set_damage_desc("clevel/6+5 spell reflection chance.");
    set_syntax("cast CLASS spell turning");
    set_description("The most skilled of abjurationists can use such a spell to raise a protective ward around themselves"
                    ". While it holds, it will have a chance to reflect any spells which are directly aimed at the caster, regardless of "
                    "whether they are hostile or friendly. The ward will not reflect splash damage or AOE, but only direct-targetted spells. This spell will override spell reflection and reflection feats.");
    set_verbal_comp();
    set_somatic_comp();
    set_components(([
                        "mage" : ([ "small silver mirror" : 1, "glass rod" : 1, ]),
                        ]));
    set_helpful_spell(1);
}

int preSpell()
{
    if (caster->query_property("spellturning")) {
        tell_object(CASTER, "You are already under the influence of such an effect.");
        return 0;
    }
    return 1;
}

string query_cast_string()
{
    return "%^MAGENTA%^" + caster->QCN + " traces an elaborate pattern in the air before " + caster->QO + ".%^RESET%^";
}

void spell_effect(int prof)
{
    int i;
    if (!objectp(caster)) {
        dest_effect();
        return;
    }
    if (interactive(caster)) {
        tell_object(caster, "%^BOLD%^%^MAGENTA%^You trace a protective glyph in the air before you, which flares brightly "
                    "and then vanishes!%^RESET%^");
        tell_room(place, "%^BOLD%^%^MAGENTA%^A glyph appears in a bright flare of light before " + caster->QCN + ", and then "
                  "vanishes!%^RESET%^", caster);
    }
    bonus = clevel / 6 + 5;
    caster->set_property("spellturning", bonus);
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH * 5 + 1800;
    set_end_time();
    call_out("dest_effect",spell_duration);
    spell_successful();
    addSpellToCaster();
}

void dest_effect()
{
    int i;
    if (objectp(CASTER)) {
        tell_object(caster, "%^MAGENTA%^You feel the protective spell ward fade from you.%^RESET%^");
        caster->set_property("spellturning", -bonus);
    }
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
