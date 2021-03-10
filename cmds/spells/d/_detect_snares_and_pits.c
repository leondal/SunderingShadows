// Detect Snares and Pits
// Coded by ~Circe~ 3/20/13 for Druids
// This spell gives a bonus that is checked for in /cmds/mortal/_trap.c
// on the detect functions only. The idea is to help the target find
// traps but not allow them to disarm or set without points in Dungeoneering.

#include <std.h>
#include <magic.h>

inherit SPELL;

int bonus;
int query_bonus();

void create() {
    ::create();
    set_author("circe");
    set_spell_name("detect snares and pits");
    set_spell_level(([ "druid" : 1, "ranger" : 1, "inquisitor" : 1, "cleric" : 1]));
    set_spell_sphere("alteration");
    set_syntax ("cast CLASS detect snares and pits");
    set_description("Upon casting this spell, the caster's chance "
       "to detect traps is improved.  This spell does not allow "
       "the caster to disarm, recover, set, or reveal traps or "
       "improve the caster's chances to perform these actions.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

int preSpell(){
    if(caster->query_property("detecting_snares")){
       tell_object(caster,"%^BOLD%^%^RED%^Your ability to detect "
          "snares is already improved!%^RESET%^");
       return 0;
    }
    return 1;
}

void spell_effect(int prof){
   int duration;
   duration = ROUND_LENGTH * (clevel + 5);
   tell_room(place,"%^BOLD%^%^BLACK%^"+caster->QCN+"'s eyes shimmer with "
      "a faint %^GREEN%^s%^RESET%^%^GREEN%^h%^BOLD%^e%^RESET%^%^GREEN%^e%^BOLD%^n "
      "%^BLACK%^before it fades away.%^RESET%^",caster);
   tell_object(caster,"%^BOLD%^%^BLACK%^Natural %^GREEN%^e%^RESET%^%^GREEN%^n"
      "%^BOLD%^e%^RESET%^%^GREEN%^r%^BOLD%^g%^RESET%^%^GREEN%^y %^BOLD%^"
      "%^BLACK%^surges through you, opening your eyes to hidden dangers.%^RESET%^");
   caster->set_property("detecting_snares",TO);
   addSpellToCaster();
   caster->set_property("spelled",({TO}));
   spell_duration = duration;
   set_end_time();
   call_out("dest_effect",spell_duration);
   spell_successful();
}

int query_bonus(){
   bonus = roll_dice(1,(clevel/4))+5;
   return bonus;
}

void dest_effect(){
   if(objectp(caster)){
      tell_object(caster,"%^ORANGE%^You can feel the blessing "
         "you have been granted fade away.");
      caster->remove_property("detecting_snares");
      if(caster->query("is_auto_detecting_traps")){
         if((int)caster->query_skill("dungeoneering") < 15){
            caster->delete("is_auto_detecting_traps");
		tell_object(caster,"%^BOLD%^%^WHITE%^As the divine "
               "inspiration fades from your mind, you stop "
               "attempting to auto detect traps.%^RESET%^");
         }
      }
   }
    ::dest_effect();
    if(objectp(TO)) TO->remove();

}
