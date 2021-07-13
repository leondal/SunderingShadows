//Body Purification for psywarriors
//removes status effects but does not heal hit points
//~Circe~ 9/29/15

#include <priest.h>
inherit SPELL;

void create() {
    ::create();
    set_spell_name("body purification");
    set_spell_level(([ "psywarrior" : 4, "psion" : 3 ]));
    set_spell_sphere("psychometabolism");
    set_syntax("cast CLASS body purification");
    set_description("This power will allow the psionic character to remove "
       "certain ailments from her body. While it does not restore lost hit "
       "points, the power will cure blindness, remove poison and intoxication, "
       "and add some stamina.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

void spell_effect(int prof) {
   int tmp;
   
   spell_successful();
   if(interactive(caster)) {
      tell_object(caster,"%^RESET%^%^CYAN%^You touch your fingers to your "
         "temples and feel toxins evaporate from your body.%^RESET%^");
   }
   tell_room(place,"%^RESET%^%^CYAN%^"+caster->QCN+" touches "+caster->QP+" "
      "fingertips to "+caster->QP+" temples and suddenly looks refreshed.%^RESET%^",caster);
   caster->set_blind(0);
   caster->set_temporary_blinded(0);
   POISON_D->clear_poisons_by_dc(caster, 1000, 0);
   caster->add_intox(-1*(int)caster->query_intox());
   if(caster->query_condition() < caster->query_max_stamina()){
      tmp = 2 * ((int)caster->query_max_stamina() - (int)caster->query_condition());
      if(tmp > 25) { tmp = 25; }
      caster->use_stamina(-1*tmp);
   }
   dest_effect();
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
