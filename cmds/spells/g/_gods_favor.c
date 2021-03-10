//changed criteria argument to check for issingleclass so dual classers could use it -tsera
#include <std.h>
#include <priest.h>

inherit SPELL;

object favor, obj;

void create() {
    ::create();
    set_spell_name("gods favor");
    set_spell_level(([ "cleric" : 8 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS gods favor");
    set_description("Gods favor allows those that are in high favor of their diety to call upon the protection of their "
"god/goddess in times of trouble.  Once this spell has been cast, it can be triggered with the command <now> to drag the "
"caster in safety back to their home temple.");
    set_verbal_comp();
    set_somatic_comp();
	set_helpful_spell(1);
}

string query_cast_string() 
{
    tell_object(caster,"You call forth and ask for the favor of "+capitalize(CASTER->query_diety())+".");
    return "display";
}

int preSpell() {
   if((obj=present("godsfavor",CASTER))&&obj!=TO){
   tell_object(CASTER,"You have already called upon the aid of "+capitalize(CASTER->query_diety())+".");
   return 0;
   }
    /*if ((sizeof(CASTER->query_classes()) > 1) && !avatarp(CASTER)) {
  tell_object(CASTER,"You have not committed yourself solely to "+capitalize(CASTER->query_diety())+" and therefor go unnoticed.");
   return 0;
   } */
  return 1;
}

void spell_effect(int prof) {
   tell_object(CASTER,"You feel the presence of "+capitalize(CASTER->query_diety())+" descend upon you and know that your prayers will not go unanswered.");
  favor=new("/cmds/priest/obj/godsfavor");
  favor->set_property("creating_spell",TO);
  favor->move(caster);
  tell_object(caster,"Type, <now> to call upon the aid of "+capitalize(CASTER->query_diety())+".");
  addSpellToCaster();
  spell_successful();
  CASTER->set_property("spelled",({TO}));
  set_heart_beat(15);
}

void dest_effect(){
  if (objectp(favor)) {
    tell_object(CASTER,"You feel the presence of "+capitalize(CASTER->query_diety())+" leave you as you lose concentration of the spell.");
    favor->remove();
  }

  if(objectp(caster)) 
  {
	caster->remove_property_value("spelled",({TO}));
      removeSpellFromCaster();
  }
  ::dest_effect();
  if(objectp(TO)) TO->remove();
}

void heart_beat() 
{
    if(objectp(favor)) { return; }
    TO->dest_effect();
}