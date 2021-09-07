//Essentially god's favor for psions, rather than allowing them to store any spell
//~Circe~ 3/16/16

#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;
object cont,obj;

#define ENCLAVES ({"shadow","Shadow","tabor","Tabor","seneca","Seneca"})

void create() {
    ::create();
    set_spell_name("exigency");
    set_spell_level(([ "psion" : 6 ]));
    set_spell_sphere("psychoportation");
    set_syntax("cast CLASS exigency on ENCLAVE");
    set_description("Using this power, the psion can prepare a portion "
       "of her mind to execute a quick exit at a later time. The power "
       "can be manifested only when the psion is at peace, and she must "
       "specify an enclave when manifesting. Available enclaves are: Tabor, "
       "Shadow, and Seneca. After manifesting the power, the psion can call "
       "upon its energy at any time by typing <now>.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_peace_needed(1);
    set_casting_time(2);
}

string query_cast_string() {
  return "%^BOLD%^"+caster->QCN+" closes "+caster->QP+" eyes and "+
     "begins to focus quietly.";
}

/*
int preSpell() {
  if (!present("gem of "+capitalize(caster->query_name()),caster)) {
    tell_object(caster,"You need to have a crystal attuned to you to cast upon.");
    return 0;
  }
  return 1;
}
*/

int preSpell() {
   if((obj=present("remotexoli",CASTER))&&obj!=TO){
      tell_object(CASTER,"You have already prepared your mind for escape!");
      return 0;
   }
   if(!ARG){
      tell_object(caster,"You must choose an enclave when manifesting this "
         "power! Valid choices are: Tabor, Shadow, and Seneca.");
      return 0;
   }
   if(member_array(ARG,ENCLAVES) == -1){
      tell_object(caster,"That is not a valid enclave! Please choose Tabor, Shadow, or Seneca.");
      return 0;
   }

   return 1;
}

void spell_effect(int prof){
   if(!ARG){
      tell_object(caster,"You must choose an enclave when manifesting this "
         "power! Valid choices are: Tabor, Shadow, and Seneca.");
      dest_effect();
      return;
   }
   if(member_array(ARG,ENCLAVES) == -1){
      tell_object(caster,"That is not a valid enclave! Please choose Tabor, Shadow, or Seneca.");
      dest_effect();
      return;
   }
   cont= new("/d/magic/obj/exigency");

   cont->set_args(ARG);
   cont->move(caster);
   tell_room(place,"%^BOLD%^%^RED%^A crystal held by "+caster->QCN+" "+
      "glows and pulses before growing still once more.",caster);
   tell_object(caster,"%^BOLD%^%^RED%^The crystal attuned to you glows "+
      "and pulses before growing still once more.");
   tell_object(caster,"Type <now> to activate");
   set_heart_beat(15);
   addSpellToCaster();
   spell_successful();
   caster->set_property("spelled",({TO}));
}

void dest_effect(){
  if (objectp(cont)) {
    tell_room(environment(caster),"%^BOLD%^%^CYAN%^There is the "+
       "crackling sound of static before all is quiet.");
    cont->remove(0);
  }
   if (!objectp(caster)) {
       if(objectp(TO)) TO->remove();
       return;
    }
  caster->remove_property_value("spelled", ({TO}) );
  removeSpellFromCaster();
  ::dest_effect();
  if(objectp(TO)) TO->remove();

}

void heart_beat() {
  if (!objectp(cont))
    TO->dest_effect();
}
