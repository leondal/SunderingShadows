#include <std.h>
#include <magic.h>
inherit SPELL;

#define DELAY 300

void create(){
    ::create();
    set_author("nienne");
    set_spell_name("witchwood step");
    set_spell_level(([ "warlock" : 2 ]));
    set_spell_sphere("abjuration");
    set_syntax("cast CLASS witchwood step");
    set_description("This invocation attunes the warlock to an element of flowing energy, commonly that of air, "
"water, or the chaotic fluctuations of the feywild. Such energies will lie dormant in the caster's veins, triggering "
"at the next time the caster is stunned or tripped to grant them freedom from the effect. The power of this invocation "
"is such that the caster will need to wait a brief period once activated before it can be cast again. It can only be "
"cast while at peace.");
    set_verbal_comp();
    set_somatic_comp();
    set_peace_needed(1); 
    set_helpful_spell(1);
}

int preSpell(){
   if(caster->query_property("freedom")){
      tell_object(caster,"%^GREEN%^You are already protected by a freedom spell.%^RESET%^");
      return 0;
   }
   if((int)caster->query_property("freedom time")+DELAY > time()){
      tell_object(caster,"You cannot cast freedom again so soon.");
      return 0;
   }
   return 1;
}

string query_cast_string(){
   tell_object(caster,"%^BOLD%^%^GREEN%^You mutter an incantation and lift a foot.%^RESET%^");
   tell_room(place,"%^BOLD%^%^GREEN%^"+caster->QCN+" mutters an incantation as "+caster->QP+" foot rises.%^RESET%^",caster);
   return "display";
}

void spell_effect(int prof){
   object obj;

   tell_object(caster,"%^GREEN%^As your foot touches the ground again, a pulse of %^CYAN%^air %^GREEN%^ripples outward from "
        "the point of impact. A sudden %^RESET%^lightness %^GREEN%^of movement infuses your limbs!%^RESET%^\nUse <freeme> to activate.");
   tell_room(place,"%^GREEN%^As "+caster->QCN+"'s foot touches the ground again, a pulse of air ripples outward from the point of impact.%^RESET%^",caster);
   obj = new("/d/magic/obj/freedom");
   obj->set_mycaster(caster);
   obj->set_spellob(TO);
   obj->set_mylevel(clevel/10);
   obj->move(caster);
   addSpellToCaster();
   caster->set_property("spelled",({TO}));
   caster->set_property("freedom",1);
   spell_successful();
}

void dest_effect(){
   if(objectp(caster)){
      tell_object(caster,"%^GREEN%^Your limbs feel suddenly cumbersome again.%^RESET%^");
      caster->remove_property("freedom",1);
   }
   ::dest_effect();
   if(objectp(TO)) TO->remove();

}
