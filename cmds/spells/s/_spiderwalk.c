#include <priest.h>
inherit SPELL;

int active;

void create() {
    ::create();
    set_author("nienne");
    set_spell_name("spiderwalk");
    set_spell_level(([ "warlock" : 1 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS spiderwalk");
    set_description("A warlock uses this basic invocation to capture the nature of a spider, including their "
"ability to climb sheer surfaces, and their immunity to webs.");
    set_verbal_comp();
    set_somatic_comp();
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
    tell_object(caster,"%^BOLD%^%^BLACK%^You rub your thumb across your fingertips.%^RESET%^");
    tell_room(place,"%^BOLD%^%^BLACK%^"+caster->QCN+" rubs "+caster->QP+" thumb across "+caster->QP+" fingertips.%^RESET%^",caster);
    return "display";
}

void spell_effect(int prof) {
    int i;
    if (!objectp(caster)) {
      dest_effect();
      return;
    }
    tell_object(caster, "%^BOLD%^%^BLACK%^Ti%^RESET%^n%^BOLD%^%^BLACK%^y b%^RESET%^ar%^BOLD%^%^BLACK%^bed ha%^RESET%^i%^BOLD%^%^BLACK%^rs sprout from your skin, and your body feels strangely light!%^RESET%^");
    caster->set_property("spider climb",1);
    caster->set_property("no web",1);
    active = 1;
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH;
    set_end_time();
    call_out("dest_effect",spell_duration);
    spell_successful();
    addSpellToCaster();
}

void dest_effect(){
    int i;
    if(objectp(CASTER) && active) {
      tell_object(caster,"%^CYAN%^Your fingertips lose their stickiness.%^RESET%^");
      caster->set_property("spider climb",-1);
      caster->set_property("no web",-1);
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
