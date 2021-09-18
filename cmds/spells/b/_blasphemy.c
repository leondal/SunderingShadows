//Updated by ~Circe~ 5/12/08 after conversations with Ares
// Rebalanced (and holy word) as it does more damage and effects to every opponent, than higher level spells even do to single foes.
// Now single target, retains damage boost on aligns and various effects; removed half-dmg on save so it wasn't too nerfed.
// Lowered blindness duration, buffed stun duration. N, 5/11.
#include <std.h>
#include <daemons.h>
#include <spell.h>
#include <magic.h>

inherit SPELL;

void create(){
    ::create();
    set_author("ares");
    set_spell_name("blasphemy");
    set_spell_level(([ "cleric" : 7, "inquisitor" : 6 ]));
    set_spell_sphere("enchantment_charm");
    set_spell_domain("evil");
    evil_spell(1);
    set_syntax("cast CLASS blasphemy");
    set_description("This spell channels unholy magic directly to the caster and releases it at a target in the form of a silent "
"explosion.  Those of good hearts have the additional chance to be blinded and/or stunned, while those of neutral bent may be "
"stunned briefly.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("reflex");
}

int preSpell(){
   if(!is_evil(caster)){
      tell_object(caster,"Only those of evil intent may use this spell.");
      return 0;
   }
   return 1;
}

string query_cast_string(){
   tell_object(caster,"%^RED%^You feel a concussion of power that radiates"+
      " out from you as you chant through the vile and profane prayer.");
   tell_room(place,"%^RED%^A concussion of power radiates out from"+
      " "+caster->QCN+" as "+caster->QS+" begins to chant a vile "+
      "and profane prayer.",caster);
   return "display";
}

void spell_effect(int prof){
   int damage,i,j;
   object limb;

   tell_object(caster,"%^BOLD%^%^BLACK%^A ripple of pure unholy power "+
      "radiates out from you, sending "+target->QCN+" staggering as you "+
      "shout out!%^RESET%^");
   caster->force_me("yell %^BOLD%^%^RED%^B%^RESET%^%^RED%^L%^BOLD%^"+
      "%^BLACK%^A%^RED%^S%^RESET%^%^RED%^P%^BOLD%^H%^BOLD%^%^BLACK%^E"+
      "%^RED%^M%^RESET%^%^RED%^Y!!!");
   tell_object(target,"%^BOLD%^%^BLACK%^A ripple of pure unholy power "+
      "radiates out at you from "+caster->QCN+" as "+caster->QS+" shouts "+
      "out!%^RESET%^");
   tell_room(place,"%^BOLD%^%^BLACK%^A ripple of pure unholy power "+
      "radiates out at "+target->QCN+" from "+caster->QCN+" as "
      +caster->QS+" shouts out!%^RESET%^",({caster,target}));

   if (interactive(target) && target->query_level() < 6) {
      tell_object(caster,"%^BOLD%^%^RED%^The power of your "+
         "spell thunders through the area with no effect.%^RESET%^");
      dest_effect();
      return;
   }

   limb = target->return_target_limb();
   damage = sdamage;
   if(!interactive(target)){
      tell_object(CASTER,"%^BOLD%^%^BLACK%^The hatred of your spell "+
         "slams into "+target->QCN+"!%^RESET%^");
      tell_room(place,"%^BOLD%^%^BLACK%^The force of "+CASTER->QCN+"'s "+
         "spell slams into "+target->QCN+"!"+
         "%^RESET%^",({target,CASTER}));
      damage_targ(target,limb,damage,"divine");

      if(!do_save(target,-2)) {
         if(!random(3)){
            target->set_temporary_blinded(roll_dice(1,4));
            tell_room(place,"%^RED%^"+target->QCN+" stares "+
               "blindly ahead!%^RESET%^",target);
         }
         if(!random(3)){
            target->set_paralyzed((clevel/4),"You are recovering from the blasphemy!");
            tell_room(place,"%^GREEN%^"+target->QCN+" freezes "+
               "in place!%^RESET%^",target);
         }
      }
   }
   else{
      if(is_good(target)) {
         tell_object(target,"%^BOLD%^%^BLACK%^The force of "+CASTER->QCN+"'s "+
            "spell slams into you!"+
            "%^RESET%^",({target,CASTER}));
         tell_object(CASTER,"%^BOLD%^%^BLACK%^The hatred of your spell "+
            "slams into "+target->QCN+"!%^RESET%^");
         tell_room(place,"%^BOLD%^%^BLACK%^The force of "+CASTER->QCN+"'s "+
            "spell slams into "+target->QCN+"!"+
            "%^RESET%^",({target,CASTER}));
         damage_targ(target,limb,damage,"divine");

         if(!do_save(target,-2)) {
            if(!random(3)){
               target->set_temporary_blinded(roll_dice(1,4));
               tell_room(place,"%^RED%^"+target->QCN+" stares "+
                  "blindly ahead!%^RESET%^",target);
               tell_object(target,"%^RED%^You are blinded by "+
                  "the taint of "+caster->QCN+"'s spell!%^RESET%^");
            }
            if(!random(3)){
               target->set_paralyzed((clevel/2),"You are recovering from the blasphemy!");
               tell_room(place,"%^GREEN%^"+target->QCN+" freezes "+
                  "in place!%^RESET%^",target);
               tell_object(target,"%^GREEN%^You are frozen in "+
                  "place from "+caster->QCN+"'s blasphemy!%^RESET%^");
            }
         }
      }
      else if (is_neutral(target)){
         tell_object(target,"%^BOLD%^%^BLACK%^The force of "+CASTER->QCN+"'s "+
            "spell slams into you!%^RESET%^",({target,CASTER}));
         tell_object(CASTER,"%^BOLD%^%^BLACK%^The hatred of your spell "+
            "slams into "+target->QCN+"!%^RESET%^");
         tell_room(place,"%^BOLD%^%^BLACK%^The force of "+CASTER->QCN+"'s "+
            "spell slams into "+target->QCN+"!%^RESET%^",({target,CASTER}));
         damage_targ(target,limb,damage,"divine");

         if(!do_save(target)) {
            if(!random(3)){
               target->set_paralyzed((clevel/2),"You are recovering from the blasphemy!");
               tell_room(place,"%^GREEN%^"+target->QCN+" freezes "+
                  "in place!%^RESET%^",target);
               tell_object(target,"%^GREEN%^You are frozen in "+
                  "place from "+caster->QCN+"'s blasphemy!%^RESET%^");
            }
         }
      }
      else if(is_evil(target)){
         tell_object(target,"%^BOLD%^%^BLACK%^The force of "+CASTER->QCN+"'s "+
            "spell strikes you!%^RESET%^",({target,CASTER}));
         tell_object(CASTER,"%^BOLD%^%^BLACK%^The hatred of your spell "+
            "strikes "+target->QCN+"!%^RESET%^");
         tell_room(place,"%^BOLD%^%^BLACK%^The force of "+CASTER->QCN+"'s "+
            "spell strikes "+target->QCN+"!%^RESET%^",({target,CASTER}));
         define_base_damage(-2);
         damage = sdamage;
         if(damage>0)
            damage_targ(target,limb,damage,"divine");
      }
   }
   spell_successful();
   dest_effect();
}

void dest_effect(){
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
