//hp adjustment updated to bring it in line with similar spells ~Circe~ 11/30/19
//~Circe~ 7/20/05
#include <spell.h>
inherit SPELL;

int newhp;

void create(){
   ::create();
   set_spell_name("vigor");
   set_spell_level(([ "psion" : 1, "psywarrior" : 1 ]));
   set_spell_sphere("psychometabolism");
   set_syntax("cast CLASS vigor");
   set_damage_desc("clevel * 2 bonus hit points");
   set_description("This power allows the psion to call upon psychic energies to strengthen their body, granting them added health.  As with other psionic powers, this one will grow in strength as the psion does.");
   set_verbal_comp();
   set_somatic_comp();
   set_helpful_spell(1);
}

string query_cast_string(){
    return "%^RESET%^%^BLUE%^"+caster->QCN+" clutches a gem in each fist and calls forth a mighty power from within!%^RESET%^";
}

int preSpell(){
   if(caster->query_property("spell_bonus_hp")){
      tell_object(caster,"The spell is repelled by similar magic.");
      TO->remove();
      return 0;
   }
   return 1;
}

void spell_effect(int prof){
   int diff;
   if(!objectp(caster)){
      TO->remove();
      return;
   }
   tell_object(caster,"%^BOLD%^%^BLUE%^The bloodstone and carnelian melt away in your fists and you summon an inner reserve of power!%^RESET%^");
   tell_room(environment(caster),"%^BOLD%^%^BLUE%^"+caster->QCN+" wavers before you as the gems melt away in "+caster->QP+" hands and "+caster->QS+" is buffered by an inner strength!%^RESET%^",({caster}));
   newhp = clevel*2;
   caster->add_max_hp_bonus(newhp);
   caster->set_property("spell_bonus_hp",1);
   caster->set_property("spelled",({TO}));    
   addSpellToCaster();
   spell_successful();    
}

void dest_effect(){
   if(objectp(caster)){
      tell_object(caster,"%^RESET%^%^CYAN%^You feel somewhat weakened as the energy granted by vigor fades away.%^RESET%^");
      caster->add_max_hp_bonus(-newhp);
      caster->remove_property("spell_bonus_hp");
   }
   ::dest_effect();
   if(objectp(TO)) TO->remove();
   return;
}
