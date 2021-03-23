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
    set_spell_name("eyebite");
    set_spell_level(([ "mage" : 6, "bard" : 6, "oracle" : 6, "cleric" : 6 ]));
    set_domains("evil");
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS eyebite on TARGET");
    set_damage_desc("sickened, panicked and comatose");
    set_description("With this spell, the caster imbues her eyes with dread power, glancing upon her enemies as she curses them. This curse works its worst on weaker enemies, paralyzing them in fear. The target creature may become sickened, panicked or even comatose. Effects stack as the power difference increases. A successful will save will negate the effect.");
    set_save("fort");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    evil_spell(1);
}

string query_cast_string() {
    return "%^BLUE%^A dark aura threads its way around "+caster->QCN+"'s eyes as "+
	caster->QS+" intones a spell.%^RESET%^";
}

void spell_effect(int prof) {
    int duration;
    if(target == caster) {
        tell_object(caster, "%^CYAN%^You realise your error in cursing yourself, and let your spell fade away.%^RESET%^");
        tell_room(place,"%^CYAN%^The aura around "+caster->QCN+"'s hands weakens and then fades away.%^RESET%^",caster);
        TO->remove();
        return;
    }
    if(do_save(target)){
        tell_object(target,"%^CYAN%^You manage to endure the dark aura that starts to grow around you, and it fades "
"away to nothing!%^RESET%^");
        tell_room(place,"%^CYAN%^A mirroring aura starts to grow around "+target->QCN+", but then it fades away to "
"nothing.%^RESET%^",target);
        TO->remove();
        return;
    }
    bonus = clevel/10;
    duration = ROUND_LENGTH * (clevel/6+1);
    tell_object(target,"%^BLUE%^A mirroring aura starts to grow around you, seeping into your skin to taint it a %^RESET%^"
"sic%^GREEN%^k%^RESET%^ly %^BLUE%^pallid hue.  An overwhelming feeling of weakness comes over you.%^RESET%^");
    tell_room(place,"%^BLUE%^A mirroring aura starts to grow around "+target->QCN+", seeping into "+target->QP+" skin to taint it a %^RESET%^sic%^GREEN%^k%^RESET%^ly %^BLUE%^pallid hue.%^RESET%^",target);

    {
        object eff = "/std/effect/status/sickened"->apply_effect(target,clevel/4+1);
        if(objectp(eff))
            eff->set_spell();
    }

    if(target->query_base_character_level()<clevel)
    {
        object eff =  "/std/effect/status/panicked"->apply_effect(target,roll_dice(1,4));
        if(objectp(eff))
            eff->set_spell();
    }
    //Panicked and comatose at the same time, sure, DnD, you make sense
    if(target->query_base_character_level()<clevel)
    {
        tell_object(target,"%^BOLD%^%^BLUE%^Unable to contain your terror, you faint!%^RESET%^");
        tell_room(environment(target),"%^BOLD%^%^BLUE%^"+target->QCN+" faints!%^RESET%^",target);
        target->set_unconscious(roll_dice(1,6),"You're unconscious!");
    }
    addSpellToCaster();
    spell_duration = duration;
    set_end_time();
    call_out("dest_effect",spell_duration);
    spell_successful();
}

void dest_effect() {
    if(objectp(target)) {
        tell_object(target,"%^CYAN%^The feeling of weakness finally lifts, and with it fades the sickly color of your "
"skin.%^RESET%^");
        tell_room(environment(target),"%^CYAN%^The sickly color of "+target->QCN+"'s skin fades back into a more healthy "
"shade.%^RESET%^",target);
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
