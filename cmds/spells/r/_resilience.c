//Resilience by ~Circe~ for the new strength domain 5/3/08
//baesd on Stone Body by Ares
#include <std.h>
#include <priest.h>
#include <daemons.h>
inherit SPELL;

int bonus;

void create(){
    ::create();
    set_spell_name("resilience");
    set_spell_level(([ "classless" : 5 ]));
    set_spell_sphere("combat");
    set_spell_domain("strength");
    set_syntax("cast CLASS resilience");
    set_description("This spell infuses the caster with the resilience of his deity, granting him some protection in "
"battle for the duration of the spell.");
    set_verbal_comp();
	set_helpful_spell(1);
}

string query_cast_string(){
   tell_object(caster,"%^ORANGE%^Clenching your fists, you draw "+
      "upon "+(string)caster->query_diety()+"'s aid.%^RESET%^");
   tell_room(place,"%^ORANGE%^"+caster->QCN+" clenches "+caster->QP+" "+
      "fists and draws upon "+caster->QP+" deity's aid.%^RESET%^",caster);
   return "display";
}

int preSpell(){
    if(caster->query_stoneSkinned() || caster->query_property("iron body")){
        tell_object(caster,"You are already strengthened by a similar effect.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof){
   int duration;
   duration = (ROUND_LENGTH * 10) * clevel;
   tell_room(place,"%^RED%^"+caster->QCN+"'s begins to %^BOLD%^g"+
      "%^YELLOW%^lo%^RED%^w%^RESET%^%^RED%^ red as if heated by "+
      "a %^BOLD%^forge%^RESET%^%^RED%^ before fading back to its "+
      "normal hue!%^RESET%^",caster);
   tell_object(caster,"%^RED%^The power of "+(string)caster->query_diety()+" "+
      "infuses you, and you feel your skin %^BOLD%^b%^YELLOW%^ur"+
      "%^RED%^n %^RESET%^%^RED%^as resilience infuses you!%^RESET%^");
   caster->set_property("iron body",1);
   caster->set_property("spelled", ({TO}) );
//   bonus = clevel/10;
// since this no longer stacks with stoneskin, giving it parity with stoneskin as a same-level spell. N, 8/15.
   caster->set_property("iron body",1);
   caster->set_property("damage resistance",10);
   addSpellToCaster();
   spell_successful();
   spell_duration = duration;
   set_end_time();
   call_out("dest_effect",spell_duration);
}

void dest_effect(){
   if(objectp(caster)){
      tell_object(caster,"%^ORANGE%^Your %^RESET%^skin %^ORANGE%^"+
         "feels vulnerable as the protection granted to you "+
         "fades away.%^RESET%^");
      tell_room(environment(caster),"%^ORANGE%^"+caster->QCN+"'s "+
         "skin %^RESET%^pales %^ORANGE%^for a moment before "+
         "returning to its normal tone.%^RESET%^",caster);
      caster->remove_property("iron body");
      caster->set_property("damage resistance",-10);
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
