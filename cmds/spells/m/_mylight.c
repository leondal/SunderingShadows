// mylight
// adapted by ~Circe~ 7/19/05
// reworked by ~Circe~ 9/27/15 to function as a sight bonus rather than a light
#include <spell.h>
#include <magic.h>
#include <std.h>
#include <daemons.h>

inherit SPELL;

void create() {
    ::create();
    set_spell_name("mylight");
    set_spell_level(([ "psion" : 1, "psywarrior" : 1 ]));
    set_spell_sphere("psychometabolism");
    set_syntax("cast CLASS mylight on TARGET");
    set_description("When the psionic character manifests this power, "
       "the target receives a sight bonus to help him see. Races with "
       "aversion to light will be able to see in brighter surroundings, "
       "while those who need light to see will be able to peer through the darkness.");
    set_target_required(1);
    set_helpful_spell(1);
    set_helpful_spell(1);
}

spell_effect(int prof) {
    int level;

    if(!objectp(target)) target = caster;
    if (interactive(caster)) {
       if(target == caster){
          tell_object(caster,"%^YELLOW%^You focus your mental energies inward, negating some of the effects of light levels.%^RESET%^");
          tell_room(place,"%^YELLOW%^"+caster->QCN+"'s eyes flash briefly as "+caster->QS+" concentrates.%^RESET%^",caster);
       }else{
          tell_object(caster,"%^YELLOW%^You focus your mental energies on "
             ""+target->QCN+", helping "+target->QO+" ignore the detrimental "
             "effects of light levels.%^RESET%^");
          tell_room(place,"%^YELLOW%^"+caster->QCN+"'s eyes flash briefly as "
             ""+caster->QS+" concentrates on "+target->QCN+".%^RESET%^", ({caster, target}));
          if(interactive(target))
             tell_object(target, "%^YELLOW%^"+caster->QCN+" focuses "+caster->QP+" "
             "attention on you, and you feel a flood of power that helps you ignore "
             "the effects of light levels.%^RESET%^");
       }
    }
    if(objectp(target)){
       if(member_array(target->query_race(),PLAYER_D->night_races()) == -1){
          target->add_sight_bonus(3);
       }else{
          target->add_sight_bonus(-3);
       }
    }
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH * 10;
    set_end_time();
    call_out("dest_effect",spell_duration);
    spell_successful();
}

void dest_effect()
{
    if(find_call_out("dest_effect") != -1) remove_call_out("dest_effect");

    if(objectp(target))
    {
       tell_object(target,"%^RESET%^%^ORANGE%^Your vision returns to normal "
       "as the psionic power fades from your sight.%^RESET%^");
       if(member_array(target->query_race(),PLAYER_D->night_races()) == -1){
          target->add_sight_bonus(-3);
       }else
       {
          target->add_sight_bonus(3);
       }
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
