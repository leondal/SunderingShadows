#include <spell.h>
#include <magic.h>
inherit SPELL;

int mydiff;

void create() {
    ::create();
    set_author("nienne");
    set_spell_name("beguiling influence");
    set_spell_level(([ "warlock" : 1 ]));
    set_spell_sphere("alteration");
    set_bonus_type("enhancement");
    set_syntax("cast CLASS beguiling influence");
    set_description("This invocation allows the warlock to channel traces of their power into their own "
"body, granting a +4 enhancement bonus to Charisma.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

int preSpell(){
    /*
    if(caster->query_property("augmentation")){
        tell_object(caster, "You are already under the influence of such spellcraft.");
        return 0;
    }
    */
    return 1;
}

string query_cast_string() {
    tell_object(caster,"%^ORANGE%^Taking a breath, you allow traces of your own magical energies to flow back into your body.%^RESET%^");
    tell_room(place,"%^ORANGE%^"+caster->QCN+" takes a breath and concentrates.%^RESET%^",caster);
    return "display";
}

void spell_effect(int prof) {
    if (!objectp(caster)) { dest_effect(); return; }
    tell_object(caster,"%^ORANGE%^The r%^YELLOW%^i%^RESET%^%^ORANGE%^p%^YELLOW%^pl%^RESET%^%^ORANGE%^e of power that runs through you fills you with co%^YELLOW%^n%^RESET%^%^ORANGE%^fi%^YELLOW%^d%^BOLD%^%^WHITE%^e%^RESET%^%^ORANGE%^nce!%^RESET%^");
    tell_room(place,"%^ORANGE%^A g%^YELLOW%^l%^BOLD%^%^WHITE%^e%^RESET%^%^ORANGE%^am in "+caster->QCN+"'s eye gives you a moment's pause.%^RESET%^",caster);
    mydiff = 4;
    mydiff = min(({ mydiff, (30 - caster->query_stats("charisma")) }));
    //if(caster->query_stats("charisma") > 28) mydiff = 1;
    //if(caster->query_stats("charisma") > 29) mydiff = 0;
    if(mydiff) {
      caster->add_stat_bonus("charisma",mydiff);
      //caster->set_property("augmentation",1);
    }
    spell_successful();
    addSpellToCaster();
}

void dest_effect(){
    if(objectp(caster) && mydiff) {
      tell_object(caster,"%^ORANGE%^Your confidence wanes even as the invocation does.%^RESET%^");
      caster->add_stat_bonus("charisma",(-1)*mydiff);
      //caster->set_property("augmentation",-1);
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
