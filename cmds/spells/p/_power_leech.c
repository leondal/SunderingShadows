//~Circe~ 7/29/05
#include <spell.h>
#include <magic.h>

inherit SPELL;

void create() {
    ::create();
    set_spell_name("power leech");
    set_spell_level(([ "psion" : 4 ]));
    set_spell_sphere("telepathy");
    mental_spell();
    set_syntax("cast CLASS power leech on TARGET");
    set_description("This power, when manifested, will cause the psion to gather his energy, focusing on the target.  The "
"psion will then reach out, attempting to touch the target.  Should he succeed, he will empathically deliver damage to "
"the target, while healing his own wounds for the same amount.  Note: The psion cannot gain extra hit points through this "
"power.  He simply heals what he has already lost.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
}

void spell_effect(int prof) {
    int damage,num,max,hp_before,mybonus,mylevel;
    string target_limb;
    object env;
    damage = 0;
    spell_successful();
    mylevel = clevel;
    max = mylevel/2;
    if(max < 1) max = 1; //shouldn't be possible, but better safe than sorry
    if(max > 25) max = 25;
    for (num=0;num < max;num++) {
        damage += roll_dice(1,8);
    }
    target_limb = target->return_target_limb();
    if (interactive(caster)) {
        tell_object(caster,"%^BOLD%^%^WHITE%^Focusing your mind on "+
           ""+target->QCN+", you reach out to touch "+target->QO+"!");
    }
    tell_object(target,"%^BOLD%^%^WHITE%^"+caster->QCN+" reaches out "+
       "a hand, attempting to touch you!");
    tell_room(place,"%^BOLD%^%^WHITE%^"+caster->QCN+" reaches out "+
       "a hand, attempting to touch "+target->QCN+"!",({caster, target}));
    env = environment(caster);
    if(!present(target,env)){
        tell_object(caster,"%^BOLD%^%^CYAN%^Your target has escaped!");
        TO->remove();
        return;
    }
    if(!caster->ok_to_kill(target)) {
        tell_object(caster,"A higher power prevents you from harming "+target->QCN+".");
        dest_effect();
        return 0;
    }
    mybonus = (int)caster->query_class_level("psion");
    mybonus = mybonus/3;
    if(mybonus > 8) mybonus = 8;
/*    if ((caster->is_class("psion")&&sizeof((string *)caster->query_classes())==1)?(int)caster->Thaco(0,target,0) <= roll_dice(1,20)+5:(int)caster->Thaco(0,target,0) <= roll_dice(1,20)) {*/
    if ((caster->is_class("psion")&&sizeof((string *)caster->query_classes())==1)?(int)caster->Thaco(0,target,0,"cleric") <= roll_dice(1,20)+10+mybonus:(int)caster->Thaco(0,target,0,"cleric") <= roll_dice(1,20)+5+mybonus) {
//Changed the roll above because the power *never* hit.  This seems balanced
//after testing.  I will continue watching and adjust as needed.  Circe 11/27/07
       tell_object(target,"%^BOLD%^%^BLACK%^As "+caster->QCN+" touches "+
          "you, you feel your body wracked with pain!");
       tell_room(place,"%^BOLD%^%^BLACK%^"+caster->QCN+" touches "+
          ""+target->QCN+" on the "+target_limb+", making "+target->QO+" "+
          "grow pallid!", ({target, caster}));
       tell_object(caster,"%^BOLD%^%^BLACK%^With rancor, you touch "+
          ""+target->QCN+"'s "+target_limb+" and steal some of "+
          ""+target->QP+" life force away!");
       hp_before = target->query_hp();
       damage_targ(target, target_limb, damage,"mental");
       if (!objectp(target))
           damage_targ(caster, target_limb, (-hp_before),"mental");
       else
           damage_targ(caster, target_limb, (-damage),"mental");
    }else{
        tell_object(target,"%^BOLD%^%^BLACK%^"+caster->QCN+" fails to touch you!");
        tell_room(place,"%^BOLD%^%^BLACK%^"+caster->QCN+" fails to touch "+target->QCN+"!", ({target, caster}));
        tell_object(caster,"%^BOLD%^%^BLACK%^You fail to touch "+target->QCN+"!");
        spell_kill(target, caster);
    }
    dest_effect();
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
