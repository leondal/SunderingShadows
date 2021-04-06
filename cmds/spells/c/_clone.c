//Tlaloc wrote this functional reskin of rebirth

#include <std.h>
#include <clock.h>

#define DELAY 3600

inherit SPELL;

void create(){
    ::create();
    set_spell_name("clone");
    set_spell_level(([ "mage" : 8 ]));
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS clone");
    set_description("This spell makes an inert duplicate of the caster from flesh. If the caster is slain, their soul immediately transfers " +
"to the clone.  In all respects, the clone is identical to the original, possessing all of the personality traits, memories and " +
"physical appearance. The exhaustive nature of this spell ensures that it can only be used sparingly. ");
    set_verbal_comp();
    set_property("magic",1);
    set_peace_needed(1);
	set_helpful_spell(1);
}

int preSpell(){
   if(caster->query_property("rebirth")){
      tell_object(caster,"%^BOLD%^You are already surrounded by a "+
         "rebirth or clone spell.%^RESET%^");
      return 0;
   }
   if((int)caster->query_property("rebirth time")+DELAY > time()){
      tell_object(caster,"You cannot cast this sort of spell yet.");
      return 0;
   }
   return 1;
}

string query_cast_string(){
   tell_object(caster,"%^BOLD%^Holding a pound of flesh in "+
      "your left hand, you draw a complicated symbol of protection "+
      "in the air with your right forefinger.%^RESET%^");
   tell_room(place,"%^BOLD%^"+caster->QCN+" holds a pound of flesh "+
      "aloft in "+caster->QP+" left hand as "+caster->QS+" draws "+
      "a complicated symbol in the air with "+caster->QP+" "+
      "right forefinger.%^RESET%^",caster);
   return "display";
}

void spell_effect(int prof){

   tell_room(place,"%^YELLOW%^"+caster->QCN+" shimmers for a moment "+
      "as their soul is bound to the flesh!%^RESET%^",caster);
   tell_object(caster,"%^YELLOW%^As you complete your spell, you "+
      "shimmer for a moment as your soul is bound to the "+
      "flesh!%^RESET%^");
   caster->set_property("spelled", ({TO}));
   caster->set_property("rebirth",TO);
   addSpellToCaster();
   spell_successful();
}

void dest_effect(){

    if(objectp(caster)) caster->remove_property("rebirth");
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
