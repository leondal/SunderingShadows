// midlevel necromancy school specialty spell. Nienne, 08/09.
#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>
#include <skills.h>
inherit SPELL;

int bonus,i;

int is_curse()
{
    return 1;
}

void create() {
    ::create();
    set_spell_name("sands of time");
    set_spell_level(([ "mage" : 3, "oracle" : 3, "bard" : 2 ]));
    set_spell_sphere("necromancy");
    set_mystery("reaper");
    set_syntax("cast CLASS sands of time on TARGET");
    set_damage_desc("-2 to physical stats to living, untyped to undead");
    set_description("You temporarily age the target, immediately advancing it two age categories further. The target immediately takes the age penalties to Strength, Dexterity, and Constitution for its new age category, but does not gain the bonuses for that category. Undead creatures instead recieve untyped damage.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_feats_required(([ "bard" : "timeweaver" ]));
}

string query_cast_string() {
    return "%^BLUE%^A dark aura threads its way around "+caster->QCN+"'s fingers as "+caster->QS+" intones a spell.%^RESET%^";
}

void spell_effect(int prof) {
    int duration;
    int willing = 0;
    if(target->query_property("sands of time")) {
        tell_object(caster,"%^ORANGE%^Your spell slips away from "+target->QCN+", unable to weaken them further!%^RESET%^");
        tell_room(place,"%^ORANGE%^The aura around "+caster->QCN+"'s hands weakens and then fades away.%^RESET%^",caster);
        TO->remove();
        return;
    }

    if(target->is_undead())
    {
        tell_object(caster,"%^ORANGE%^Your spell withers "+target->QCN+", but is unable to weaken them!%^RESET%^");
        tell_room(place,"%^ORANGE%^The aura around "+caster->QCN+"'s hands withers them and then fades away.%^RESET%^",caster);
        damage_targ(target, target->return_target_limb(), sdamage,"untyped" );
        TO->remove();
        return;
    }
    bonus = 2; // TODO: Consider age cathegory shift property instead.
    duration = (ROUND_LENGTH * 4) * clevel;
    spell_kill(target,caster);
    tell_object(target,"%^ORANGE%^You feel horror as your body rapidly ages, making you much older.%^RESET%^");
    tell_room(place,"%^ORANGE%^"+target->QCN+"becomes much older.%^RESET%^",target);
    target->add_stat_bonus("strength", -bonus);
    target->add_stat_bonus("dexterity", -bonus);
    target->add_stat_bonus("constitution", -bonus);
    target->set_property("spelled", ({TO}) );
    target->set_property("sands of time",1);
    addSpellToCaster();
    spell_duration = duration;
    set_end_time();
    call_out("dest_effect",spell_duration);
    spell_successful();
}

void dest_effect() {
    if(objectp(target)) {
        tell_object(target,"%^ORANGE%^The feeling of weakness finally lifts as your true age returns.%^RESET%^");
        tell_room(environment(target),"%^ORANGE%^The sickly color of "+target->QCN+"'s skin fades back as the true age returns.%^RESET%^",target);
        target->add_stat_bonus("strength", bonus);
        target->add_stat_bonus("dexterity", bonus);
        target->add_stat_bonus("constitution", bonus);
        target->remove_property("sands of time");
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
