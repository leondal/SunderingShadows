#include <std.h>
#include <priest.h>
#include <party.h>

inherit SPELL;

int flag, mrbonus, mrflag;

void emote_em();

void create()
{
    ::create();
    set_spell_name("frightful aspect");
    set_spell_level(([ "cleric" : 8, "druid" : 8, "mage" : 8]));
    set_syntax("cast CLASS frightful aspect");
    set_spell_sphere("alteration");
    set_bonus_type("size");
    set_description("You become a larger, awful version of yourself. You grow in size, and take on features that horrify your enemies. You gain the following abilities: a +6 size bonus to Strength, a +4 size bonus to Constitution, a +6 natural armor bonus, 5 damage resistance, and spell resistance equal to 10 + half your caster level. You also emit an aura that emanates 30 feet from you. Enemy creatures within the aura are shaken. This spell won't work together with iron body, stoneskin and other such spells.\n\n%^BOLD%^%^RED%^See also:%^RESET%^ status effects");
    set_verbal_comp();
    set_somatic_comp();
    splash_spell(2);
    set_helpful_spell(1);
}

int preSpell()
{
    if (caster->query_property("frightful_aspect")) {
        tell_object(caster, "You are already under the effects of this power!");
        return 0;
    }
    if (caster->query_property("iron body")) {
        tell_object(caster, "You already have protection of this nature!");
        return 0;
    }
    mrbonus = 10 + clevel / 2;
    mrflag = 0;
    return 1;
}

void spell_effect(int prof)
{
    tell_object(caster, "%^RED%^You grow twice in size and feel more powerful, ready to crush your enemies!");
    tell_room(environment(caster), "%^RED%^" + caster->QCN + " grows twice in size!", caster);
    //caster->set_property("spelled", ({ TO }));
    caster->set_property("iron body", 1);
    caster->set_property("damage resistance", 5);
    caster->add_stat_bonus("strength", 6);
    caster->add_stat_bonus("constitution", 4);
    caster->set_property("added short", ({ "%^RED%^ (giant)%^RESET%^" }));
    caster->set_size_bonus(1);
    caster->add_ac_bonus(6);
    if (!caster->query_property("raised resistance")) {
        caster->set_property("magic resistance", mrbonus);
        caster->set_property("raised resistance", 1);
        mrflag = 1;
    }
    spell_successful();
    addSpellToCaster();
    environment(caster)->addObjectToCombatCycle(TO, 1);
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH;
    set_end_time();
    call_out("dest_effect", spell_duration);
}

void execute_attack()
{
    object* inven, room, ppl;
    if (!flag) {
        ::execute_attack();
        flag = 1;
        return;
    }
    if (!objectp(caster)) {
        dest_effect();
        return;
    }
    room = environment(caster);

    inven = target_selector(); //doesn't look like this function can take an argument

    if (sizeof(inven)) {
        foreach(ppl in inven)
        {
            if (!ppl->query_property("effect_shaken")) {
                if (!mind_immunity_check(ppl)) {
                    "/std/effect/status/shaken"->apply_effect(ppl, clevel / 6 + 1);
                    tell_object(ppl, "%^RED%^You shake in fear in sight of " + caster->QCN);
                    tell_room(room, "%^RED%^" + ppl->QCN + " shakes in fear in sight of " + caster->QCN, ({ ppl }));
                }
            }
        }
    }

    environment(caster)->addObjectToCombatCycle(TO, 1);
}

void dest_effect()
{
    if (objectp(caster)) {
        caster->set_size_bonus(0);
        caster->remove_property("added short", ({ "%^RED%^ (giant)%^RESET%^" }));
        caster->remove_property("iron body");
        caster->add_stat_bonus("strength", -6);
        caster->add_stat_bonus("constitution", -4);
        caster->set_property("damage resistance", -5);
        caster->add_ac_bonus(-6);
        caster->remove_property("frightful_aspect");
        if (mrflag) {
            caster->set_property("magic resistance", -mrbonus);
            caster->set_property("raised resistance", 0);
            mrflag = 0;
        }
        tell_object(target, "%^RED%^You shrink back to normal!");
        tell_room(environment(caster), "%^RED%^" + caster->QCN + " shrinks back to normal size.", target);
    }
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
