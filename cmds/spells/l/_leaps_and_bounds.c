#include <spell.h>
inherit SPELL;

int active;

void create() {
    ::create();
    set_author("nienne");
    set_spell_name("leaps and bounds");
    set_spell_level(([ "warlock" : 1 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS leaps and bounds");
    set_description("This invocation grants the caster a startling degree of agility and stamina. It grants a bonus to "
"both the athletics and endurance skills for its duration.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

int preSpell(){
   if((int)caster->query_property("leaps and bounds")){
      tell_object(caster,"You are already under the influence of such an invocation.");
      return 0;
   }
   return 1;
}

string query_cast_string() {
    tell_object(caster,"%^BOLD%^%^WHITE%^You flex your fingers and make a brief motion to invoke minor spellcraft.%^RESET%^");
    tell_room(place,"%^BOLD%^%^WHITE%^"+caster->QCN+" flexes "+caster->QP+" fingers and makes a quick motion.%^RESET%^",caster);
    return "display";
}

void spell_effect(int prof) {
    if (!objectp(caster)) {
      dest_effect();
      return;
    }
    tell_object(caster, "%^BOLD%^%^WHITE%^A rush of supernatural ag%^YELLOW%^i%^BOLD%^%^WHITE%^li%^BOLD%^%^CYAN%^t%^BOLD%^%^WHITE%^y fills you, sharpening your movements!%^RESET%^");
    tell_room(environment(caster),"%^BOLD%^%^WHITE%^"+caster->QCN+"'s movements become more prec%^YELLOW%^i%^BOLD%^%^WHITE%^se and gr%^BOLD%^%^CYAN%^a%^BOLD%^%^WHITE%^ceful.%^RESET%^",caster);
    caster->add_skill_bonus("athletics",4);
    caster->add_skill_bonus("endurance",4);
    caster->set_property("leaps and bounds",1);
    active = 1;
    spell_successful();
    addSpellToCaster();
}

void dest_effect(){
    int i;
    if(objectp(caster) && active) {
      tell_object(caster,"%^BOLD%^%^CYAN%^The agility you'd possessed for a time seeps away, leaving you feeling sluggish in its wake.%^RESET%^");
      tell_room(environment(caster),"%^BOLD%^%^CYAN%^"+caster->QCN+"'s supernatural agility seems to fade.%^RESET%^",caster);
      caster->add_skill_bonus("athletics",-4);
      caster->add_skill_bonus("endurance",-4);
      caster->set_property("leaps and bounds",-1);
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
