// based on bestow curse. -Nienne
#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>
#include <skills.h>
inherit SPELL;

int bonus,i;

void create()
{
    ::create();
    set_author("nienne");
    set_spell_name("crushing despair");
    set_spell_level(([ "bard" : 3, "mage" : 4 ]));
    set_spell_sphere("enchantment_charm");
    set_syntax("cast CLASS crushing despair on TARGET");
    set_description("By means of this spell, the caster invokes a tangible feeling of despair over their target, "
                    "attempting to sap their morale. It will inflict a penalty to the target's attacks, damage, core skills, saving "
                    "throws and spellpower. Such an effect is not dispellable by normal magics, but will fade over time.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    mental_spell(1);
    set_save("will");
}

string query_cast_string() {
    return "%^BLUE%^A dark aura threads its way around "+caster->QCN+"'s fingers as "
+caster->QS+" intones a spell.%^RESET%^";
}

void spell_effect(int prof) {
    int duration;
    if(target == caster) {
        tell_object(caster, "%^CYAN%^You realise your error in targetting yourself, and let your spell fade away.%^RESET%^");
        tell_room(place,"%^CYAN%^The aura around "+caster->QCN+"'s hands weakens and then fades away.%^RESET%^",caster);
        TO->remove();
        return;
    }
    if(target->query_property("crushing_despair")) {
        tell_object(caster,"%^CYAN%^Your spell slips away from "+target->QCN+", unable to weaken them further!%^RESET%^");
        tell_room(place,"%^CYAN%^The aura around "+caster->QCN+"'s hands weakens and then fades away.%^RESET%^",caster);
        TO->remove();
        return;
    }
    if (do_save(target, 2) || mind_immunity_damage(target)) {
        tell_object(target, "%^CYAN%^You manage to shake off the dark aura that starts to grow around you, and it fades "
                    "away to nothing!%^RESET%^");
        tell_room(place, "%^CYAN%^A mirroring aura starts to grow around " + target->QCN + ", but then it fades away to "
                  "nothing.%^RESET%^", target);
        TO->remove();
        return;
    }
    bonus = clevel/8;
    duration = (ROUND_LENGTH) * (clevel / 12 + 1);

    tell_object(target,"%^BLUE%^A mirroring aura starts to grow around you, seeping into your skin as an overwhelming "
"feeling of %^MAGENTA%^de%^BLUE%^s%^MAGENTA%^pa%^BLUE%^i%^MAGENTA%^r %^BLUE%^comes over you.%^RESET%^");
    tell_room(place,"%^BLUE%^A mirroring aura starts to grow around "+target->QCN+", seeping into "+target->QP+" skin as "
"an expression of utter %^MAGENTA%^de%^BLUE%^s%^MAGENTA%^pa%^BLUE%^i%^MAGENTA%^r %^BLUE%^washes over "+target->QP+
" features.%^RESET%^",target);
    target->add_damage_bonus((-1) * bonus);
    target->add_attack_bonus((-1) * bonus);
    target->set_property("empowered", (-1) * bonus);
    for (i = 0; i < sizeof(CORE_SKILLS); i++) {
        caster->add_skill_bonus(CORE_SKILLS[i], (-1) * bonus);
    }
    caster->add_saving_bonus("all", (-1) * bonus);
    target->set_property("crushing_despair", 1);
    spell_duration = duration;
    set_end_time();
    call_out("dest_effect",spell_duration);
    spell_successful();
}

void dest_effect() {
    if(objectp(target)) {
        tell_object(target,"%^CYAN%^The feeling of despair finally lifts, and you feel normal again.%^RESET%^");
        tell_room(environment(target),"%^CYAN%^"+target->QCN+"'s expression of despair finally lifts.%^RESET%^",target);
        target->add_damage_bonus(bonus);
        target->add_attack_bonus(bonus);
        target->set_property("empowered",bonus);
        for(i=0;i<sizeof(CORE_SKILLS);i++) caster->add_skill_bonus(CORE_SKILLS[i],bonus);
        caster->add_saving_bonus("all",bonus);
        target->remove_property("crushing_despair");
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
