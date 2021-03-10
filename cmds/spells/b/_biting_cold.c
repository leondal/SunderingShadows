#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>
inherit SPELL;

int mylevel,counter;
object *inven;

void zapper();
void zap_again();

void create() {
    ::create();
    set_spell_name("biting cold");
    set_spell_level(([ "psywarrior" : 5, "psion" : 5 ]));
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS biting cold on TARGET");
    set_description("Upon manifesting this power, the psywarrior manipulates "
       "the elemental planes, summoning cold to himself. Concentrating the "
       "icy power in his core, he lashes out, freezing his target. The victim "
       "experiences cold damage and may have their movement impaired for a time.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("fort");
}

int preSpell()
{
    if(objectp(target) && target->query_property(CASTER->query_name() + "_biting_cold"))
    {
        tell_object(caster,"You have already summoned biting cold to torment that target!");
        return 0;
    }
    return 1;
}

string query_cast_string() {
   tell_room(environment(caster),"%^BOLD%^%^BLUE%^"+caster->QCN+" raises a hand, palm out, as %^RESET%^"
       "%^CYAN%^f%^BOLD%^r%^WHITE%^o%^CYAN%^s%^RESET%^%^CYAN%^t %^BOLD%^%^BLUE%^"
       "swirls from "+caster->QP+" fingertips.%^RESET%^",caster);
   tell_object(caster,"%^BOLD%^%^BLUE%^You raise your hand, palm out, as %^RESET%^"
       "%^CYAN%^f%^BOLD%^r%^WHITE%^o%^CYAN%^s%^RESET%^%^CYAN%^t %^BOLD%^%^BLUE%^"
       "swirls from your fingertips.%^RESET%^");
   return "display";
}

void spell_effect(int prof) {
     mylevel = clevel;
     counter = mylevel/10;
     if(counter < 1) counter = 1;
     counter += 2;
     if(interactive(caster)){
          tell_object(caster,"%^CYAN%^You open your mind, forming a conduit to channel "
                      "sheer %^BOLD%^cold%^RESET%^%^CYAN%^ that concentrates in your palm.%^RESET%^");
          tell_room(place, "%^CYAN%^"+caster->QCN+"'s palm glows a %^BLUE%^f%^BOLD%^r"
                    "%^RESET%^%^CYAN%^o%^BOLD%^s%^WHITE%^ty %^CYAN%^b%^RESET%^%^CYAN%^l%^BOLD%^"
                    "%^BLUE%^u%^RESET%^%^BLUE%^e %^CYAN%^that intensifies to a brilliant %^BOLD%^"
                    "%^WHITE%^wh%^CYAN%^i%^WHITE%^te%^RESET%^%^CYAN%^.%^RESET%^", ({caster}) );
          call_out("zapper",4);
     }else{
          zapper();
     }
     spell_successful();
}

void zapper(){
   int i,effect,damage;
   inven = ({});

   if(!objectp(target) || !objectp(environment(caster)) || !present(target, environment(caster))){
      tell_object(caster,"%^BLUE%^The frigid energy dissipates as your target is nowhere to be seen.%^RESET%^");
      tell_room(place,"%^BLUE%^"+caster->QCN+"'s palm ceases to glow as "+caster->QP+" normal color returns.%^RESET%^", caster);
      dest_effect();
      return;
   }
   counter--;
   damage = sdamage;
   tell_room(place,"%^BOLD%^%^CYAN%^A blast of %^RESET%^%^BLUE%^a%^BOLD%^r%^RESET%^"
      "%^CYAN%^c%^BOLD%^t%^RESET%^i%^BOLD%^c e%^RESET%^n%^BOLD%^%^CYAN%^e%^RESET%^"
      "%^CYAN%^r%^BOLD%^%^BLUE%^g%^RESET%^%^BLUE%^y %^BOLD%^%^CYAN%^explodes from "
      ""+caster->QCN+"'s palm, hurtling toward "+target->QCN+"!%^RESET%^",({caster,target}));
   tell_object(caster,"%^BOLD%^%^CYAN%^A blast of %^RESET%^%^BLUE%^a%^BOLD%^r%^RESET%^"
      "%^CYAN%^c%^BOLD%^t%^RESET%^i%^BOLD%^c e%^RESET%^n%^BOLD%^%^CYAN%^e%^RESET%^"
      "%^CYAN%^r%^BOLD%^%^BLUE%^g%^RESET%^%^BLUE%^y %^BOLD%^%^CYAN%^explodes from "
      "your palm, hurtling toward "+target->QCN+"!%^RESET%^");
   tell_object(target,"%^BOLD%^%^CYAN%^A blast of %^RESET%^%^BLUE%^a%^BOLD%^r%^RESET%^"
      "%^CYAN%^c%^BOLD%^t%^RESET%^i%^BOLD%^c e%^RESET%^n%^BOLD%^%^CYAN%^e%^RESET%^"
      "%^CYAN%^r%^BOLD%^%^BLUE%^g%^RESET%^%^BLUE%^y %^BOLD%^%^CYAN%^explodes from "
      ""+caster->QCN+"'s palm, hurtling toward you!%^RESET%^");

   if(do_save(target,0)) {
/*
      if(evade_splash(target)){
         tell_object(target,"%^RESET%^%^CYAN%^Your reflexes are so fast, you avoid the incoming arctic blast!%^RESET%^");
         tell_room(place,"%^RESET%^%^CYAN%^"+target->QCN+" dodges quickly, avoiding the incoming arctic blast!%^RESET%^",target);
         return;
      }
*/
      damage = damage/2;
   }

   tell_object(target,"%^BOLD%^%^BLUE%^The %^RESET%^%^BLUE%^a%^BOLD%^r%^RESET%^"
      "%^CYAN%^c%^BOLD%^t%^RESET%^i%^BOLD%^c %^RESET%^b%^BOLD%^%^CYAN%^l%^RESET%^"
      "%^CYAN%^a%^BOLD%^%^BLUE%^s%^RESET%^%^BLUE%^t %^BOLD%^slams into you, "
      "draining you of heat in a cloud of %^RESET%^%^CYAN%^v%^BOLD%^a%^WHITE%^p"
      "%^CYAN%^o%^RESET%^%^CYAN%^r%^BOLD%^%^BLUE%^!%^RESET%^");
   tell_room(place,"%^BOLD%^%^BLUE%^The %^RESET%^%^BLUE%^a%^BOLD%^r%^RESET%^"
      "%^CYAN%^c%^BOLD%^t%^RESET%^i%^BOLD%^c %^RESET%^b%^BOLD%^%^CYAN%^l%^RESET%^"
      "%^CYAN%^a%^BOLD%^%^BLUE%^s%^RESET%^%^BLUE%^t %^BOLD%^slams into "+target->QCN+", "
      "obscuring "+target->QO+" in a cloud of %^RESET%^%^CYAN%^v%^BOLD%^a%^WHITE%^p"
      "%^CYAN%^o%^RESET%^%^CYAN%^r%^BOLD%^%^BLUE%^!%^RESET%^",target);
   damage_targ(target,"torso",damage,"cold");
   if(!do_save(target,0)){ //if they fail a second save, they are chilled
//      if(!evade_splash(target)){
         tell_object(target,"%^BOLD%^%^WHITE%^The %^CYAN%^chill%^WHITE%^ saps your strength, making it difficult to move!%^RESET%^");
         tell_object(caster,"%^BOLD%^%^WHITE%^The %^CYAN%^chill%^WHITE%^ seeps into "+target->QCN+"'s bones, slowing "+target->QO+"!%^RESET%^");
         target->set_disable((mylevel/4),target);
         target->set_property("added short",({ "%^CYAN%^( chilled )%^RESET%^"}));
//      }
   }
   target->set_property(CASTER->query_name() + "_biting_cold",1);
   call_out("zap_again", ROUND_LENGTH);
}

void zap_again()
{
   int damage;
   if(!objectp(target))
   {
       dest_effect();
       return;
   }
   if(!present(target,environment(caster)))
   {
      target->remove_property_value("added short",({ "%^CYAN%^( chilled )%^RESET%^"}));
      target->remove_property(CASTER->query_name() + "_biting_cold");
   }
   if(counter < 1)
   {
       dest_effect();
       return;
   }
   counter--;
   damage = roll_dice(mylevel,4);
   if(do_save(target,0)) {
/*      if(evade_splash(target)){
         tell_object(target,"%^RESET%^%^CYAN%^Your reflexes are so fast, you avoid the incoming arctic blast!%^RESET%^");
         tell_room(place,"%^RESET%^%^CYAN%^"+target->QCN+" dodges quickly, avoiding the incoming arctic blast!%^RESET%^",target);
         return;
      }
*/
      damage = damage/2;
   }
   tell_object(target,"%^BOLD%^%^BLUE%^The relentless %^RESET%^%^BLUE%^a%^BOLD%^r%^RESET%^"
      "%^CYAN%^c%^BOLD%^t%^RESET%^i%^BOLD%^c %^RESET%^b%^BOLD%^%^CYAN%^l%^RESET%^"
      "%^CYAN%^a%^BOLD%^%^BLUE%^s%^RESET%^%^BLUE%^t %^BOLD%^slams into you once more!%^RESET%^");
   tell_room(environment(target),"%^BOLD%^%^BLUE%^The relentless %^RESET%^%^BLUE%^a%^BOLD%^r%^RESET%^"
      "%^CYAN%^c%^BOLD%^t%^RESET%^i%^BOLD%^c %^RESET%^b%^BOLD%^%^CYAN%^l%^RESET%^"
      "%^CYAN%^a%^BOLD%^%^BLUE%^s%^RESET%^%^BLUE%^t %^BOLD%^slams into "+target->QCN+" once more!%^RESET%^",target);
   damage_targ(target,"torso",damage,"cold");
   call_out("zap_again", ROUND_LENGTH);
}

void dest_effect(){
   if(objectp(target)){
      tell_object(target,"%^RESET%^%^ORANGE%^Warmth returns to your body, allowing you to move more freely.%^RESET%^");
      target->remove_property_value("added short",({ "%^CYAN%^( chilled )%^RESET%^"}));
      target->remove_property(CASTER->query_name() + "_biting_cold");
   }
   if(objectp(caster)){
      tell_object(caster,"%^RESET%^%^ORANGE%^The cold recedes from the air, filling you with warmth.%^RESET%^");
   }
   ::dest_effect();
   if(objectp(TO)) TO->remove();
}
