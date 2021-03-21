#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>
inherit SPELL;

int current;

void create() {
    ::create();
    set_spell_name("powerword blind");
    set_spell_level(([ "mage" : 7, "cleric" : 7 ]));
    set_domains("war");
    set_spell_sphere("enchantment_charm");
    set_syntax("cast CLASS powerword blind on TARGET");
    set_description("When the powerword stun blind is uttered, any creature of the caster's choice is blinded, reeling and unable to think coherently or to act for a duration dependent on the creature's current hit points.");
    mental_spell();
    mental_spell(1);
    set_verbal_comp();
    set_target_required(1);
}

void spell_effect(int prof) {
    int hpmin,hpmax, hpmax2, x;

    if (!present(target,environment(caster))) {
        tell_object(caster,"%^BOLD%^Your target is not in this area.\n");
        dest_effect();
        return;
    }
    tell_object(caster,"%^BOLD%^%^GREEN%^You take in a deep breath and scream the words, 'SIGTHUS DISAPPEERUS!!!'");
    tell_room(place,"%^BOLD%^%^GREEN%^"+caster->QCN+" takes in a deep breath and screams the words, 'SIGTHUS DISAPPEERUS!!!'",({caster}));


   if(mind_immunity_damage(target))
   {
        spell_successful();
        dest_effect();
        return;
   }

   current = target->query_hp();
   hpmax = target->query_max_hp();
   x = (current*100)/hpmax;
   if(x>90){
      tell_object(caster,"%^BOLD%^"+target->QCN+" reels backward, slightly blinded by the power of your spell!");
      tell_object(target,"%^BOLD%^You reel backward, slightly blinded by the power of "+caster->QCN+"'s spell!");
      tell_room(place,"%^BOLD%^"+target->QCN+" reels backward, slightly blinded by the power of "+caster->QCN+"'s spell!",({caster, target}));
      target->set_temporary_blinded(roll_dice(2,4),"The force of the spell has left you blinded.");
   }else if(x>50){
      tell_object(caster,"%^BOLD%^"+target->QCN+" reels backward, blinded by the power of your spell!");
      tell_object(target,"%^BOLD%^You reel backward, blinded by the power of "+caster->QCN+"'s spell!");
      tell_room(place,"%^BOLD%^"+target->QCN+" reels backward, blinded by the power of "+caster->QCN+"'s spell!",({caster, target}));
      target->set_temporary_blinded(roll_dice(2,8),"The force of the spell has left you blinded.");
   }else{
      tell_object(caster,"%^BOLD%^"+target->QCN+" reels backward, completely blinded by the power of your spell!");
      tell_object(target,"%^BOLD%^You reel backward, completely blinded by the power of "+caster->QCN+"'s spell!");
      tell_room(place,"%^BOLD%^"+target->QCN+" reels backward, completely blinded by the power of "+caster->QCN+"'s spell!",({caster, target}));
      target->set_temporary_blinded(roll_dice(2,16),"The force of the spell has left you blinded.");
   }

   spell_successful();
   dest_effect();
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
