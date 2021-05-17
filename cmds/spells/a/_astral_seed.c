//Tlaloc wrote this functional reskin of rebirth

#include <std.h>
#include <clock.h>

#define DELAY 3600

inherit SPELL;

void create(){
    ::create();
    set_spell_name("astral seed");
    set_spell_level(([ "psion" : 8 ]));
    set_discipline("shaper");
    set_spell_sphere("metacreativity");
    set_syntax("cast CLASS astral seed");
    set_description("This spell creates a tiny portal into the Astral plane, where the psion's soul is safely sequestered away. " +
"Upon death, the soul will seek out the body, reviving it and returning it to consciousness, giving them a second chance at life. " +
"The exhaustive nature of this power ensures that it can only be used sparingly. ");
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

string query_cast_string()
{
   tell_object(caster,"%^BOLD%^You move your hands in a rythmic pattern as you create "+
      "a tiny portal to the Astral plane.%^RESET%^");
   tell_room(place,"%^BOLD%^"+caster->QCN+" moves " + caster->query_possessive() + " hands "+
      "in a rythmic fashion and creates a tiny portal in the air.", ({ caster }));
   return "display";
}

void spell_effect(int prof){

   tell_room(place,"%^YELLOW%^"+caster->QCN+" shimmers for a moment "+
      "as their soul is shunted into the Astral Plane!%^RESET%^",caster);
   tell_object(caster,"%^YELLOW%^As you manifest your power, you "+
      "shimmer for a moment as your soul is shunted into the Astral "+
      "Plane!%^RESET%^");
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
