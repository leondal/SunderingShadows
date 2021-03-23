//Powerword Stun coded by Bane//
//After discussions with other Imms, I've removed the save but lowered
//the duration to make it more in line with the books.
//Microcosm got the same changes. ~Circe~ 8/6/13
#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>
inherit SPELL;

int current;

void create() {
    ::create();
    set_spell_name("powerword stun");
    set_spell_level(([ "mage" : 8, "cleric" : 8 ]));
    set_domains("suffering");
    set_spell_sphere("enchantment_charm");
    set_syntax("cast CLASS powerword stun on TARGET");
    set_description("When the powerword stun spell is uttered, any creature of the caster's choice is stunned, reeling "
"and unable to think coherently or to act for a duration dependent on the creature's current hit points.");
    mental_spell();
    set_verbal_comp();
    set_silent_casting(1);
    set_target_required(1);
}

void spell_effect(int prof) {
    int hpmin,hpmax, hpmax2, x;

    if (!present(target,environment(caster))) {
        tell_object(caster,"%^BOLD%^Your target is not in this area.\n");
        dest_effect();
        return;
    }
    tell_object(caster,"%^BOLD%^%^GREEN%^You take in a deep breath and scream the words, 'HARRNES RUCKONUS!!!'");
    tell_room(place,"%^BOLD%^%^GREEN%^"+caster->QCN+" takes in a deep breath and screams the words, 'HARRNES RUCKONUS!!!'",({caster}));
    spell_kill(target, caster);
    if(!caster->ok_to_kill(target)) {
        dest_effect();
        return;
    }
   if(target->query_property("no hold") || target->query_property("no paralyze")) {
   tell_object(target,"%^YELLOW%^The spell disperses futilely around you.");
       tell_room(place,"%^YELLOW%^The spell disperses futilely around "+target->QCN+".",({target}));
      dest_effect();
      return;
   }

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
      tell_object(caster,"%^BOLD%^"+target->QCN+" reels backward, slightly dazed by the power of your spell!");
      tell_object(target,"%^BOLD%^You reel backward, slightly dazed by the power of "+caster->QCN+"'s spell!");
      tell_room(place,"%^BOLD%^"+target->QCN+" reels backward, slightly dazed by the power of "+caster->QCN+"'s spell!",({caster, target}));
      target->set_paralyzed(roll_dice(1,2)*8,"The force of the spell has left you stunned.");
   }else if(x>50){
      tell_object(caster,"%^BOLD%^"+target->QCN+" reels backward, stunned by the power of your spell!");
      tell_object(target,"%^BOLD%^You reel backward, stunned by the power of "+caster->QCN+"'s spell!");
      tell_room(place,"%^BOLD%^"+target->QCN+" reels backward, stunned by the power of "+caster->QCN+"'s spell!",({caster, target}));
      target->set_paralyzed(roll_dice(1,4)*8,"The force of the spell has left you stunned.");
   }else{
      tell_object(caster,"%^BOLD%^"+target->QCN+" reels backward, completely stunned by the power of your spell!");
      tell_object(target,"%^BOLD%^You reel backward, completely stunned by the power of "+caster->QCN+"'s spell!");
      tell_room(place,"%^BOLD%^"+target->QCN+" reels backward, completely stunned by the power of "+caster->QCN+"'s spell!",({caster, target}));
      target->set_paralyzed(roll_dice(1,8)*8,"The force of the spell has left you stunned.");
   }
   spell_successful();
   dest_effect();
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
