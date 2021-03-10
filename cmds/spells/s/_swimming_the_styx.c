#include <std.h>
inherit SPELL;

object breathob;
int active;

void create(){
    ::create();
    set_author("nienne");
    set_spell_name("swimming the styx");
    set_spell_level(([ "warlock" : 1 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS swimming the styx");
    set_description("This invocation channels the famed river that traverses the astral and lower planes. Doing "
"so grants the caster minor aquatic traits, with their hands and feet becoming slightly webbed to aid in swimming. "
"The warlock gains the ability to breathe water as well as air for the duration of the spell.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

int preSpell(){
    if(present("underwtr_breath_ob", caster)){
      tell_object(caster,"You can already breathe water.");
      return 0;
    }
    return 1;
}

string query_cast_string() {
    tell_object(caster,"%^CYAN%^You slow your breathing and call an invocation into being.%^RESET%^");
    tell_room(place,"%^CYAN%^"+caster->QCN+" slows "+caster->QP+" breathing and mutters a few words.%^RESET%^",caster);
    return "display";
}

void spell_effect(int prof) {
    spell_successful();
    if(environment(caster)->query_property("underwater")) tell_object(caster, "%^BOLD%^%^CYAN%^The weight of the water is suddenly lighter, as webbing appears between your fingers.");
    else tell_object(caster, "%^BOLD%^%^CYAN%^The air you breathe seems to grow thicker and heavier, as webbing appears between your fingers.");
    tell_room(place, "%^BOLD%^%^CYAN%^"+caster->QCN+" takes an unusually deep breath as webbing appears between "+caster->QP+" fingers.", caster);

    breathob = new("/d/magic/obj/breathob");
    breathob->set_maxtime(500+(5*clevel));
    breathob->set_property("spell", TO);
    breathob->set_property("spelled", ({TO}));
    active = 1;
    addSpellToCaster();
    breathob->move(caster);
}

void dest_effect(){
    if(objectp(caster) && active) {
      if(environment(caster)->query_property("underwater")) tell_object(caster,"%^CYAN%^The weight of the water is suddenly oppressive and you gasp for air, as the webbing disappears from between your fingers!%^RESET%^");
      else tell_object(caster,"%^CYAN%^The next breath of air is suddenly light and refreshing, as the webbing disappears from between your fingers!%^RESET%^");
    }
    if(objectp(breathob)) breathob->remove();
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
