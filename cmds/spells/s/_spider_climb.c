#include <priest.h>
inherit SPELL;

void create() {
    ::create();
    set_spell_name("spider climb");
    set_spell_level(([ "mage" : 2,"druid" : 2, "assassin" : 2, "magus" : 2 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS spider climb");
    set_description("A caster willing to swallow both a drop of bitumen and a live spider, can use this to draw upon the "
"nature of the arachnid itself, becoming able to climb even the most sheer of surfaces.");
    set_verbal_comp();
    set_somatic_comp();
    set_components(([
      "mage" : ([ "spider" : 1, "bitumen" : 1, ]),
    ]));
	set_helpful_spell(1);
}

int preSpell(){
   if((int)CASTER->query_property("spider climb")){
      tell_object(CASTER,"You are already under the influence of such a spell.");
      return 0;
   }
   return 1;
}

string query_cast_string() {
    tell_object(caster,"%^CYAN%^You take a deep breath, and then swallow a drop of bitumen and a live spider...%^RESET%^");
    tell_room(place,"%^CYAN%^"+caster->QCN+" seems to brace "+caster->QO+"self, before swallowing a drop of bitumen and a live spider...%^RESET%^",caster);
    return "display";
}

void spell_effect(int prof) {
    int i;
    if (!objectp(caster)) {
      dest_effect();
      return;
    }
    tell_object(caster, "%^BOLD%^%^CYAN%^As you manage to swallow the components, your fingertips suddenly feel sticky!%^RESET%^");
    tell_room(place,"%^BOLD%^%^CYAN%^"+caster->QCN+" manages to swallow the components, flexing "+caster->QP+" fingertips.%^RESET%^",caster);
    caster->set_property("spider climb",1);
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH;
    set_end_time();
    call_out("dest_effect",spell_duration);
    spell_successful();
    addSpellToCaster();
}

void dest_effect(){
    int i;
    if(objectp(CASTER)) {
      tell_object(caster,"%^CYAN%^Your fingertips lose their stickiness.%^RESET%^");
      caster->set_property("spider climb",-1);
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
