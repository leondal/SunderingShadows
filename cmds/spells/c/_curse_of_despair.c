// templated directly from bestow curse; it's rarely seen anyways. And I wrote it so I can haz it. So there. N, 12/15.
#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>
#include <skills.h>
inherit SPELL;

int bonus,i;

void create() {
    ::create();
    set_author("nienne");
    set_spell_name("curse of despair");
    set_spell_level(([ "warlock" : 2 ]));
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS curse of despair on TARGET");
    set_description("By means of this invocation, the caster places a curse upon the target that will weaken them considerably"
", lowering their defenses and their combat abilities. It is not dispellable by normal magics, but will fade over time.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("will");
}

string query_cast_string() {
    tell_object(caster,"%^BLUE%^Whisps of %^MAGENTA%^shadow %^BLUE%^trail from your fingertips as you weave an invocation.%^RESET%^");
    tell_room(place,"%^BLUE%^Whisps of %^MAGENTA%^shadow %^BLUE%^trail "+caster->QCN+"'s fingers as "+caster->QS+" weaves an invocation.%^RESET%^",caster);
    return "display";
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
    if(do_save(target)){
        tell_object(target,"%^CYAN%^You manage to shake off the dark aura that starts to grow around you, and it fades away to nothing!%^RESET%^");
        tell_room(place,"%^CYAN%^A mirroring aura starts to grow around "+target->QCN+", but then it fades away to nothing.%^RESET%^",target);
        TO->remove();
        return;
    }
    bonus = (clevel+9)/10; // +1 per 10 level bracket - max +4 as per spell description
    if(bonus > 4) bonus = 4;
    duration = (ROUND_LENGTH * 2) * clevel;

    tell_object(target,"%^BLUE%^Mirroring tendrils of gloom thread their way around you, seeping into your skin to taint it a %^RESET%^sic%^GREEN%^k%^RESET%^ly %^BLUE%^pallid hue.  An overwhelming feeling of %^CYAN%^despair %^BLUE%^comes over you.%^RESET%^");
    tell_room(place,"%^BLUE%^Mirroring tendrils of gloom thread their way around "+target->QCN+", seeping into "+target->QP+" skin to taint it a %^RESET%^sic%^GREEN%^k%^RESET%^ly %^BLUE%^pallid hue.%^RESET%^",target);
    target->add_damage_bonus((-1)*bonus);
    target->add_attack_bonus((-1)*bonus);
    target->set_property("empowered",(-1)*bonus);
    for(i=0;i<sizeof(CORE_SKILLS);i++) caster->add_skill_bonus(CORE_SKILLS[i],(-1)*bonus);
    caster->add_saving_bonus("all",(-1)*bonus);
    target->set_property("cursed",1);
    spell_duration = duration;
    set_end_time();
    call_out("dest_effect",spell_duration);
    spell_successful();
}

void dest_effect() {
    if(objectp(target)) {
        tell_object(target,"%^CYAN%^The feeling of %^BLUE%^despair %^CYAN%^finally lifts, and with it fades the sickly color of your skin.%^RESET%^");
        tell_room(environment(target),"%^CYAN%^The sickly color of "+target->QCN+"'s skin brightens back into a more healthy shade.%^RESET%^",target);
        target->add_damage_bonus(bonus);
        target->add_attack_bonus(bonus);
        target->set_property("empowered",bonus);
        for(i=0;i<sizeof(CORE_SKILLS);i++) caster->add_skill_bonus(CORE_SKILLS[i],bonus);
        caster->add_saving_bonus("all",bonus);
        target->remove_property("cursed");
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
