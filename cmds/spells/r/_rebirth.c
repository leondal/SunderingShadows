//Rebirth - new spell for the Renewal domain
//by ~Circe~ 5/15/08 - will give the caster an
//option to revive himself after death

#include <std.h>
#include <clock.h>

#define DELAY 3600

inherit SPELL;

void create(){
    ::create();
    set_spell_name("rebirth");
    set_spell_level(([ "cleric" : 7 ]));
    set_spell_sphere("healing");
    set_syntax("cast CLASS rebirth");
    set_description("This spell provides the caster with a certain amount of protection, allowing him to ressurrect "
"himself should he die.  The priest will be given a choice at the moment of death and may accept the rebirth offered from "
"his deity, or may journey to the realm of Lysara instead.  The priest does in fact die and will still suffer some "
"experience loss (though less than if he had died without such protection from his deity), but he will be reborn in the "
"place he died fully healed and wearing any gear he was wearing at the time of death that is still present.\n\n%^BOLD%^"
"%^RED%^Special Note%^RESET%^:  This spell takes place right at the moment of death, before the caster has entered "
"Lysara's plane.  As such, should the caster accept the rebirth, he will remember the moments before his death, much as "
"if he hadn't died at all.  If he refuses the rebirth, the death will continue as normal.");
    set_verbal_comp();
    set_property("magic",1);
    set_peace_needed(1);
	set_helpful_spell(1);
}

int preSpell(){
   if(caster->query_property("rebirth")){
      tell_object(caster,"%^BOLD%^You are already surrounded by a "+
         "rebirth spell.%^RESET%^");
      return 0;
   }
   if((int)caster->query_property("rebirth time")+DELAY > time()){
      tell_object(caster,"You cannot cast rebirth again so soon.");
      return 0;
   }
   return 1;
}

string query_cast_string(){
   tell_object(caster,"%^BOLD%^Holding your holy symbol aloft in "+
      "your left hand, you draw a complicated symbol of protection "+
      "in the air with your right forefinger.%^RESET%^");
   tell_room(place,"%^BOLD%^"+caster->QCN+" holds a holy symbol "+
      "aloft in "+caster->QP+" left hand as "+caster->QS+" draws "+
      "a complicated symbol in the air with "+caster->QP+" "+
      "right forefinger.%^RESET%^",caster);
   return "display";
}

void spell_effect(int prof){

   tell_room(place,"%^YELLOW%^"+caster->QCN+" fades from sight "+
      "briefly before solidifying once more!%^RESET%^",caster);
   tell_object(caster,"%^YELLOW%^As you complete your spell, you "+
      "feel insubstantial for a moment before growing solid "+
      "once more!%^RESET%^");
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
