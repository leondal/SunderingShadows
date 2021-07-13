//Screen - Illusion domain spell by ~Circe~ based on detect scrying
//and protection from scrying.  Part of the rebalancing of domain
//spells 5/5/08

#include <spell.h>
#include <magic.h>
#include <daemons.h>

#define SCRY_D "/daemon/ic_scry_locate_d"

inherit SPELL;

object detector, blocker;

void create() {
    ::create();
    set_spell_name("screen");
    set_spell_level(([ "oracle" : 8, "mage": 8 ]));
    set_spell_sphere("illusion");
    set_mystery("lore");
    set_syntax("cast CLASS screen");
    set_description("Upon casting this spell, the user creates a screen of illusion centered upon himself that makes "
"scrying attempts difficult.  This spell has a chance to both detect and block scrying attempts, with the chance for "
"success determined by the level of the priest against the level of the scryer.  The spell is centered upon the caster "
"and will move with him, allowing him to sweep areas for the duration of the spell.\n\nWhen a scrying attempt is detected"
", the scryer must immediately roll a saving throw.  If this is failed, the appearance and general location of the scryer "
"immediately become known to the one who cast this spell.  The general location is the room and area where the scryer "
"is located at the time.\n\nThis spell can only be cast while at peace.");
    set_verbal_comp();
    set_somatic_comp();
    set_peace_needed(1);
	set_helpful_spell(1);
}

string query_cast_string(){
   tell_object(caster,"%^CYAN%^You gesture gracefully with your "+
      "hands, weaving an illusion to confuse those who attempt "+
      "to view you from afar.%^RESET%^");
   tell_room(place,"%^CYAN%^"+caster->QCN+" gestures gracefully "+
      "with "+caster->QP+" hands, almost as if weaving.%^RESET%^",caster);
   return "display";
}

void spell_effect(int prof) {
   int num, duration, wis_bonus, power;
   object temp;

   ::spell_effect();

   if(temp = caster->query_property("detect scrying")){
      if(!objectp(temp)){
         caster->remove_property("detect scrying");
      }else{
         tell_object(caster,"%^BOLD%^RED%^You are already detecting "+
            "scrying attempts!");
         TO->remove();
         return;
      }
   }
   if(temp = caster->query_property("block scrying")){
      if(!objectp(temp)){
         caster->remove_property("block scrying");
      }else{
         tell_object(caster,"%^BOLD%^RED%^There is already blocking "+
            "magic working for that target!");
         TO->remove();
         return;
      }
   }
   tell_room(place,"%^BOLD%^%^CYAN%^The air around "+caster->QCN+" "+
      "s%^RESET%^%^CYAN%^h%^BOLD%^i%^RESET%^%^CYAN%^m%^BOLD%^m"+
      "%^RESET%^%^CYAN%^e%^BOLD%^r%^RESET%^%^CYAN%^s %^BOLD%^with "+
      "shifting images for a moment before growing still.%^RESET%^",caster);
   tell_object(caster,"%^BOLD%^%^CYAN%^The air around you "+
      "s%^RESET%^%^CYAN%^h%^BOLD%^i%^RESET%^%^CYAN%^m%^BOLD%^m"+
      "%^RESET%^%^CYAN%^e%^BOLD%^r%^RESET%^%^CYAN%^s %^BOLD%^with "+
      "shifting images for a moment before growing still.%^RESET%^");
   wis_bonus = calculate_bonus(caster->query_stats(get_casting_stat()));
   power = CLEVEL + wis_bonus + random(6);

   caster->set_property("spelled",({TO}));
   detector = SCRY_D->add_detect_scrying(caster);
   if(!objectp(detector)){
      tell_object(caster,"%^BOLD%^RED%^Something is wrong that "+
         "a wiz might want to look at!");
      dest_effect();
      return;
   }
   detector->set_detect_power(power);
   blocker = SCRY_D->add_block_scrying(caster);
   if(!objectp(blocker)) {
      tell_object(caster,"%^BOLD%^RED%^Something is wrong that "+
         "a wiz might want to look at!");
      dest_effect();
      return;
   }
   wis_bonus = calculate_bonus(caster->query_stats(get_casting_stat()));
   power = CLEVEL + wis_bonus + random(6);
   blocker->set_block_power(power);
   spell_successful();
   addSpellToCaster();
   spell_duration = 6 * (int)CLEVEL * ROUND_LENGTH;
   set_end_time();
   call_out("dest_effect", spell_duration);
   return;
}

void dest_effect(){

   if(objectp(caster))
   {
       tell_object(caster,"%^CYAN%^%^BOLD%^The illusion protected you from scrying fades.%^RESET%^");
       caster->remove_property_value("spelled", ({TO}) );
   }
   if(objectp(detector)) detector->self_destruct();
   if(objectp(blocker)) blocker->self_destruct();

   ::dest_effect();
   if(objectp(TO)) TO->remove();
}
