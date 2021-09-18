//Updated by ~Circe~ 5/12/08 after conversations with Ares
// Rebalanced (and blasphemy) as it does more damage and effects to every opponent, than higher level spells even do to single foes.
// Now single target, retains damage boost on aligns and various effects; removed half-dmg on save so it wasn't too nerfed.
// Lowered blindness duration, buffed stun duration. N, 5/11.
// Holy Word
#include <std.h>
#include <daemons.h>
#include <spell.h>
#include <magic.h>

inherit SPELL;

void create(){
    ::create();
    set_spell_name("holy word");
    set_spell_level(([ "cleric" : 7,"inquisitor":6 ]));
    set_spell_sphere("enchantment_charm");
    set_syntax("cast CLASS holy word");
    set_description("This spell channels holy magic directly to the caster and releases it at a target in the form of a silent "
"explosion.  Those of evil hearts have the additional chance to be blinded and/or stunned, while those of neutral bent may be "
"stunned briefly.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("reflex");
}

int preSpell(){
   if(!is_good(caster)) {
      tell_object(caster,"Only those of good heart may use this spell.");
      return 0;
   }
   return 1;
}

string query_cast_string(){
   tell_object(caster,"A concussion of power radiates out from "+
      "you as you begin to chant.");
   tell_room(place,"A concussion of power radiates out from "+
      ""+caster->QCN+" as "+caster->QS+" begins to chant.", ({caster}));
   return "display";
}

void spell_effect(int prof){
   int damage,i,j;
   object limb;

   tell_object(caster,"%^BOLD%^%^CYAN%^A ripple of pure %^WHITE%^"+
      "holy power %^CYAN%^radiates out from you, centred upon "+
      target->QCN+"!%^RESET%^");
   tell_object(target,"%^BOLD%^%^CYAN%^A ripple of pure %^WHITE%^"+
      "holy power %^CYAN%^radiates out from "+caster->QCN+
      ", centred upon you!%^RESET%^");
   tell_room(place,"%^BOLD%^%^CYAN%^A ripple of pure %^WHITE%^"+
      "holy power %^CYAN%^radiates out from "+caster->QCN+
      ", centred upon "+target->QCN+"!%^RESET%^",({caster,target}));

if (interactive(target) && is_good(target)){
      tell_object(caster,"%^BOLD%^%^BLUE%^The power of your spell "+
         "thunders through the area with no effect.%^RESET%^");
      dest_effect();
      return;
   }

   limb = target->return_target_limb();
   damage = sdamage;
   if(!interactive(target)){
//Added to always do damage to mobs per conversations with Ares. ~Circe~ 5/12/08
      tell_object(CASTER,"%^BOLD%^The purity of your spell "+
         "blasts into "+target->QCN+"!%^RESET%^");
      tell_room(place,"%^BOLD%^The force of "+CASTER->QCN+"'s "+
         "spell blasts into "+target->QCN+"!%^RESET%^",({target,CASTER}));
      damage_targ(target,limb,damage,"divine");

      if(!do_save(target,-2)) {
         if(!random(3)){
            target->set_temporary_blinded(roll_dice(1,4));
            tell_room(place,"%^CYAN%^"+target->QCN+" stares "+
               "blindly ahead!%^RESET%^",target);
         }
         if(!random(3)){
            target->set_paralyzed((clevel/2),"You are recovering from the holy word!");
            tell_room(place,"%^YELLOW%^"+target->QCN+" freezes "+
               "in place!%^RESET%^",target);
         }
      }
   }
   else{
      if(is_evil(target)) {
         tell_object(target,"%^BOLD%^The force of "+CASTER->QCN+"'s "+
            "spell blasts into you!"+
            "%^RESET%^",({target,CASTER}));
         tell_object(CASTER,"%^BOLD%^The purity of your spell "+
            "blasts into "+target->QCN+"!%^RESET%^");
         tell_room(place,"%^BOLD%^The force of "+CASTER->QCN+"'s "+
            "spell blasts into "+target->QCN+"!"+
            "%^RESET%^",({target,CASTER}));
         damage_targ(target,limb,damage,"divine");

         if(!do_save(target,-2)) {
            if(!random(3)){
               target->set_temporary_blinded(roll_dice(1,4));
               tell_room(place,"%^CYAN%^"+target->QCN+" stares "+
                  "blindly ahead!%^RESET%^",target);
               tell_object(target,"%^CYAN%^You are blinded by "+
                  "the purity of "+caster->QCN+"'s spell!%^RESET%^");
            }
            if(!random(3)){
               target->set_paralyzed((clevel/2),"You are recovering from the holy word!");
               tell_room(place,"%^YELLOW%^"+target->QCN+" freezes "+
                  "in place!%^RESET%^",target);
               tell_object(target,"%^YELLOW%^You are frozen in "+
                  "place from "+caster->QCN+"'s holy word!%^RESET%^");
            }
         }
      }
      else if (is_neutral(target)){
         tell_object(target,"%^BOLD%^The force of "+CASTER->QCN+"'s "+
            "spell strikes you!%^RESET%^",({target,CASTER}));
         tell_object(CASTER,"%^BOLD%^The purity of your spell "+
            "strikes "+target->QCN+"!%^RESET%^");
         tell_room(place,"%^BOLD%^The force of "+CASTER->QCN+"'s "+
            "spell strikes "+target->QCN+"!%^RESET%^",({target,CASTER}));
         damage_targ(target,limb,damage,"divine");

         if(!do_save(target)) {
            if(!random(3)){
               target->set_paralyzed((clevel/2),"You are recovering from the holy word!");
               tell_room(place,"%^YELLOW%^"+target->QCN+" freezes "+
                  "in place!%^RESET%^",target);
               tell_object(target,"%^YELLOW%^You are frozen in "+
                  "place from "+caster->QCN+"'s holy word!%^RESET%^");
            }
         }
      }
      else if(is_good(target)){
         tell_object(target,"%^BOLD%^The force of "+CASTER->QCN+"'s "+
            "spell strikes you!%^RESET%^",({target,CASTER}));
         tell_object(CASTER,"%^BOLD%^The purity of your spell "+
            "strikes "+target->QCN+"!%^RESET%^");
         tell_room(place,"%^BOLD%^The force of "+CASTER->QCN+"'s "+
            "spell strikes "+target->QCN+"!"+
            "%^RESET%^",({target,CASTER}));
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
