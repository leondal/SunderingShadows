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
    set_author("nienne");
    set_spell_name("bestow curse");
    set_spell_level(([ "mage" : 4, "inquisitor":3, "paladin":3, "cleric":3]));
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS bestow curse on TARGET");
    set_damage_desc("clevel / 8 to all skills, attack and damage bonus, caster level");
    set_description("By means of this spell, the caster places a curse upon the target that will weaken them considerably"
", lowering their defenses and their combat abilities. It is not dispellable by normal magics, but will fade over time.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("will");
}

string query_cast_string() {
    return "%^BLUE%^A dark aura threads its way around "+caster->QCN+"'s fingers as "+
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
    if(target->query_property("cursed")) {
        tell_object(caster,"%^CYAN%^Your spell slips away from "+target->QCN+", unable to weaken them further!%^RESET%^");
        tell_room(place,"%^CYAN%^The aura around "+caster->QCN+"'s hands weakens and then fades away.%^RESET%^",caster);
        TO->remove();
        return;
    }
    if(do_save(target, -2)){
        tell_object(target,"%^CYAN%^You manage to shake off the dark aura that starts to grow around you, and it fades "
"away to nothing!%^RESET%^");
        tell_room(place,"%^CYAN%^A mirroring aura starts to grow around "+target->QCN+", but then it fades away to "
"nothing.%^RESET%^",target);
        TO->remove();
        return;
    }
    bonus = clevel / 6 + 1;
    duration = (ROUND_LENGTH * 4 + roll_dice(1, 20)) * clevel;

    tell_object(target,"%^BLUE%^A mirroring aura starts to grow around you, seeping into your skin to taint it a %^RESET%^sic%^GREEN%^k%^RESET%^ly %^BLUE%^pallid hue.  An overwhelming feeling of weakness comes over you.%^RESET%^");
    tell_room(place,"%^BLUE%^A mirroring aura starts to grow around "+target->QCN+", seeping into "+target->QP+" skin to taint it a %^RESET%^sic%^GREEN%^k%^RESET%^ly %^BLUE%^pallid hue.%^RESET%^",target);
    target->add_damage_bonus((-1) * bonus);
    target->add_attack_bonus((-1) * bonus);
    target->set_property("empowered", (-1) * bonus);
    for (i = 0; i < sizeof(CORE_SKILLS); i++) {
        target->add_skill_bonus(CORE_SKILLS[i], (-1) * bonus);
    }
    target->add_saving_bonus("all", (-1) * bonus);
    target->set_property("spelled", ({ TO }));
    target->set_property("cursed", 1);
    addSpellToCaster();
    spell_duration = duration;
    set_end_time();
    call_out("dest_effect",spell_duration);
    spell_successful();
}

void dest_effect() {
    if(objectp(target)) {
        tell_object(target,"%^CYAN%^The feeling of weakness finally lifts, and with it fades the sickly color of your skin.%^RESET%^");
        tell_room(environment(target),"%^CYAN%^The sickly color of "+target->QCN+"'s skin fades back into a more healthy shade.%^RESET%^",target);
        target->add_damage_bonus(bonus);
        target->add_attack_bonus(bonus);
        target->set_property("empowered",bonus);
        target->remove_property_value("spelled", ({TO}) );
        for(i=0;i<sizeof(CORE_SKILLS);i++) target->add_skill_bonus(CORE_SKILLS[i],bonus);
        target->add_saving_bonus("all",bonus);
        target->remove_property("cursed");
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
